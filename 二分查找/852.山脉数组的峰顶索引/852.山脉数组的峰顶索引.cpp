#define _CRT_SECURE_NO_WARNINGS
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) //在上升
                left = mid + 1;
            else   //在下降
                right = mid;
        }
        return left;
    }

};