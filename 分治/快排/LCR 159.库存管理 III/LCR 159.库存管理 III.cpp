#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        qsort(stock, 0, stock.size() - 1, cnt);
        return { stock.begin(),stock.begin() + cnt };
    }

    int getRandom(vector<int>& stock, int left, int right)
    {
        return stock[rand() % (right - left + 1) + left];
    }

    void qsort(vector<int>& stock, int l, int r, int cnt)
    {
        if (l >= r)
            return;
        //1.随机选择一个基准元素+数组分三块
        int key = getRandom(stock, l, r);
        int left = l - 1, right = r + 1, i = l;
        while (i < right)
        {
            if (stock[i] < key)
                swap(stock[++left], stock[i++]);
            else if (stock[i] == key)
                i++;
            else
                swap(stock[--right], stock[i]);
        }

        //[l,left][left+1,right-1][right,r]
        // a个元素    b个元素       c个元素

        //2.分情况讨论
        int a = left - l + 1, b = right - left - 1;
        if (a > cnt)
            qsort(stock, l, left, cnt);    //[l,left]找最小cnt个元素
        else if (a + b >= cnt)
            return;                     //[left+1,right-1]中元素都相同，不需要考虑
        else
            qsort(stock, right, r, cnt - a - b);  //[right,r]找cnt-a-b个最小元素
    }
};