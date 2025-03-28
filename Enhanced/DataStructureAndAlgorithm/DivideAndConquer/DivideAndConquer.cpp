//
// Created by GlokieYu on 25-3-27.
//
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class TreeNode
{
  public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const TreeNode& node)
    {
      val=node.val;
      left=node.left;
      right=node.right;
    }
    TreeNode(int val)
    {
      this->val=val;
      left=nullptr;
      right=nullptr;
    }
    void dfs(string order,vector<int> &res,TreeNode* root)
    {
      if(root==nullptr)
        return;
      if(order=="pre")
        res.push_back(root->val);
      dfs(order,res,root->left);
      if(order=="in")
        res.push_back(root->val);
      dfs(order,res,root->right);
      if(order=="post")
        res.push_back(root->val);
    }
    void preOrder(vector<int> &res)
    {
      dfs("pre",res,this);
    }
    void inOrder(vector<int> &res)
    {
      dfs("in",res,this);
    }
    void postOrder(vector<int> &res)
    {
      dfs("post",res,this);
    }
};

// TreeNode* createTreeHelper(vector<int> pre,unordered_map<int,int> in,int l,int i,int r)//l is left sub tree's root, i is root,m is root in in order
// {
// //return condition
//         if(l>r)
//           return nullptr;
//         TreeNode* root=new TreeNode(pre[i]);
//         //get the root's index in inorder
//         int m=in[pre[i]];
//         //the left subtree is in [l,m-1] in inorder
//         //the left subtree's root is i+1 in pre
//         root->left=createTreeHelper(pre,in,l,i+1,m-1);
//         //the right subtree is in [m+1,r] in inorder
//         //the root of right root is at the i+m-l+1 index of preorder
//         root->right=createTreeHelper(pre,in,m+1,i+m-l+1,r);
//   return root;
// }
//
// TreeNode* createTree(vector<int> &pre,vector<int> &in)
// {
// //store the inorder traverse to unordered_map to enhance the performance of get element
// unordered_map<int,int> inOrder;
// for(int i=0;i<in.size();i++)
// {
//   inOrder[in[i]]=i;
// }
// return createTreeHelper(pre,inOrder,0,0,inOrder.size()-1);
// }
/* 构建二叉树：分治 */
TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorderMap, int i, int l, int r) {
  // 子树区间为空时终止
  if (r - l < 0)
    return NULL;
  // 初始化根节点
  TreeNode *root = new TreeNode(preorder[i]);
  // 查询 m ，从而划分左右子树
  int m = inorderMap[preorder[i]];
  // 子问题：构建左子树
  root->left = dfs(preorder, inorderMap, i + 1, l, m - 1);
  // 子问题：构建右子树
  root->right = dfs(preorder, inorderMap, i + 1 + m - l, m + 1, r);
  // 返回根节点
  return root;
}

/* 构建二叉树 */
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  // 初始化哈希表，存储 inorder 元素到索引的映射
  unordered_map<int, int> inorderMap;
  for (int i = 0; i < inorder.size(); i++) {
    inorderMap[inorder[i]] = i;
  }
  TreeNode *root = dfs(preorder, inorderMap, 0, 0, inorder.size() - 1);
  return root;
}
int main()
{
  vector<int> pre={1,2,4,5,3,6,7};
  vector<int> in={4,2,5,1,6,3,7};
  TreeNode* root=buildTree(pre,in);
  vector<int> resPre;
  root->inOrder(resPre);
  for (int val:resPre) {
    cout<<val<<" ";
  }
  return 0;
}