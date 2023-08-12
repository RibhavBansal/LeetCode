class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if ((n == 0) || (k <= 0))
        {
            return;
        }
        
        // Make a copy of nums
        vector<int> numsCopy(n);
        for (int i = 0; i < n; i++)
        {
            numsCopy[i] = nums[i];
        }
        
        // Rotate the elements.
        for (int i = 0; i < n; i++)
        {
            nums[(i + k)%n] = numsCopy[i];
        }
    }
};

// class Solution {
// public:
//     void rotate(vector<int>& a, int k) {
//         int n = a.size();
//         vector<int>v(n,0);
//         int j = 0;
//         k = k%n;
//         for(int i = n-k; i < n; i++)
//         {
//             v[j] = a[i];
//             j++;
//         }
//         for(int i = 0; i < n-k; i++)
//         {
//             v[j] = a[i];
//             j++;
//         }
//         for(int i = 0; i < n; i++)
//         {
//             a[i] = v[i];
//         }
//     }
// };