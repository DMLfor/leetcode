//先按照对角线反转，然后反转每一行，可以达到旋转90度的效果
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sz = matrix[0].size();
        for(int i = 0; i<sz; i++)
            for(int j = 0; j<i; j++)
                swap(matrix[i][j], matrix[j][i]);

        for(int i = 0; i<sz; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
