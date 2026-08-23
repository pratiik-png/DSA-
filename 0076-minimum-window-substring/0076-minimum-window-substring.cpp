class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size())
            return "";

        vector<int> need(128, 0);

        // Store frequency of characters required from t
        for (char ch : t) {
            need[ch]++;
        }

        int left = 0;
        int count = t.size();

        int minLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            // If this character is required
            if (need[s[right]] > 0) {
                count--;
            }

            need[s[right]]--;

            // Window is valid
            while (count == 0) {

                // Update minimum window
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                // Remove left character
                need[s[left]]++;

                if (need[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX)
            return "";

        return s.substr(start, minLength);
    }
};