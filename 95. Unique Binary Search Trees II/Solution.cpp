/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> solve(int start, int end){
        if(start > end){
            return {NULL};
        }
        if(start == end){
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        vector<TreeNode*> result;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left_bsts = solve(start, i-1);
            vector<TreeNode*> right_bsts = solve(i+1, end);
            for(TreeNode* leftRoot : left_bsts){
                for(TreeNode* rightRoot : right_bsts){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};