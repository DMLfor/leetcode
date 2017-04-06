//�����ݣ������Ϊ�����ͱ�Ϊ���������int���
class Solution {
    double myPow(double x, int n) {
        double res = 1.0;
        int mark = 0;
        if(n<0) mark = 1;
        long long tmp = labs(n);
        while(tmp)
        {
            if(tmp & 1)
                res *= x;
            x *= x;
            tmp >>= 1;
        }
        if(mark) res = 1.0/res;
        return res;
    }
};
