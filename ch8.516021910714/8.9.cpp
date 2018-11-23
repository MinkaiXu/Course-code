#include <iostream>
#include <stack>
using namespace std;

template <class T>
class BinarySearchTree
{
  private:
	struct Node
	{
		T data;
		Node *left;
		Node *right;
		Node(const T &x, Node *l = NULL, Node *r = NULL) : data(x), left(l), right(r) {}
	};
	Node *root;
	bool find(const T &x, Node *t) const
	{
		if (t == NULL)
			return false;
		if (t->data == x)
			return true;
		if (t->data < x)
			return find(x, t->right);
		if (t->data > x)
			return find(x, t->left);
	}
	void insert(const T &x, Node *&t)
	{
		if (t == NULL)
		{
			t = new Node(x);
			return;
		}
		if (t->data == x)
			return;
		else if (t->data < x)
			insert(x, t->right);
		else if (t->data > x)
			insert(x, t->left);
	}
	void remove(const T &x, Node *&t)
	{
		if (t == NULL)
			return;
		if (t->data < x)
			remove(x, t->right);
		else if (t->data > x)
			remove(x, t->left);
		else if (t->data == x)
		{
			if (t->left != NULL && t->right != NULL)
			{
				Node *tmp = t->right;
				while (tmp->left != NULL)
					tmp = tmp->left;
				t->data = tmp->data;
				remove(tmp->data, t->right);
			}
			else
			{
				Node *tmp = t;
				t = (t->left != NULL) ? t->left : t->right;
				delete tmp;
			}
		}
	}
	void clear(Node *&t)
	{
		if (t == NULL)
			return;
		clear(t->left);
		clear(t->right);
		delete t;
	}
	void dfs(Node *&t)
	{
		if (t == NULL)
			return;
		cout << t->data << " ";
		dfs(t->left);
		dfs(t->right);
	}
	struct StNode
	{
		Node *node;
		int timesPop;
		StNode(Node *n = NULL) : node(n), timesPop(0) {}
	};
	T &findBigX(int x, Node *t)
	{
		stack<StNode> s;
		//vector<T> arr;
		int cnt = 0;
		StNode cur(t);
		s.push(cur);
		while (!s.empty())
		{
			cur = s.top();
			s.pop();
			++cur.timesPop;
			if (cur.timesPop == 2)
			{
				cnt++;
				//cout<<cur.node->data<<endl;
				if (cnt == x)
					return cur.node->data;
				if (cur.node->left != NULL)
					s.push(StNode(cur.node->left));
			}
			else
			{
				s.push(cur);
				if (cur.node->right != NULL)
					s.push(StNode(cur.node->right));
			}
		}
	}

  public:
	void traverse()
	{
		dfs(root);
		cout << endl;
	}
	BinarySearchTree(Node *t = NULL)
	{
		root = t;
	}
	~BinarySearchTree()
	{
		clear(root);
	}
	bool find(const T &x) const
	{
		return find(x, root);
	}
	void insert(const T &x)
	{
		insert(x, root);
	}
	void remove(const T &x)
	{
		remove(x, root);
	}
	T &findBigX(int x)
	{
		return findBigX(x, root);
	}
};
int main()
{
	int a[] = {10, 8, 6, 21, 87, 56, 4, 0, 11, 3, 22, 7, 5, 34, 1, 2, 9};
	BinarySearchTree<int> tree;

	for (int i = 0; i < 17; i++)
		tree.insert(a[i]);
	cout << tree.findBigX(5);

	return 0;
}
