class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right =0;
        int sum=0;
        int ans= INT_MAX;

        for(int right=0; right< nums.size(); right++){
            // add current sum
             sum += nums[right];

             // shrink window
             while(sum >= target){
                //update min window
                ans= min(ans, right-left+1);

                // remove the left elemnt 
                sum -=nums[left];
                left++;
             }

        }

        // if no subarray was found
        if(ans == INT_MAX){
            return 0;
        }

        return ans;
        
    }
};