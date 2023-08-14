class Solution {
public:
    int reverse(int x) {
        long long int ans = 0,k = 1;
        // if(x < 0) k *= -1;
        while(x){
            ans = ans*10 + (x%10);
            x /= 10;
        }
        
        // cout << INT_MIN << " " << INT_MAX << endl;
        
        if(ans >= INT_MAX || ans < INT_MIN)
            return 0;
        // ans *= k;
        return ans;
    }
};