#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;    //第一个为值，第二个为多少个
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.count(nums[i]))
                return true;
            hash[nums[i]]++;
        }
        return false;
    }
};