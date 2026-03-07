#define _CRT_SECURE_NO_WARNINGS
class Solution {
    int tmp[50010];

public:
    int reversePairs(vector<int>& nums) {
        return Mergesort(nums, 0, nums.size() - 1);
    }

    int Mergesort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0;
        int ret = 0;
        // 1.先根据中间元素划分区间
        int mid = left + (right - left) / 2;
        // 2.先计算左右两侧翻转对数量
        ret += Mergesort(nums, left, mid);
        ret += Mergesort(nums, mid + 1, right);

        // 3.计算一左一右翻转对数量
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if ((long long)nums[i] > (long long)2 * nums[j]) {
                ret += right - j + 1;
                i++;
            }
            else
                j++;
        }

        // 4.合并两个有序数组
        int cur1 = left, cur2 = mid + 1;
        i = 0;
        // 降序
        while (cur1 <= mid && cur2 <= right) {
            if (nums[cur1] <= nums[cur2]) {
                tmp[i++] = nums[cur2++];
            }
            else
                tmp[i++] = nums[cur1++];
        }
        while (cur1 <= mid)
            tmp[i++] = nums[cur1++];
        while (cur2 <= right)
            tmp[i++] = nums[cur2++];

        while (cur1 <= mid && cur2 <= right) {
            if (nums[cur1] <= nums[cur2]) {
                tmp[i++] = nums[cur1++];
            }
            else
                tmp[i++] = nums[cur2++];
        }
        for (int i = left; i <= right; i++)
            nums[i] = tmp[i - left];

        return ret;
    }
};