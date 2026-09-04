class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq;

        int ans = n + 1;

        for (int i = 0; i <= n; i++) {

            // 1. Check if we have a valid subarray
            while (!dq.empty() &&
                   prefix[i] - prefix[dq.front()] >= k) {

                ans = min(ans, i - dq.front());

                dq.pop_front();
            }

            // 2. Remove useless prefix sums
            while (!dq.empty() &&
                   prefix[i] <= prefix[dq.back()]) {

                dq.pop_back();
            }

            // 3. Add current index
            dq.push_back(i);
        }

        return ans == n + 1 ? -1 : ans;
    }
};