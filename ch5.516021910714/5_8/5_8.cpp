#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int data;
	Node *lson;
	Node *rbro;
	bool isRoot;
	Node() : isRoot(true) {}
};
void dfs(Node *t, int type) //��������ͺ������
{
	if (t != NULL)
	{
		if (type == 1)
			cout << t->data << " ";
		dfs(t->lson, type);

		dfs(t->rbro, type);
		if (type == 2)
			cout << t->data << " ";
	}
}
void bfs(Node *t) //��α���
{
	queue<Node *> hh;
	hh.push(t);
	while (!hh.empty())
	{
		Node *tmp = hh.front();
		cout << tmp->data << " ";
		if (tmp->lson != NULL)
			hh.push(tmp->lson);
		Node *p = tmp->rbro;
		while (p != NULL)
		{
			cout << p->data << " ";
			if (p->lson != NULL)
				hh.push(p->lson);
			p = p->rbro;
		}
		hh.pop();
	}
}
int main()
{
	//�����ʽ�ο�OJ 1214
	int n;
	cin >> n;
	Node *tree = new Node[n + 1];
	for (int i = 1, l, r; i <= n; i++)
	{
		cin >> l >> r >> tree[i].data;
		tree[i].lson = (l != 0) ? &(tree[l]) : NULL;
		tree[i].rbro = (r != 0) ? &(tree[r]) : NULL;
		tree[l].isRoot = false;
		tree[r].isRoot = false;
	}
	Node *root;
	for (int i = 1; i <= n; i++)
		if (tree[i].isRoot)
		{
			root = &tree[i];
			break;
		}
	cout << "ǰ�������";
	dfs(root, 1);
	cout << "\n���������";
	dfs(root, 2);
	cout << "\n��α�����";
	bfs(root);
	delete[] tree;
	return 0;
}
/*
��һ�к���һ��������N���������н��������
�ڶ��е���N+1�У�ÿ�а�������������
���е�i�е���������Pi��Qi��Vi��������i������ΪPi�����ֵ�ΪQi�����i�����ȨֵΪVi��
��Pi=0����������iû�����ӡ�
ͬ���ģ���Qi=0����������iû�����ֵܡ�

9
2 0 1
5 3 2
0 4 3
7 0 4
0 6 5
0 0 6
0 8 7
0 9 8
0 0 9
*/
