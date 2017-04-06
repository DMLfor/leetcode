//规律已经给出了，只要要到每段字符的种类和个数，转化为字符串就可以了
class Solution
{
public:
    string countAndSay(int n)
    {
        string str = "1", tmp = "";
        for(int i = 2; i<=n; i++)
        {
            tmp = "";
            for(int j = 0; j<str.size(); j++)
            {
                int cnt = 0, num;
                if(j == 0 || str[j] != str[j-1])
                {
                    num = str[j] - '0';
                }
                int id = j;
                while(str[id] == str[j] && j<str.size())
                {
                    cnt++;
                    j++;
                }
                j--;
                tmp += getString(cnt) + getString(num);
            }
            str = tmp;
        }
        return str;
    }
    string getString(int x)
    {
        string res = "";
        while(x)
        {
            res += ('0' + x%10);
            x /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
