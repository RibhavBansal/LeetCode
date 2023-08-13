class Solution {
public:
    int singleNumber(vector<int>& a) {
        // sort(a.begin(),a.end());
        int n = a.size();
        int k = 0;

        for(int i = 0; i < a.size(); i++)
        {
            k ^= a[i];
        }
        return k;
    }
};