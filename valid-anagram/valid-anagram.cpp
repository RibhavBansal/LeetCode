class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        return false;

        if(s == t)return true;

        unordered_map<char,int>mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            mp[t[i]]--;

            if(mp[s[i]] == 0)
            mp.erase(s[i]);

            if(mp[t[i]] == 0)
            mp.erase(t[i]);
        }

        if(mp.size() == 0)
        return true;

        return false;
    }
};