class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete= arr[0];
        int oneDelete = arr[0];

        int ans= arr[0];

        for(int i=1; i<arr.size(); i++){
           int x= arr[i];
           // when no delete is done
           int newNoDelete= max(x,noDelete + x);
           // when delete is done
           int newOneDelete = max(noDelete, oneDelete + x);

           noDelete = newNoDelete;
           oneDelete = newOneDelete;
           
           ans= max(ans,max(noDelete , oneDelete));

        }
        return ans;


    }
};