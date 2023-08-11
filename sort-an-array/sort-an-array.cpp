class Solution {
public:
    void merge(vector<int>& a, int i, int m, int j, vector<int>&b){
        // vector<int>b = a;
        int t = m+1;
        int k = i;
        while(i <= m && t <= j){
            if(a[i] < a[t])
                b[k++] = a[i++];
            else 
                b[k++] = a[t++];
        }
        
        while(i <= m)
            b[k++] = a[i++];
        
        while(t <= j)
            b[k++] = a[t++];
        
        a = b;
    }
    
    void f(vector<int>& a, int i, int j, vector<int>&b) {
        if(i < j){
            int m = (i+j)/2;
            f(a,i,m,b);            
            f(a,m+1,j,b);
            merge(a,i,m,j,b);
        }
    }
    
    vector<int> sortArray(vector<int>& a) {
        int n = a.size();
        vector<int>b = a;
        f(a,0,n-1,b);
        
        return a;
    }
};