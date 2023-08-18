class Solution {
public:
    int dx[8] = {0,-1,0,1,1,-1,1,-1};
    int dy[8] = {1,0,-1,0,1,-1,-1,1};
    void gameOfLife(vector<vector<int>>& a) {
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++){
                int ones = 0;
                for(int k = 0; k < 8; k++){
                    if(dx[k]+i < 0 || dx[k]+i >= a.size() || dy[k]+j < 0 || dy[k]+j >= a[0].size()) continue;
                    if(a[dx[k]+i][dy[k]+j] == 1 || a[dx[k]+i][dy[k]+j] == 6) ones++;
                }

                if(a[i][j] == 0){
                    if(ones == 3) a[i][j] = 5;
                }
                
                if(a[i][j] == 1){
                    if(ones < 2 || ones > 3) a[i][j] = 6;
                }
            }
        }
        
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++){
                if(a[i][j] == 5)a[i][j] = 1;
                if(a[i][j] == 6)a[i][j] = 0;
                // cout << a[i][j] << " ";
            }
            // cout << endl;
        }
    }
};