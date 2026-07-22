class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int temp = 0;

        for (int x : nums) {

           
            temp += x;

            maxi = max(maxi, temp);
             if (temp < 0) temp = 0;
        }

        return maxi;
    }
};
