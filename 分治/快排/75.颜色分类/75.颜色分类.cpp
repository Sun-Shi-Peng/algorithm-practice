class Solution {
public:
    void sortColors(vector<int>& nums) {
        //解法：三指针
        //left:0区域的最右侧，right：2区域的最左侧，i：遍历数组
        //分为4个区域[0,left]全为0，[left+1,i-1]:全为1
        //[i,right-1]:待扫描元素，[right,n-1]:全为2
        int n = nums.size();
        int left = -1, right = n, i = 0;
        while (i < right)
        {
            if (nums[i] == 0)
                swap(nums[++left], nums[i++]);   //换过来的是0,可以++
            else if (nums[i] == 2)
                swap(nums[--right], nums[i]);    //右边换过来的是未知值，需要继续判断
            else if (nums[i] == 1)
                i++;
        }
    }
};