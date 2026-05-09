class Solution {
public:
    int fun(int n)
    {
        if(n==0)
        return 1;
        if(n<0)
        return 0;

        return fun(n-1)+fun(n-2);

    }
    int climbStairs(int n) {
      return fun(n);  
    }
};
