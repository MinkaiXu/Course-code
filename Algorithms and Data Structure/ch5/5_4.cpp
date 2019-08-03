#include <iostream>
#include <queue>

using namespace std;

template <class Type>
class BinaryTree
{
  private:
	struct Node
	{
		Node *left, *right;
		Type data;
		Node() : left(NULL), right(NULL) {}
		Node(const Type &item, Node *L = NULL, Node *R = NULL) : data(item), left(L), right(R) {}
		~Node() {}
	};
	Node *root;

  public:
	BinaryTree() : root(NULL) {}
	BinaryTree(const Type &value)
	{
		root = new Node(value);
	}
	BinaryTree(const Type *p)
	{
		root = p;
	}
	~BinaryTree()
	{
		clear();
	}

	Type getRoot() const
	{
		return root->data;
	}
	Type getLeft() const
	{
		return (root->left == NULL) ? root->left->data : NULL;
	}
	Type getRight() const
	{
		return (root->right == NULL) ? root->right->data : NULL;
	}
	void makeTree(const Type &x, BinaryTree &lt, BinaryTree &rt)
	{
		root = new Node(x, lt.root, rt.root);
		lt.root = NULL;
		rt.root = NULL;
	}
	void delLeft()
	{
		BinaryTree tmp = root->left;
		root->left = NULL;
		tmp.clear();
	}
	void delRight()
	{
		BinaryTree tmp = root->right;
		root->right = NULL;
		tmp.clear();
	}
	bool isEmpty() const
	{
		return root == NULL;
	}
	void clear()
	{
		if (root != NULL)
			clear(root);
		root = NULL;
	}
	int size() const
	{
		return size(root);
	}
	int height() const
	{
		return height(root);
	}
	void preOrder() const
	{
		if (root != NULL)
		{
			cout << "\nǰ�������";
			dfs(root, 1);
		}
	}
	void midOrder() const
	{
		if (root != NULL)
		{
			cout << "\n���������";
			dfs(root, 2);
		}
	}
	void postOrder() const
	{
		if (root != NULL)
		{
			cout << "\n���������";
			dfs(root, 3);
		}
	}
	void levelTraverse() const
	{
		if (root == NULL)
			return;
		cout << "\n��α�����";
		queue<Node *> hh;
		hh.push(root);
		while (!hh.empty())
		{
			Node *tmp = hh.front();
			cout << tmp->data << " ";
			if (tmp->left != NULL)
				hh.push(tmp->left);
			if (tmp->right != NULL)
				hh.push(tmp->right);
			hh.pop();
		}
	}
	bool isComplete() const
	{
		if (root == NULL)
			false;

		queue<Node *> hh;
		hh.push(root);
		while (!hh.empty())
		{
			Node *tmp = hh.front();
			hh.pop();
			if (tmp == NULL)
				break;
			hh.push(tmp->left);
			hh.push(tmp->right);
		}
		while (!hh.empty())
		{
			Node *tmp = hh.front();
			hh.pop();
			if (tmp != NULL)
				return false;
		}
		return true;
	}
	void createTree(Type flag)
	{
		queue<Node *> q;
		Node *tmp;
		Type x, l, r;

		cout << "������ڵ㣺";
		cin >> x;
		root = new Node(x);
		q.push(root);
		while (!q.empty())
		{
			tmp = q.front();
			q.pop();
			cout << "����" << tmp->data << "����������(" << flag << "��ʾ�սڵ�)��";
			cin >> l >> r;
			if (l != flag)
				q.push(tmp->left = new Node(l));
			if (r != flag)
				q.push(tmp->right = new Node(r));
		}
	}

  private:
	int height(Node *t) const
	{
		if (t == NULL)
			return 0;
		return 1 + max(height(t->left), height(t->right));
	}
	void clear(Node *t)
	{
		if (t->left != NULL)
			clear(t->left);
		if (t->right != NULL)
			clear(t->right);
		delete t;
	}
	int size(Node *t) const
	{
		if (t == NULL)
			return 0;
		return 1 + size(t->left) + size(t->right);
	}
	void dfs(Node *t, int type) const
	{
		if (t != NULL)
		{
			if (type == 1)
				cout << t->data << " ";
			dfs(t->left, type);
			if (type == 2)
				cout << t->data << " ";
			dfs(t->right, type);
			if (type == 3)
				cout << t->data << " ";
		}
	}
};

int main()
{
	cout << "����ʾ��Ϊ:(��������)" << endl
		 << "A\nBC\nEF\nG@\n@@\n@@\n@@\n@@\n"
		 << endl
		 << "�������:" << endl;
	BinaryTree<char> tree, tree1('M'), tree2;
	tree.createTree('@');
	cout << "�߶�Ϊ��" << tree.height() << endl;
	cout << "��ģΪ��" << tree.size() << endl;
	tree.preOrder();
	tree.midOrder();
	tree.postOrder();
	tree.levelTraverse();
	cout << "\n"
		 << (tree.isComplete() ? "����ȫ������" : "������ȫ������") << endl;
	system("pause");
	return 0;
}