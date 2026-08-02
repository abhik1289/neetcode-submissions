class Solution {
   public:
    bool can(vector<int>& weights, int mid, int days) {
        int curr = 0;
        int day = 1;

        for (auto x : weights) {
            if (curr + x <= mid) {
                curr += x;
            } else {
                day++;
                curr = x;
            }
        }

        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (can(weights, mid, days)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};