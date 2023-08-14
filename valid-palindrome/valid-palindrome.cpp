class Solution {
public:
    bool isPalindrome(string s) {
        string k = "";
        bool z;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                k += s[i];
            }
            else if(s[i] >= 'A' && s[i] <= 'Z')
            {
                k += tolower(s[i]);
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                k += s[i];
            }
        }
        string l = k;
        reverse(l.begin(),l.end());
        if(l == k)
        {
            z = true;
        }
        else
        {
            z = false;
        }
        cout << k;
        return z;
    }
};