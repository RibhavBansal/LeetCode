class Solution {
public:
    vector<string>v;
    map<int,string>mp;
    void f(int i, string &a, string k){
        if(i == a.size()){
            v.push_back(k);
            return;
        }

        string s = mp[a[i]-'0'];
        for(int j = 0; j < s.size(); j++){
            f(i+1,a,k+s[j]);
        }
    }

    vector<string> letterCombinations(string a) {
        mp.clear();
        v.clear();
        if(a.size() == 0)
        return v;
        mp[2] = "abc";mp[3] = "def";mp[4] = "ghi";mp[5] = "jkl";mp[6] = "mno";mp[7] = "pqrs";mp[8] = "tuv";mp[9] = "wxyz";
        string k = "";
        f(0,a,k);
        return v;
    }
};