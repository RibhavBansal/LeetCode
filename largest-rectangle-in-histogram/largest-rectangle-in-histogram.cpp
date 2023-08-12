class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int>st;
        int ls,rs, ans = 0;
        int n = a.size();
        for(int i = 0; i <= n; i++){
            if(i == n){
                rs = n;
                while(!st.empty()){
                    int k = st.top();
                    st.pop();
                    if(st.empty())ls = -1;
                    else ls = st.top();

                    ans = max(ans,(rs-ls-1)*a[k]);
                }
            }
            else if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && a[i] < a[st.top()]){
                    rs = i;
                    int k = st.top();
                    st.pop();
                    if(st.empty())ls = -1;
                    else ls = st.top();
                    // cout << i << " " << ls << " " <<  rs << " " << endl;

                    ans = max(ans,(rs-ls-1)*a[k]);
                }
                st.push(i);
            }
            // cout << ans << " ";
        }

        return ans;
    }
};