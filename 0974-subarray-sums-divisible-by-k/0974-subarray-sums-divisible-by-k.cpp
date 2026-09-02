class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
        // remainder 0 we have seen before array starting
        mp[0]=1;

        int sum=0;
        int ans=0;

        for(int i=0; i < nums.size(); i++){
            sum += nums[i];

            int rem= sum % k;
            //fix negative remainder
            if(rem < 0){
                rem +=k;
            }
            // same remainder means valid subarray

            ans += mp[rem];
            // store the remainder
            mp[rem]++;
        }
        return ans;
        
    }
};