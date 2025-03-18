#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class TreeNode
{
public:
	int m_Val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :m_Val(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
	TreeNode* root;
	void Dfs(TreeNode* node, string order, vector<int>& res)
	{
		if (node == nullptr)
		{
			return;
		}
		if (order == "pre")
			res.push_back(node->m_Val);
		Dfs(node->left, order, res);
		if (order == "in")
			res.push_back(node->m_Val);
		Dfs(node->right, order, res);
		if (order == "post")
			res.push_back(node->m_Val);
	}
public:
	BinarySearchTree()
	{
		root = nullptr;
	}
	void insert(int val)
	{
		//if the tree is empty
		if (root == nullptr)
		{
			root = new TreeNode(val);
			return;
		}
		//find the target position
		TreeNode* curr = root;
		TreeNode* prev = nullptr;//record the parent
		while (curr != nullptr)
		{
			//find the same element,return directly
			if (curr->m_Val == val)
			{
				return;
			}
			//the val node is in the right sub tree
			if (curr->m_Val < val)
			{
				prev = curr;//record the parent
				curr = curr->right;
			}
			//the val node is in the left sub tree
			else if (curr->m_Val > val)
			{
				prev = curr;
				curr = curr->left;
			}
		}
		//curr is nullptr,and prev is the parent
		if (prev->m_Val > val)
		{
			prev->left = new TreeNode(val);
		}
		else
		{
			prev->right = new TreeNode(val);
		}
	}
	TreeNode* search(int val)
	{
		TreeNode* cur = root;
		while (cur != nullptr)
		{
			if (cur->m_Val == val)
			{
				return cur;
			}
			if (cur->m_Val > val)
			{
				//val is in left tree
				cur = cur->left;
			}
			if (cur->m_Val < val)
			{
				//val is in the right sub tree
				cur = cur->right;
			}
		}
		//cur is nullptr
		//not found
		return cur;
	}
	void remove(int num) 
	{
		//if the tree is empty
		if (root==nullptr) 
		{
			return;
		}
		//search the removed element
		TreeNode* cur = root;
		TreeNode* prev = nullptr;
		while (cur!=nullptr)
		{
			//find the element
			if (cur->m_Val==num) 
			{
				break;//end loop
			}
			prev = cur;
			//removed one is in left
			if (num<cur->m_Val) 
			{
				cur = cur->left;
			}
			//right
			else 
			{
				cur = cur->right;
			}
		}
		//cur is nullptr or removed one
		//cur is nullptr
		if (cur==nullptr) 
		{
			return;
		}
		//cur is the removed one
		//the number of child elements is one or zero
		if (cur->left==nullptr||cur->right==nullptr) 
		{
			//move the child element to its position
			TreeNode* child = cur->left != nullptr ? cur->left : cur->right;
			//if the cur is root, move the child to it directly
			if (cur==root) 
			{
				root = child;
			}
			else//cur is not root, make parent position connect to the child 
			{
				if (prev->left==cur) 
				{
					prev->left = child;
				}
				else 
				{
					prev->right = child;
				}
			}
			delete cur;
		}
		else //two sub trees 
		{
			TreeNode* temp = cur->right;
			//get the most left element of right subtree
			while (temp->left!=nullptr) 
			{
				temp = temp->left;
			}
			//replace the temp with cur
			int val = temp->m_Val;
			remove(val);
			cur->m_Val = val;
		}
	}
	vector<int> inOrder()
	{
		vector<int> res;
		Dfs(root, "in", res);
		return res;
	}
	vector<int> preOrder()
	{
		vector<int> res;
		Dfs(root, "pre", res);
		return res;
	}
	vector<int> postOrder()
	{
		vector<int> res;
		Dfs(root, "post", res);
		return res;
	}
};
void test()
{
	BinarySearchTree bst;
	bst.insert(1);
	bst.insert(2);
	bst.insert(3);
	bst.insert(4);
	bst.insert(5);
	bst.insert(6);
	vector<int> vec = bst.inOrder();
	for (int val : vec)
	{
		cout << val << " ";
	}
	cout << endl;
	TreeNode* node = bst.search(3);
	cout << node->m_Val << endl;
	TreeNode* node2 = bst.search(9);
	if (node2 == nullptr)cout << "Not found" << endl;
	bst.remove(5);
	bst.remove(1);
	bst.remove(3);
	vector<int> vec2 = bst.inOrder();
	for (int val : vec2)
	{
		cout << val << " ";
	}
}
int main()
{
	test();
	return 0;
}