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
vector<vector<int>> levelOrder(struct TreeNode* root) {
        vector<vector<int>> ans; 
        
        if(root == NULL) 
            return ans; 
            
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
           vector<int>v;
           int sz = q.size();
           for(int i = 0; i < sz; i++){
            TreeNode *temp = q.front(); 
            v.push_back(temp->val);
            q.pop(); 
            if(temp->left != NULL) 
                q.push(temp->left); 
            if(temp->right != NULL) 
                q.push(temp->right); 
            }
            ans.push_back(v); 
        }
        return ans; 
    }
};