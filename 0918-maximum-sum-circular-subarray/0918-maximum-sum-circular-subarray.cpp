class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        int maxSum = nums[0];
        int currentMax = nums[0];

        int minSum = nums[0];
        int currentMin = nums[0];

        for (int i = 0; i < nums.size(); i++) {

            total += nums[i];

            if (i > 0) {

                // Normal Kadane
                currentMax = max(nums[i], currentMax + nums[i]);
                maxSum = max(maxSum, currentMax);

                // Minimum Kadane
                currentMin = min(nums[i], currentMin + nums[i]);
                minSum = min(minSum, currentMin);
            }
        }

        // All elements are negative
        if (maxSum < 0) {
            return maxSum;
        }

        // Two possibilities:
        // 1. Normal maximum subarray
        // 2. Circular maximum subarray
        int circularSum = total - minSum;

        return max(maxSum, circularSum);
    }
};