class Solution {
   public:
    int mySqrt(int x) {
        int l = 1, r = x;
        int ans = -1;

        if (x <= 1) return x;

        if(x==3)
        return 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
  long long square = 1LL * mid * mid;

            if (square == x)
                return mid;
            else if (square < x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
               
            }
        }
        return ans;
    }
};