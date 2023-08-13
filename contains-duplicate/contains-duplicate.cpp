class Solution {
public:
    bool containsDuplicate(vector<int>& a) {
        map<int,int>m;
        for(int i = 0; i < a.size(); i++)
        {
            if(m[a[i]] > 0)
            return true;

            m[a[i]]++;
        }
        return false;
    }
};