class Solution {
public:
    int maxProfit(vector<int>& a){
        int k = a[0], n = a.size();
        int l = a[0];
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            l = max(l,a[i]);
            ans = max(ans,l-k);
            if(a[i] < k){ 
                k = a[i];
                l = a[i];
            }
        }
        if(ans <= 0)
        {
            return 0;
        }
        return ans;
    }
};