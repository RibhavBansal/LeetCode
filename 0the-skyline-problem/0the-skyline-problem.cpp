class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }

        return a[0] < b[0];
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& a) {
        vector<vector<int>>v;
        for(auto it : a){
            v.push_back({it[0],-1*it[2]});
            v.push_back({it[1],it[2]});
        }

        sort(v.begin(),v.end(),comp);
        multiset<int>st;
        st.insert(0);
        int k = -1;
        vector<vector<int>>ans;

        for(auto it : v){
            cout << it[0] << " " << it[1] << endl;
            if(it[1] < 0){
                it[1] *= -1;
                st.insert(it[1]);
                if(k < it[1]){
                    k = it[1];
                    ans.push_back({it[0],it[1]});
                }
            }
            else{
                st.erase(st.find(it[1]));
                if(k == *st.rbegin())continue;

                k = *st.rbegin();
                ans.push_back({it[0],k});
            }
        }

        return ans;
    }
};