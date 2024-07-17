#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class TreeNode {
public:    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    TreeNode* postorderAndDlt(TreeNode* root, unordered_set<int>& toDeleteSet, vector<TreeNode*>& ans){
        if(!root) return NULL;
        root->left = postorderAndDlt(root->left, toDeleteSet, ans);
        root->right = postorderAndDlt(root->right, toDeleteSet, ans);
        if(toDeleteSet.find(root->val) != toDeleteSet.end()) {
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            delete root;
            return NULL;
        }
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& target) {
        unordered_set<int> toDeleteSet(target.begin(), target.end());
        vector <TreeNode*> ans;
        root  = postorderAndDlt(root, toDeleteSet, ans);
        if(root) ans.push_back(root);
        return ans;
    }
};