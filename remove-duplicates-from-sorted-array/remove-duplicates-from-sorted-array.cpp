class Solution {
public:
    int removeDuplicates(vector<int>& a) {
    int n = a.size();
    int j = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] != a[i-1])
        {
            a[j] = a[i];
            j++;
        }
    }
    // a[j] = a[n-1];
    // j++;
    return j;
    }
};