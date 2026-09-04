class Solution {
public:

    long long mergeSort(vector<long long>& prefix,
                        int left,
                        int right,
                        int lower,
                        int upper) {

        // Only one element
        if (right - left <= 1) {
            return 0;
        }

        int mid = left + (right - left) / 2;

        long long count = 0;

        // Count in left half
        count += mergeSort(prefix, left, mid, lower, upper);

        // Count in right half
        count += mergeSort(prefix, mid, right, lower, upper);

        // Count valid pairs across the two halves
        int low = mid;
        int high = mid;

        for (int i = left; i < mid; i++) {

            while (low < right &&
                   prefix[low] - prefix[i] < lower) {
                low++;
            }

            while (high < right &&
                   prefix[high] - prefix[i] <= upper) {
                high++;
            }

            count += high - low;
        }

        // Merge two sorted halves
        vector<long long> temp;

        int i = left;
        int j = mid;

        while (i < mid && j < right) {

            if (prefix[i] <= prefix[j]) {
                temp.push_back(prefix[i]);
                i++;
            } else {
                temp.push_back(prefix[j]);
                j++;
            }
        }

        while (i < mid) {
            temp.push_back(prefix[i]);
            i++;
        }

        while (j < right) {
            temp.push_back(prefix[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            prefix[left + k] = temp[k];
        }

        return count;
    }


    int countRangeSum(vector<int>& nums, int lower, int upper) {

        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, 0, n + 1, lower, upper);
    }
};