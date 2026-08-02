class Solution {
   public:
    int searchInsert(vector<int>& arr, int target) {
        int s = 0, e = arr.size() - 1;
        int ans = -1;

        if (target < arr[0]) return 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target)
                return mid;

            else if (arr[mid] < target) {
                s = mid + 1;
                ans = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return ans;
    }
};