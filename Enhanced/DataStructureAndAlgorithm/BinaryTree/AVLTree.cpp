#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class TreeNode
{
public:
	int height;
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val)
	{
		this->val = val;
		left = nullptr;
		right = nullptr;
		height = 0;
	}
};
class AVLTree
{
	TreeNode* root;
	void updateHeight(TreeNode* node)
	{
		if (node != nullptr)
			node->height = max(height(node->left), height(node->right)) + 1;
	}
	int balanceFactor(TreeNode* node)
	{
		return height(node->left) - height(node->right);
	}
	TreeNode* rightRotate(TreeNode* node)
	{
		TreeNode* child = node->left;
		TreeNode* grand_child = child->right;//node or nullptr
		child->right = node;
		node->left = grand_child;//node or //nullptr
		//update the height to avoid execute the function again
		updateHeight(node);
		updateHeight(child);
		return child;
	}
	TreeNode* leftRotate(TreeNode* node)
	{
		TreeNode* child = node->right;
		TreeNode* grand_child = child->left;//node or nullptr
		child->left = node;
		node->right = grand_child;
		updateHeight(node);
		updateHeight(child);
		return child;
	}
	TreeNode* rotate(TreeNode* node)
	{

		if (balanceFactor(node) > 1)
		{
			if (balanceFactor(node->left) >= 0)
			{
				return rightRotate(node);
			}
			else
			{
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
		}
		else if (balanceFactor(node) < -1)
		{
			if (balanceFactor(node->right) <= 0)
			{
				return leftRotate(node);
			}
			else
			{
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
		}
		//The node is balanced already
		return node;
	}
	TreeNode* insertHelper(TreeNode* node, int val)
	{
		//arrive the position, return it
		if (node == nullptr)
		{
			return new TreeNode(val);
		}
		if (val > node->val)//the position is in right subtree 
		{
			node->right = insertHelper(node->right, val);
		}
		else if (val < node->val)//left 
		{
			node->left = insertHelper(node->left, val);
		}
		//else return node;//重复节点不插入直接返回
		//update the height
		updateHeight(node);
		node = rotate(node);
		//the node is in the tree already
		return node;
	}
	TreeNode* removeHelper(TreeNode* node, int val)
	{
		if (node == nullptr)
		{
			return nullptr;//the tree is empty or node is not found
		}
		if (val < node->val)//left 
		{
			node->left = removeHelper(node->left, val);
		}
		else if (val > node->val)//right 
		{
			node->right = removeHelper(node->right, val);
		}
		else //find the position
		{
			//the node has one or zero subtree
			if (node->left == nullptr || node->right == nullptr)
			{
				TreeNode* child = node->left != nullptr ? node->left : node->right;//right node or nullptr
				if (child == nullptr) {
					delete node;
					return nullptr;
				}
				else {
					//node has child
					delete node;
					node = child;
				}
			}
			else//two sub trees  
			{
				TreeNode* child = node->right;
				while (child->left != nullptr)
				{
					child = child->left;
				}
				//remove the child
				int child_val = child->val;
				node->right = removeHelper(node->right, child_val);
				//child is the most left node of right subtree
				node->val = child_val;
			}
		}
		updateHeight(node);
		node = rotate(node);
		return node;

	}
	void dfs(TreeNode* node, string order, vector<int>& res)
	{
		if (node == nullptr)
		{
			return;
		}
		if (order == "pre")
			res.push_back(node->val);
		dfs(node->left, order, res);
		if (order == "in")
			res.push_back(node->val);
		dfs(node->right, order, res);
		if (order == "post")
			res.push_back(node->val);
	}
public:
	int height(TreeNode* node)
	{
		return node == nullptr ? -1 : node->height;
	}
	AVLTree()
	{
		root = nullptr;
	}
	//we need to rotate the node from bottom to top, so we need recursion
	void insert(int val)
	{
		root = insertHelper(root, val);
	}
	void remove(int val)
	{
		root = removeHelper(root, val);
	}
	void preOrder()
	{
		vector<int> vec;
		dfs(root, "pre", vec);
		for (int num : vec)
		{
			cout << num << " ";
		}
	}
	void inOrder()
	{
		vector<int> vec;
		dfs(root, "in", vec);
		for (int i = 0;i < vec.size();i++)
		{
			cout << vec[i] << " ";
		}
	}
	void postOrder()
	{
		vector<int> vec;
		dfs(root, "post", vec);
		for (int num : vec)
		{
			cout << num << " ";
		}
	}
	void levelOrder()
	{
		if (root == nullptr)return;
		queue<TreeNode*> queue;
		queue.push(root);
		vector<int>res;
		while (!queue.empty())
		{
			TreeNode* node = queue.front();
			res.push_back(node->val);
			queue.pop();
			if (node->left != nullptr)
				queue.push(node->left);
			if (node->right != nullptr)
				queue.push(node->right);
		}
		for (int val : res)
		{
			cout << val << " ";
		}
	}
	TreeNode* searchHelper(int val,TreeNode* node) 
	{
		if (node == nullptr)//not found
			return nullptr;
		if (val>node->val) 
		{
			return searchHelper(val,node->right);
		}
		else if(val<node->val)
		{
			return searchHelper(val,node->left);
		}
		else//find it
		{
			return node;
		}
	}
	TreeNode* search(int val)
	{
		return searchHelper(val,root);
	}
};

void test()
{
	AVLTree avlTree;
	avlTree.insert(1);
	avlTree.insert(2);
	avlTree.insert(3);
	avlTree.insert(4);
	avlTree.insert(5);
	avlTree.insert(6);
	avlTree.insert(6);
	avlTree.levelOrder();
	cout << endl;
	avlTree.remove(3);
	avlTree.levelOrder();
	TreeNode* node3=avlTree.search(3);
	if (node3 != nullptr) 
	{
		cout << "node3: " << node3->val << endl;
	}
}
int main()
{
	test();
	return 0;
}