class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        
        int sum=0;
        int ans=0;

        // Prefix sum 0 already exist
        mp[0] =1;

        for(int x: nums){

            sum += x;
            // check if previous prefix exists
            if(mp.count(sum-k)){
                ans += mp[sum -k];
            }
            // store current prefix sum
            mp[sum]++;
        }
        return ans;

        
    }
};