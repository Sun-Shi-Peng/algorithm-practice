#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int ret = 0;
        int n = nums.size();
        int left = 0, right = 0;
        while (right < n)
        {
            ret += nums[right++];
            while (left <= right && ret >= target)
            {
                min_len = min(min_len, right - left);
                ret -= nums[left++];
            }
        }
        if (min_len == INT_MAX)
            return 0;
        return min_len;
    }
};