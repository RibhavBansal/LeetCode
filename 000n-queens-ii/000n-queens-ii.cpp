class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
	    int n = size(board);
	    for(int i = 0; i < n; i++) {
		    if(board[i][col] == 'Q') return false; 
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
	    }
	    return true;
    }

    int solve(vector<string>s, int k, int n, int i, int j)
    {
        if(k == 0)
        {
            return 1;
        }

        if(i == n)
        return 0;
        
        int ans = 0;

        for(int l = 0; l < n; l++)
        {
            if(isSafe(s,i,l))
            {
                s[i][l] = 'Q';
                ans += solve(s,k-1,n,i+1,l);
                s[i][l] = '.';
            }
        }
        return ans;
    }
    
    int totalNQueens(int n) {
        string s1 = "";
        for(int i = 0; i < n; i++)
        {
            s1 += '.';
        }
        vector<string>k(n,s1);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            k[0][i] = 'Q';
            ans += solve(k,n-1,n,1,i);
            k[0][i] = '.';
        }
        
        return ans;
    }
};