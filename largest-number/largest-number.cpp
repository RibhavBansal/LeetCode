class Solution {
public:
    static int mycompare(int a, int b)
    {
        string ab = to_string(a).append(to_string(b));
        string ba = to_string(b).append(to_string(a));
    
        return ab.compare(ba) > 0 ? 1 : 0;
    }

    string largestNumber(vector<int>& A) {
        vector<int>arr = A;
        sort(arr.begin(), arr.end(), mycompare);
        string str = "";
        for(int i = 0; i<arr.size(); i++)
        {
            str += to_string(arr[i]);
        }
        if(str[0]=='0') return to_string(0);
        return str;
    }
};