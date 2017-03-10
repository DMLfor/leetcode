class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.size();
        string ans = "";
        int row = 0, line = 0, x = numRows - 1, cnt =  0, id;
        if(numRows == 1)
            return s;
        while(row<numRows && cnt < n)
        {
            id = row;
            int flag = 0;
            while(id < n && cnt < n)
            {
                ans += s[id];
                if(row != 0 && row != numRows-1)
                {
                    if(!flag)
                        id += 2*x;
                    else id += 2*numRows - 2*x -2;
                    flag ^= 1;
                }
                else id += 2*(numRows - 1);
                cnt++;
            }
            x--, row++;

        }
        return ans;
    }
};
