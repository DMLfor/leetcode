//注意反转后可能溢出
class Solution {
public:
    int reverse(int x) {
        string MIN = "2147483648", MAX = "2147483647", rever = "";
        int flag = 0;
        if(x < 0)
        flag = 1, x = -x;
        int ans = 0;
        while(x)
        {
            ans = x%10 + ans*10;
            rever += '0' + x%10;
            x /= 10;
        }
        if(flag == 1)
        {
            if(rever.size() > MIN.size() || rever.size() == MIN.size() && rever > MIN)
                return 0;
        }
        else
        {
            if(rever.size() > MAX.size() || rever.size() == MAX.size() && rever > MAX)
                return 0;
        }
        if(flag) return -ans;
        else return ans;
    }
};
