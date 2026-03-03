#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(nullptr));
        return qsort(nums, 0, nums.size() - 1, k);
    }

    int getRandom(vector<int>& nums, int left, int right)
    {
        return nums[rand() % (right - left + 1) + left];
    }

    int qsort(vector<int>& nums, int l, int r, int k)
    {
        if (l == r) return nums[l];
        //1.随机选择基准元素
        int key = getRandom(nums, l, r);
        //2.根据基准元素将数组分三块
        int left = l - 1, right = r + 1, i = l;
        while (i < right)
        {
            if (nums[i] < key) swap(nums[++left], nums[i++]);
            else if (nums[i] == key) i++;
            else swap(nums[i], nums[--right]);
        }
        //[l,left][left+1,right-1][right,r]
        //           b个元素        c个元素

        //3.分情况讨论
        int c = r - right + 1, b = right - left - 1;
        if (c >= k)    return qsort(nums, right, r, k);   //[right,r]
        else if (b + c >= k) return key;                 //[left+1,right-1]
        else return qsort(nums, l, left, k - b - c);       //[l,left]
    }
};