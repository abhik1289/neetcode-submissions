class Solution {
   public:
    bool can(vector<int>& piles, int mid, int h) {
        double time = 0;

        for (int x : piles) {
            time += (x + mid - 1) / mid;
        }
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (can(piles, mid, h)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
