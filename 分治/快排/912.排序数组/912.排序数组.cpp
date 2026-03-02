class Solution {
public:
    int getRandom(vector<int>& nums, int left, int right)
    {
        int r = rand();
        return nums[left + r % (right - left + 1)];
    }

    void qsort(vector<int>& nums, int l, int r)
    {
        if (l >= r)
            return;

        //数组分三块
        //1.获得随机数
        int key = getRandom(nums, l, r);
        //2.创建指针
        int i = l, left = l - 1, right = r + 1;
        //3.分区间
        while (i < right)
        {
            if (nums[i] < key)
                swap(nums[++left], nums[i++]);
            else if (nums[i] == key)
                i++;
            else
                swap(nums[i], nums[--right]);
        }

        //[l,left][left+1,right-1][right,r]

        qsort(nums, l, left);
        qsort(nums, right, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        srand(time(nullptr));   //种下随机数种子
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }
};