#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;    //<nums[i],i>
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];   //当前值要找的值
            if (hash.count(x))   return { hash[x],i }; //看前面有没有要找的x
            hash[nums[i]] = i;    //存入当前值
        }
        return { -1,-1 };
    }
};