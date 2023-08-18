class Solution {
public:
    int maxArea(vector<int>& a) {
        int mx = 0, n = a.size();
        int i = 0, j = n-1;

        while(i <= j){
            mx = max(mx,(j-i)*min(a[i],a[j]));
            if(a[i] <= a[j])
            i++;
            else
            j--;
        }
        return mx;
    }
};