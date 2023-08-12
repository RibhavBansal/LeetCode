class Solution {
public:
    vector<string>v;
    string dp[10][10];
    void solve(int n, int m,string s)
    {
        if(dp[n][m] != "")
        {
            v.push_back(dp[n][m]);
            return;
        }

        if(n > m)
        return;

        if(n == 0)
        {
            while(m != 0)
            {
                s += ')';
                m--;
            }
            dp[n][m] = s;
            v.push_back(s);
            return;
        }

        if(m == 0)
        return;

        solve(n-1,m,s+'(');
        solve(n,m-1,s+')');

        return;
    }
    vector<string> generateParenthesis(int n) {
        solve(n,n,"");
        return v;
    }
};