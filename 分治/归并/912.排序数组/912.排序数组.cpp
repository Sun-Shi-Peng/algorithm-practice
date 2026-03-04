#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    void MergeSort(vector<int>& nums, int left, int right, vector<int>& tmp)
    {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        MergeSort(nums, left, mid, tmp);
        MergeSort(nums, mid + 1, right, tmp);

        int begin1 = left, end1 = mid;
        int begin2 = mid + 1, end2 = right;
        int index = begin1;

        while (begin1 <= end1 && begin2 <= end2)
        {
            if (nums[begin1] <= nums[begin2])
                tmp[index++] = nums[begin1++];
            else
                tmp[index++] = nums[begin2++];
        }

        while (begin1 <= end1)
            tmp[index++] = nums[begin1++];
        while (begin2 <= end2)
            tmp[index++] = nums[begin2++];

        for (int i = left; i <= right; i++)
        {
            nums[i] = tmp[i];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> tmp(nums.size());
        MergeSort(nums, 0, nums.size() - 1, tmp);
        return nums;
    }
};