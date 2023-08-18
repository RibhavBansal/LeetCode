class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        map<int,int>mp;
        for(auto it : a){
            mp[it]++;
        }
        
        int cnt = 0;
        for(auto it : a){
            if(mp.find(it-1) == mp.end()){
                int k = 0, l = it;
                while(mp.find(l) != mp.end()){
                    l++;k++;
                }
                cnt = max(cnt,k);
            }
        }
        
        return cnt;
    }
};