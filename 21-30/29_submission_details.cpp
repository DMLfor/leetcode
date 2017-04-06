//倍增法，让除数倍增，使得被除法一直减去它
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int mark = 1;
        int cnt = 0, tmp = divisor, flag = 1;
        if(divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            mark = 0;
        long long ll_dividend = labs(dividend), ll_divisor = labs(divisor);
        while(ll_dividend>=ll_divisor)
        {
            long long tmp = ll_divisor, flag = 1;
            while(ll_dividend >= tmp)
            {
                ll_dividend -= tmp;
                cnt += flag;
                tmp += tmp;
                flag += flag;

            }
        }
        if(mark==0)
            return -cnt;
        else return cnt;
    }
};
