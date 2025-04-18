class Solution 
{
public:
    string countAndSay(int n) 
    {
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