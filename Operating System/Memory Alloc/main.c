/*
Created By Minkai Xu
姓名：徐民凯
班级：F1603603
学号：516021910714
*/

#include <stdio.h>

// 空闲分区链表
struct map {
	unsigned m_size;
	char *m_addr;
	struct map *prior, *next;
};

unsigned sizeAll; // 总内存段大小
char* start; // 记录内存段起始位置
struct map *coremap; // 空闲区链表首节点
struct map *current; // 空闲区链表查找指针

char* lmalloc(unsigned size);
int lfree(unsigned size, char* addr);
void printmap(); // 打印空闲区表函数

int main() {

	char cmdchar[40]; // 输入的操作命令
	unsigned size; // 操作内存段大小
	unsigned addr; // 操作地址(相对地址)

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
	current = coremap; // 查询指针初始化时停在起始位置

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
		if (size <= tmp->m_size) { break; } // 找到可分配内存区
		else { tmp = tmp->next; } // 尚未找到可分配内存区
	} while (tmp != current); // 遍历内存无可分配内存区

	if (tmp == current && size > tmp->m_size)  // 未能找到可分配内存区
		return NULL;

	else { 
		char* result_m = tmp->m_addr;
		tmp->m_size -= size;
		tmp->m_addr += size;
		current = tmp->next; // 空闲区链表查找指针循环后移
		if (!tmp->m_size) { // 该内存区被全部分配
			tmp->prior->next = tmp->next;
			tmp->next->prior = tmp->prior;
			if (tmp == coremap) { coremap = tmp->next; } 
			// 空闲区链表首节点后移
			if (tmp != coremap) { free(tmp); }
			// 内存块为0时，若不是头指针则移除该指针
		}
		return result_m;
	}
}


int lfree(unsigned size, char* addr) {

	struct map* tmp = coremap;

	if (addr < start || addr + size > start + sizeAll) { return 0; }

	if (coremap->m_size == 0){
		// 内存全部分配，新建一个map
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

	// 要释放的内存并未被完全占用
	if (tmp == coremap) { // 确保退出while不是由于空闲分区全部在释放空间的一侧
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
		// 释放空间与前向空闲块相连
		tmp->m_size += size;
		if (tmp->m_addr + tmp->m_size == tmp->next->m_addr) {
			// 继续与后向空闲块相连
			struct map* tmp_n = tmp->next; // tmp->next
			tmp->m_size += tmp_n->m_size;
			tmp_n->next->prior = tmp;
			tmp->next = tmp_n->next; // 删除tmp->next节点
			if (current == tmp_n) { current = tmp->prior; }
			// 查找指针指向被移除的部分，则移动查找指针
			free(tmp_n);
		}
	}
	else {
		if ( tmp->next->m_addr == (addr + size) ) {
			// 释放空间与后向空闲块相连
			tmp->next->m_size += size;
			tmp->next->m_addr -= size;
		}
		else {
			// 与前后的空闲块均不相连，新建一个map
			struct map* newmap;
			newmap = (struct map*)malloc(sizeof(struct map));
			newmap->m_size = size;
			newmap->m_addr = addr;
			newmap->next = tmp->next;
			newmap->prior = tmp;
			tmp->next->prior = newmap;
			tmp->next = newmap;
			if (tmp->m_addr > addr) { coremap = newmap; }
			// 新建分区在头指针之前，移动头指针
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

