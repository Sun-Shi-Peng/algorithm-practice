class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums1 int整型vector
     * @param nums2 int整型vector
     * @return int整型vector
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // write code here
        vector<bool> hash(1010, false);
        vector<int> ret;
        for (auto num : nums1)
            hash[num] = true;
        for (auto num : nums2)
        {
            if (hash[num] == true)
            {
                ret.push_back(num);
                hash[num] = false;
            }
        }
        return ret;
    }
};