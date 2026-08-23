class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right =0;
        int maxFreq=0;
        int ans=0;

        vector<int> freq(26,0);

        for(int right=0; right < s.size();right++ ){
            // adding current character
            freq[s[right] - 'A']++;

            // max frequency in current window 
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            //number of character we need to replace 

            int changes= (right- left +1) - maxFreq;

            // If changes > k, shrinkmthe window
            while(changes>k){
                freq[s[left] - 'A']--;
                left++;

                changes = (right- left+1) - maxFreq;
            }

            ans= max(ans, right- left +1);
        }

        return ans;


        
        
    }
};