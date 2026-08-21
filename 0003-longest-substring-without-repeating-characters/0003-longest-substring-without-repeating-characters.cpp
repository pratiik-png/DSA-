class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
       unordered_map<char,int> freq;
    
        int left=0;
        int right=0;
        int ans=0;
            
        for(int right=0; right < s.length(); right++ ){

            //add current character
            freq[s[right]]++;
            // if duplicate exists
            while(freq[s[right]] > 1){

                freq[s[left]]--;

                if(freq[s[left]]==0){
                    freq.erase(s[left]);
                }
                left++;
            }
            ans= max(ans,right - left+1);
        }    

      return ans;
        
    }
};