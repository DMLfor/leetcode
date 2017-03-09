class Solution
{
public:
    int myAtoi(string str)
    {
        int flag = 0, mark = 0, i = 0;
        string MIN = "2147483648", MAX = "2147483647";
        int dmin = -2147483648, dmax = 2147483647;
        while(str[i] == ' ' && i<str.size())
            i++;
        if(i >= str.size())
            return 0;
        if(str[i] == '-')
            flag = 1;
        string digit = "";
        if(str[i] == '-' || str[i] == '+')
        {
            i++;
            while(str[i] == '0')
            {
                if(str[i] == '+' && flag == 1 || str[i] == '-' && flag == 0)
                    return 0;
                i++;
            }
        }
        while(i<str.size())
        {
            if(str[i]<='9' && str[i]>='0')
                digit += str[i];
            else break;
            i++;
        }
        if(flag == 1)
        {
            if(digit.size() > MIN.size() || digit.size() == MIN.size() && digit > MIN)
                return dmin;
        }
        else
        {
            if(digit.size() > MAX.size() || digit.size() == MAX.size() && digit > MAX)
                return dmax;
        }

        int ans = 0;
        for(int i = 0; i<digit.size(); i++)
            ans = ans*10 + digit[i] - '0';
        if(flag)
            ans *= -flag;
        return ans;
    }
};
