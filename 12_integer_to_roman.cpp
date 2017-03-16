//先打出各个位权对应的罗马数字，直接拆分得到答案
class Solution
{
public:
    string intToRoman(int num)
    {
        string roman[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        string ans = "";
        int cnt = 3, div = 1000;
        while(cnt>=0)
        {
            ans.append(roman[cnt][num/div%10]);
            div /= 10;
            cnt--;
        }
        return ans;
    }
};
