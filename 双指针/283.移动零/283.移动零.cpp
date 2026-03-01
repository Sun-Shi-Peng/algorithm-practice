class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return;
        int left = -1; //最后一个安置好非0元素的下标
        int right = 0; //寻找非0元素
        while (right < n)
        {
            if (nums[right] == 0)
                right++;
            else    //找到非0的数了，要进行交换（先交换到最开始位置）
                swap(nums[++left], nums[right++]);
            //先将left右移指向当前第一个0，
            //与right交换后right的位置变0，right再向后遍历
        }
    }
};