class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        map<char,int>mp;
        int id = -1;
        for(int i = n-1; i >= 0; i--){
            mp[s[i]] += 1;
        }
        
        for(int i = n-1; i >= 0; i--){
            if(mp[s[i]] == 1) id = i;
        }
        return id;
    }
};