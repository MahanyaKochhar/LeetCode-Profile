class Solution {
public:
    int gcdOfOddEvenSums(int n)
    {
        int sum1 = (n * (2 * 1 + (n - 1) * 2)) / 2;
        int sum2 = (n * (2 * 2 + (n - 1) * 2)) / 2;
        int ans = __gcd(sum1,sum2);
        return ans;
    }
};
