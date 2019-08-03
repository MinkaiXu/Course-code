/*
Created By Minkai Xu
����������
�༶��F1603603
ѧ�ţ�516021910714
*/

#include <stdio.h>

// ���з�������
struct map {
	unsigned m_size;
	char *m_addr;
	struct map *prior, *next;
};

unsigned sizeAll; // ���ڴ�δ�С
char* start; // ��¼�ڴ����ʼλ��
struct map *coremap; // �����������׽ڵ�
struct map *current; // �������������ָ��

char* lmalloc(unsigned size);
int lfree(unsigned size, char* addr);
void printmap(); // ��ӡ����������

int main() {

	char cmdchar[40]; // ����Ĳ�������
	unsigned size; // �����ڴ�δ�С
	unsigned addr; // ������ַ(��Ե�ַ)

	while (1) {
		printf("Input the size of your requested memory: \n>> ");
		scanf_s("%d", &sizeAll);
		if (sizeAll <= 10240) { 
			start = (char*)malloc(sizeAll);
			printf("%s%p%s", "Start of Virtual Memory: ", start, "\n");
			break; 
		}
		else { printf("The requested size is too large!\n"); }
	}

	coremap = (struct map*)malloc(sizeof(struct map));
	coremap->next = coremap;
	coremap->prior = coremap;
	coremap->m_addr = start;
	coremap->m_size = sizeAll;
	current = coremap; // ��ѯָ���ʼ��ʱͣ����ʼλ��

	printf("------------Command List---------------\
\n  --to malloc: m [size]\
\n  --to free: f [size] [Vaddr]\
\n  --to print map: p\
\n  --to exit: q\
\n---------------------------------------\n");
	while (1) {
		printf(">> ");
		scanf_s("%s", &cmdchar, 40);
		if (strcmp(cmdchar, "m") == 0) { //lmalloc
			scanf_s("%zu", &size);
			char* result_m = lmalloc(size);
			if (result_m == NULL) { printf("No enough memory left.\n"); }
			else { printf("Allocate memory from %d(%p) to %d(%p) successfully!\n",\
				result_m - start, result_m, result_m - start + size, result_m +size); }
		}
		else if (strcmp(cmdchar, "f") == 0) { //lfree
			scanf_s("%zu", &size);
			scanf_s("%d", &addr);
			int result_f = lfree(size, start + addr);
			if (result_f) { printf("Free memory from %d(%p) to %d(%p) successfully!\n", \
				addr, start + addr, addr + size, start + addr + size); }
			else { printf("Free memory error.\n"); }
		}
		else if (strcmp(cmdchar, "p") == 0) { printmap(); } //show 
		else if (strcmp(cmdchar, "q") == 0) { //quit
			printf("Exit the program.\n");
			break;
		}
		else { printf("Invalid Command! Check your input!\n"); }
	}
	system("pause");
	free(coremap);
	return 0;
}

char* lmalloc(unsigned size) {
	struct map* tmp;
	tmp = current;
	do {
		if (size <= tmp->m_size) { break; } // �ҵ��ɷ����ڴ���
		else { tmp = tmp->next; } // ��δ�ҵ��ɷ����ڴ���
	} while (tmp != current); // �����ڴ��޿ɷ����ڴ���

	if (tmp == current && size > tmp->m_size)  // δ���ҵ��ɷ����ڴ���
		return NULL;

	else { 
		char* result_m = tmp->m_addr;
		tmp->m_size -= size;
		tmp->m_addr += size;
		current = tmp->next; // �������������ָ��ѭ������
		if (!tmp->m_size) { // ���ڴ�����ȫ������
			tmp->prior->next = tmp->next;
			tmp->next->prior = tmp->prior;
			if (tmp == coremap) { coremap = tmp->next; } 
			// �����������׽ڵ����
			if (tmp != coremap) { free(tmp); }
			// �ڴ��Ϊ0ʱ��������ͷָ�����Ƴ���ָ��
		}
		return result_m;
	}
}


int lfree(unsigned size, char* addr) {

	struct map* tmp = coremap;

	if (addr < start || addr + size > start + sizeAll) { return 0; }

	if (coremap->m_size == 0){
		// �ڴ�ȫ�����䣬�½�һ��map
		struct map* newmap;
		newmap = (struct map*)malloc(sizeof(struct map));
		newmap->m_size = size;
		newmap->m_addr = addr;
		newmap->next = newmap;
		newmap->prior = newmap;
		coremap = newmap;
		free(tmp);
		return 1;
	}

	do{
		if (tmp->m_addr > addr) { break; }
		else { tmp = tmp->next; }
	}while (tmp!= coremap);

	// Ҫ�ͷŵ��ڴ沢δ����ȫռ��
	if (tmp == coremap) { // ȷ���˳�while�������ڿ��з���ȫ�����ͷſռ��һ��
		if ((tmp->m_addr < addr && tmp->prior->m_addr + tmp->prior->m_size > addr)
			|| (tmp->m_addr > addr && tmp->m_addr < (addr + size))
			|| tmp->m_addr == addr)
		{ return 0; }
	}
	else {
		if ((addr + size) > tmp->m_addr || addr < tmp->prior->m_addr + tmp->prior->m_size) 
		{ return 0; }
	}

	tmp = tmp->prior;

	if (tmp->m_addr + tmp->m_size == addr) {
		// �ͷſռ���ǰ����п�����
		tmp->m_size += size;
		if (tmp->m_addr + tmp->m_size == tmp->next->m_addr) {
			// �����������п�����
			struct map* tmp_n = tmp->next; // tmp->next
			tmp->m_size += tmp_n->m_size;
			tmp_n->next->prior = tmp;
			tmp->next = tmp_n->next; // ɾ��tmp->next�ڵ�
			if (current == tmp_n) { current = tmp->prior; }
			// ����ָ��ָ���Ƴ��Ĳ��֣����ƶ�����ָ��
			free(tmp_n);
		}
	}
	else {
		if ( tmp->next->m_addr == (addr + size) ) {
			// �ͷſռ��������п�����
			tmp->next->m_size += size;
			tmp->next->m_addr -= size;
		}
		else {
			// ��ǰ��Ŀ��п�����������½�һ��map
			struct map* newmap;
			newmap = (struct map*)malloc(sizeof(struct map));
			newmap->m_size = size;
			newmap->m_addr = addr;
			newmap->next = tmp->next;
			newmap->prior = tmp;
			tmp->next->prior = newmap;
			tmp->next = newmap;
			if (tmp->m_addr > addr) { coremap = newmap; }
			// �½�������ͷָ��֮ǰ���ƶ�ͷָ��
		}
	}
	return 1;
}

void printmap() {
	struct map* tmp = coremap;
	printf("----------------------Free-Memory-List----------------------\n");
	printf("Index\t\tRAddress\tVAddress\tSize\n");
	int index = 0;
	do{
		if (coremap->m_size == 0) { break; }
		printf("%d\t\t%p\t%d\t\t%d\n", \
			index, tmp->m_addr, tmp->m_addr-start, tmp->m_size);
		tmp = tmp->next; 
		index++;
	} while (tmp != coremap);
	printf("---------------------------End------------------------------\n");
}

