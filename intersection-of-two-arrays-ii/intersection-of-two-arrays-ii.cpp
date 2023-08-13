class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        set<int>s;
        if(a.size() >= b.size()){
            map<int,int>m;
        for(int i = 0; i < b.size(); i++)
        {
            m[b[i]]++;
        }
        vector<int>v;
        for(int i = 0; i < a.size(); i++)
        {
            if(m[a[i]] > 0)
            {
                v.push_back(a[i]);
                m[a[i]]--;
            }
        }
        return v;
        }
        else{
            map<int,int>m;
        for(int i = 0; i < a.size(); i++)
        {
            m[a[i]]++;
        }
        vector<int>v;
        for(int i = 0; i < b.size(); i++)
        {
            if(m[b[i]] > 0)
            {
                v.push_back(b[i]);
                m[b[i]]--;
            }
        }
        return v;
        }
    }
};