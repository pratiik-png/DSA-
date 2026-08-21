class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;

        int left =0;
        int right =0;
        int ans=0;

        for(int right=0; right< fruits.size(); right++){
            // add current fruit

            freq[fruits[right]]++;

            // if we have more than 2 types of fruits
            while(freq.size() > 2){
                freq[fruits[left]]--;

                // removing fruit type when its count becomes 0
                if(freq[fruits[left]] == 0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            ans= max(ans, right-left+1);
        }
        return ans;
        
    }
};