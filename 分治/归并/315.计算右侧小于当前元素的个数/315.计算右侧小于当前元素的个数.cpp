#define _CRT_SECURE_NO_WARNINGS
class Solution {
    vector<int> ret;
    vector<int> index;  //记录nums中当前元素下标的原始下标
    int tmpNums[100000];
    int tmpIndex[100000];   //交换后的下标
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ret.resize(n);
        index.resize(n);

        //初始化一个index数组
        for (int i = 0; i < n; i++)
            index[i] = i;

        MergeSort(nums, 0, n - 1);
        return ret;
    }

    void MergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;

        //1.根据中间元素划分区间
        int mid = left + (right - left) / 2;
        //[left,mid][mid+1,right]

        //2.先处理左右两部分
        MergeSort(nums, left, mid);
        MergeSort(nums, mid + 1, right);

        //3.处理一左一右的清空
        int cur1 = left, cur2 = mid + 1;
        int i = 0;
        //降序排序
        //nums[cur1]>nums[cur2] -> tmp1[cur1]+=right-cur2+1
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] <= nums[cur2])
            {
                tmpIndex[i] = index[cur2];
                tmpNums[i] = nums[cur2];
                i++, cur2++;
            }
            else
            {
                ret[index[cur1]] += right - cur2 + 1;
                tmpNums[i] = nums[cur1];
                tmpIndex[i] = index[cur1];
                i++, cur1++;
            }
        }

        while (cur1 <= mid)
        {
            tmpNums[i] = nums[cur1];
            tmpIndex[i] = index[cur1];
            i++, cur1++;
        }
        while (cur2 <= right)
        {
            tmpNums[i] = nums[cur2];
            tmpIndex[i] = index[cur2];
            i++, cur2++;
        }

        for (int j = left; j <= right; j++)
        {
            nums[j] = tmpNums[j - left];
            index[j] = tmpIndex[j - left];  //更新当前下标
        }
    }
};