#pragma GCC optimize("O2")

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

class Solution 
{
public:
    string countAndSay(int n) 
    {
        fast_io;

        string s = "1";
        for (int i = 2; i <= n; ++i)
        {
            string newStr = "";
            char current = s[0];
            int currentCount = 1, length = s.length();
            for (int j = 1; j < length; ++j)
            {
                if (s[j] == current)
                {
                    ++currentCount;
                    continue;
                }
                newStr += ('0' + currentCount);
                newStr += current;
                current = s[j];
                currentCount = 1;
            }
            newStr += ('0' + currentCount);
            newStr += current;
            s = newStr;
        }
        return s;    
    }
};