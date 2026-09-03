class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;

        //Prefix sum 0 exist before the array starts
        mp[0]=-1;

        int sum=0;
        int ans=0;

        for(int i=0; i < nums.size(); i++){

            // convert 0 to -1
           if(nums[i] == 0){
            sum -= 1;
           }
           else{
            sum += 1;
           }

           // if we have seen this sum before 
           if(mp.find(sum) != mp.end()){

            int length = i - mp[sum];

            ans = max(ans, length);
           }
           else{
            // store only yhe first occurrence

            mp[sum] = i;
           }
        }
        return ans;
        
    }
};