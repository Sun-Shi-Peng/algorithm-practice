#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        move(A.size(), A, B, C);
    }

    void move(int n, vector<int>& src, vector<int>& aux, vector<int>& dst)
    {
        //只有一个盘子直接移动到dst上
        if (n == 1)
        {
            dst.push_back(src.back());
            src.pop_back();
            return;
        }

        //将src上的n-1个盘子放到aux
        move(n - 1, src, dst, aux);

        //将剩余盘子放到dst
        dst.push_back(src.back());
        src.pop_back();

        //将aux上的盘子放到dst
        move(n - 1, aux, src, dst);
    }
};