class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> answer;

        if (p.length() > s.length()) {
            return answer;
        }

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        // Frequency of characters in p
        for (char ch : p) {
            pFreq[ch - 'a']++;
        }

        int windowSize = p.length();

        // Create the first window
        for (int i = 0; i < windowSize; i++) {
            windowFreq[s[i] - 'a']++;
        }

        // Check first window
        if (pFreq == windowFreq) {
            answer.push_back(0);
        }

        // Slide the window
        for (int right = windowSize; right < s.length(); right++) {

            // Character entering the window
            windowFreq[s[right] - 'a']++;

            // Character leaving the window
            int left = right - windowSize;
            windowFreq[s[left] - 'a']--;

            // Check if current window is an anagram
            if (pFreq == windowFreq) {
                answer.push_back(left + 1);
            }
        }

        return answer;
    }
};