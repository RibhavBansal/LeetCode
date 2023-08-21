class Solution {
public:
    int ans = INT_MIN;
    // using height function for option3 of diameter function
    int height(TreeNode* r){
        if(r == NULL)return 0;

        int lt = max(0,height(r->left));
        int rt = max(0,height(r->right));

        ans = max(ans,lt+rt+r->val);

        return r->val + max(lt,rt);
    }
    int maxPathSum(TreeNode* root) {
        height(root);
        return ans; 
    }
};