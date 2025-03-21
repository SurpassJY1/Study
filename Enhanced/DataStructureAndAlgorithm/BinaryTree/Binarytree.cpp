#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
class  TreeNode
{
public:
	TreeNode* left;
	TreeNode* right;
	int value;
	TreeNode(int val) :value(val), left(nullptr), right(nullptr) {}
};
vector<int> levelOrder(TreeNode* root)
{
	vector<int> res;
	//using queue to achieve level order traverse
	queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty())
	{
		TreeNode* node = queue.front();
		queue.pop();
		res.push_back(node->value);
		if (node->left != nullptr)
		{
			queue.push(node->left);
		}
		if (node->right != nullptr)
		{
			queue.push(node->right);
		}
	}
	return res;
}
void preOrder(TreeNode* root, vector<int>& res)//引用传递，值传递会随着方法栈内存中释放而释放
{
	if (root == nullptr)
	{
		return;
	}
	res.push_back(root->value);
	//interview left tree
	preOrder(root->left, res);
	preOrder(root->right, res);
}
void inOrder(TreeNode* root, vector<int>& res)
{
	if (root == nullptr)
	{
		return;
	}
	inOrder(root->left, res);
	res.push_back(root->value);
	inOrder(root->right, res);
}
void postOrder(TreeNode* root, vector<int>& res)
{
	if (root == nullptr)
	{
		return;
	}
	postOrder(root->left, res);
	postOrder(root->right, res);
	res.push_back(root->value);
}
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test()
{
	/* 初始化二叉树 */
// 初始化节点
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	// 构建节点之间的引用（指针）
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	//vector<int> res=levelOrder(n1);
	//for_each(res.begin(),res.end(),MyPrint());
	vector<int>res;
	postOrder(n1, res);
	for_each(res.begin(), res.end(), MyPrint());
}
class ArrayTree
{
	vector<int> tree;
	void dfs(int i, string order, vector<int>& vec)
	{
		if (get(i) == INT_MAX)
		{
			return;
		}
		if (order == "pre") vec.push_back(get(i));
		dfs(left(i), order, vec);
		if (order == "in")vec.push_back(get(i));
		dfs(right(i), order, vec);
		if (order == "post")vec.push_back(get(i));
	}
public:
	ArrayTree(vector<int> arr)
	{
		tree = arr;
	}
	int getSize()
	{
		return tree.size();
	}
	int get(int i)
	{
		if ( i >= tree.size() || i < 0)
		{
			return INT_MAX;
		}
		return tree.at(i);
	}
	int left(int i)
	{
		return 2 * i + 1;
	}
	int right(int i)
	{
		return 2 * i + 2;
	}
	vector<int> levelOrder()
	{
		vector<int> res;
		for (vector<int>::const_iterator it = tree.begin();it != tree.end();it++)
		{
			if (*it != INT_MAX)
			{
				res.push_back(*it);
			}
		}
		return res;
	}
	vector<int> preOrder(int i)
	{
		vector<int> res;
		dfs(i, "pre", res);
		return res;
	}
	vector<int> inOrder(int i)
	{
		vector<int> res;
		dfs(i, "in", res);
		return res;
	}vector<int> postOrder(int i)
	{
		vector<int> res;
		dfs(i, "post", res);
		return res;
	}
};
int main()
{
		// 构造测试用的数组树
		std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
		ArrayTree tree(arr);

		// 测试层序遍历
		std::vector<int> levelOrderRes = tree.levelOrder();
		std::cout << "Level Order: ";
		for (int val : levelOrderRes)
		{
			std::cout << val << " ";
		}
		std::cout << std::endl;

		// 测试前序遍历
		std::vector<int> preOrderRes = tree.preOrder(0);
		std::cout << "Pre Order: ";
		for (int val : preOrderRes)
		{
			std::cout << val << " ";
		}
		std::cout << std::endl;

		// 测试中序遍历
		std::vector<int> inOrderRes = tree.inOrder(0);
		std::cout << "In Order: ";
		for (int val : inOrderRes)
		{
			std::cout << val << " ";
		}
		std::cout << std::endl;

		// 测试后序遍历
		std::vector<int> postOrderRes = tree.postOrder(0);
		std::cout << "Post Order: ";
		for (int val : postOrderRes)
		{
			std::cout << val << " ";
		}
		std::cout << std::endl;

		return 0;
}
