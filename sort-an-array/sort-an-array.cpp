class Solution {
public:
    void heapify(vector<int>& a, int n, int i){
        int lt = i;
        int l = 2*i+1;
        int r = 2*i+2;
        
        if(l < n && a[l] > a[lt])
            lt = l;
        
        if(r < n && a[r] > a[lt])
            lt = r;
        
        if(i != lt){
            swap(a[i],a[lt]);
            heapify(a,n,lt);
        }
    }
        
    vector<int> sortArray(vector<int>& a) {
        int n = a.size();
        for(int i = n/2-1; i >= 0; i--){
            heapify(a,n,i);
        }
        
        for(int i = n-1; i >= 0; i--){
            swap(a[0],a[i]);
            heapify(a,i,0);
        }
        
        return a;
    }
};