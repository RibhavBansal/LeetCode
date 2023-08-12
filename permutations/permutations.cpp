class Solution {
public:
    vector<vector<int> >v;
    void f(int n, vector<int>&p, vector<int>&hsh){
        if(p.size() == n){
            v.push_back(p);
            return;
        }

        for(int i = 0; i < 21; i++){
            if(hsh[i] == 0)
            continue;

            p.push_back(i-10);
            hsh[i] = 0;
            f(n,p,hsh);
            hsh[i] = 1;
            p.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& a) {
        vector<int>p;
        vector<int>hsh(21,0);
        for(int i = 0; i < a.size(); i++){
            hsh[a[i]+10] = 1;
        }

        f(a.size(),p,hsh);
        return v;
    }
};