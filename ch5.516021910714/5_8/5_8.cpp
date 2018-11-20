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

void dfs(Node *t, int type)
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

void bfs(Node *t)
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
	cout << "The first line contains a positive integer N representing the total number of nodes in the tree." << endl
		 << "The second line to the (N+1)th line, each line contains three integers." << endl
		 << "The three integers Pi, Qi, Vi in the i-th row represent the left child of the node i as Pi," << endl
		 << "the right brother is Qi, and the weight of the node i itself is Vi." << endl
		 << "If Pi=0, it means that node i has no left child;" << endl
		 << "if Qi=0, it means that node i has no right brother." << endl
		 << endl;
	cout << "The example input is as follows" << endl
		 << '9' << endl
		 << "2 0 1" << endl
		 << "5 3 2" << endl
		 << "0 4 3" << endl
		 << "7 0 4" << endl
		 << "0 6 5" << endl
		 << "0 0 6" << endl
		 << "0 8 7" << endl
		 << "0 9 8" << endl
		 << "0 0 9" << endl;
	cout << "Please input the binary tree that you want to traverse:" << endl
		 << "(You can copy the above example to test this program.)" << endl;
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
	cout << "Preorder traversal£º";
	dfs(root, 1);
	cout << "\nPost-order traversal£º";
	dfs(root, 2);
	cout << "\nHierarchical traversal£º";
	bfs(root);
	cout << endl;
	delete[] tree;
	system("pause");
	return 0;
}
