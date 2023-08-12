class Solution {
public:
    set<vector<string>>v;
    vector<vector<string>>v1;
    bool isSafe(vector<string>& board, int row, int col) {
	    int n = size(board);
	    for(int i = 0; i < n; i++) {
		    if(board[i][col] == 'Q') return false; 
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
	    }
	    return true;
    }

    void solve(vector<string>s, int k, int n, int i, int j)
    {
        if(k == 0)
        {
            v.insert(s);
            return;
        }

        if(i == n)
        return;

        for(int l = 0; l < n; l++)
        {
            if(isSafe(s,i,l))
            {
                s[i][l] = 'Q';
                solve(s,k-1,n,i+1,l);
                s[i][l] = '.';
            }
        }
        return;
    }
    
    int totalNQueens(int n) {
        string s1 = "";
        for(int i = 0; i < n; i++)
        {
            s1 += '.';
        }
        vector<string>k(n,s1);
        vector<int>vis(n,0);
        for(int i = 0; i < n; i++)
        {
            k[0][i] = 'Q';
            solve(k,n-1,n,1,i);
            k[0][i] = '.';
        }

        for(auto it : v)
        {
            v1.push_back(it);
        }
        return v1.size();
    }
};