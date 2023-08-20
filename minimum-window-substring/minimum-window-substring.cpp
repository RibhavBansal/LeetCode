class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        for(int i = 0; i < t.size(); i++){
            mp[t[i]]++;
        }
        int cnt = mp.size();
        string s1 = "";

        int i = 0, j = 0, ans = INT_MAX, l = 0;
        while(cnt == 0 || j < s.size()){
            if(cnt == 0){
                while(cnt == 0 && i <= j){
                    if(ans >= j-i)
                       l=i;
                    ans = min(ans,j-i);
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] > 0)
                        cnt++;
                    }
                    i++;
                }
            }
            else{
                if(mp.find(s[j]) != mp.end()){
                    mp[s[j]]--;
                    if(mp[s[j]] == 0)
                    cnt--;
                }
                j++;
            }
        }
        if(cnt == 0){
            if(ans >= j-i)
                   l=i;
            ans = min(ans,j-i);
        }
        cout << ans << endl;
        
        if (ans != INT_MAX) 
            return s.substr(l,ans);
        return s1;
    }
};