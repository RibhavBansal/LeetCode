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
    bool solve(TreeNode* c,long long int mn,long long int mx)
    {
        if(c == NULL)
        return true;

        if(c->val <= mn || c->val >= mx)
        return false;

        return solve(c->left,mn,c->val) && solve(c->right,c->val,mx);
    }

    bool isValidBST(TreeNode* root) {
        long long int mx = 1e10;
        long long int mn = -1e10;
        return solve(root,mn,mx);
    }
};