//
// Created by GlokieYu on 25-3-27.
//
#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
/*
*
 * 找到二叉树中能到7的路径，并且不要中间有3的
* 做法：回溯剪枝模版
 * */
class TreeNode {
    void dfs(string order, vector<int> &res, TreeNode *node) {
        if (node == nullptr)
            return;
        if (order == "pre")
            res.push_back(node->val);
        dfs(order, res, node->left);
        if (order == "in")
            res.push_back(node->val);
        dfs(order, res, node->right);
        if (order == "post")
            res.push_back(node->val);
    }

public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value): val(value), left(nullptr), right(nullptr) {
    }
    vector<int> levelOrder() {
        queue<TreeNode *> queue;
        queue.push(this);
        vector<int> res;
        while (!queue.empty()) {
            TreeNode* node=queue.front();
            res.push_back(node->val);
            queue.pop();
            if (node->left != nullptr)
                queue.push(node->left);
            if (node->right != nullptr)
                queue.push(node->right);
        }
        return res;
    }
    vector<int> preOrder() {
        vector<int> res;
        dfs("pre",res,this);
        return res;
    }
    vector<int> inOrder() {
        vector<int> res;
        dfs("in",res,this);
        return res;
    }
};

bool isSolution(vector<TreeNode *> state) {
    return !state.empty() && state.back()->val == 7;
}

void recordSolution(vector<vector<TreeNode *> > &res, vector<TreeNode *> state) {
    res.push_back(state);
}

bool isValid(TreeNode *choice, vector<TreeNode *> state) {
    return choice != nullptr && choice->val != 3;
}

void makeChoice(vector<TreeNode *> &state, TreeNode *choice) {
    state.push_back(choice);
}

void undoChoice(vector<TreeNode *> &state) {
    state.pop_back();
}

void backTrack(vector<TreeNode *> &state, vector<TreeNode *> &choices, vector<vector<TreeNode *> > &res) {
    if (isSolution(state)) {
        recordSolution(res, state);
        //此处没有return，因为找到7之后要接着往下找，防止一颗子树上有多个7
    }
        for (TreeNode *choice: choices) {
        if (isValid(choice, state)) {
            makeChoice(state, choice);
            vector<TreeNode *> nextChoices = {choice->left, choice->right};
            backTrack(state, nextChoices, res);
            undoChoice(state);
        }
    }
}

TreeNode *createTreeHelper(vector<int> &pre, unordered_map<int, int> &in, int left, int i, int right) {
    if (left > right) //no element
        return nullptr;
    TreeNode *root = new TreeNode(pre[i]);
    int m = in[pre[i]];//find the root 's value 's corresponding index in inorder to get m
    //left tree in inorder is in left to m-1
    //root of left tree in preorder is at i+1
    root->left = createTreeHelper(pre, in, left, i + 1, m - 1);
    //right tree in inorder is in m+1,right
    //the root of right tree in preorder is at i+m-l+1 (m-l)is the number of left tree's elements
    root->right = createTreeHelper(pre, in, m + 1, i + (m - left) + 1, right);
    return root;
}

TreeNode *createTree(vector<int> &pre, vector<int> &inorder) {
    unordered_map<int, int> in;
    for (int i = 0; i < inorder.size(); i++) { in[inorder[i]] = i; }
    return createTreeHelper(pre, in, 0, 0, inorder.size()-1);//should be size-1
}

int main() {
    // vector<int> pre={1,7,4,5,3,6,7};
    // vector<int> in={4,7,5,1,6,3,7};
    // TreeNode* node=createTree(pre,in);
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(7);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(7);
    root->right->left=new TreeNode(6);
    vector<vector<TreeNode*>> res;
    vector<TreeNode*>state;
    vector<TreeNode*> choices={root};
    backTrack(state,choices,res);
    for (int i = 0; i < res.size(); i++) {
        for ( int j = 0; j < res[i].size(); j++) {
            cout << res[i][j]->val << " ";
        }
    }
    return 0;
}
