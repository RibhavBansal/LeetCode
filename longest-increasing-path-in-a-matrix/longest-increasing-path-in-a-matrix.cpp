class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& vis, vector<vector<int>>& dp){

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        int n=matrix.size();
        int m=matrix[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        vis[i][j]=1;
        int longest=1;
        for(int k=0; k<4; k++){
            int adjr = i+drow[k];
            int adjc = j+dcol[k];
            if(adjr>=0 && adjr<n && adjc>=0 && adjc<m && vis[adjr][adjc]==0){
                if(matrix[adjr][adjc]>matrix[i][j]){
                    longest = max(longest, 1+dfs(adjr, adjc, matrix, vis, dp));
                }
            }
        }
        vis[i][j]=0;
        return dp[i][j] = longest;
        return longest;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxx = INT_MIN;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dp[i][j]==-1){
                maxx = max(maxx, dfs(i, j, matrix, vis, dp));
                }
            }
        }

        return maxx;
    }
};