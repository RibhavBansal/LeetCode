class Solution {
public:
    vector<vector<int>>v;
    void solve(int i, vector<int>&a, int n, int k)
    {
        if(k == 0)
        {
            v.push_back(a);
            return;
        }

        if(i > n)
        return;

        a.push_back(i);
        solve(i+1,a,n,k-1);
        a.pop_back();
        solve(i+1,a,n,k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>a;
        solve(1,a,n,k);
        return v;
    }
};