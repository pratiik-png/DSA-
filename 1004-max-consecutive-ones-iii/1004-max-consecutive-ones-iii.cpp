class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int zeros=0;
        int ans=0;

        for(int right=0; right< nums.size() ; right++){
            // if current element is 0
            if(nums[right] ==0){
                zeros++;
            }
            // shrinking the window 
            while(zeros > k){
                if(nums[left] ==0){
                    zeros--;
                }

                left++;
            }
            // current window is valid'
          ans= max(ans,right-left+1);
        }
          return ans;
        
    }
};