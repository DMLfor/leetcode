//负数不是回文数，把回文数的后半部分逆序取出，和前半部分对比

class Solution {

public:

    bool isPalindrome(int x) {

        if(x < 0 || x%10 == 0 && x != 0) return false;

        int res = 0;

        while(res<x)

        {

            res = res*10 + x%10;

            x /= 10;

        }

        return res == x || res/10 == x;

    }

};
