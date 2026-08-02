class Solution {
   public:
    int search(vector<int>& arr, int target) {
        // sort(mid.begin(), nums.end());
        int n = arr.size();
        int s = 0, e = n - 1;
        for (int i = 0; i < n; ++i) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (target > arr[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return -1;
    }
};
