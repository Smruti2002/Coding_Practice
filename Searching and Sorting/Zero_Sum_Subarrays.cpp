
/* 
   Problem Link
   https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

*/

/*
    Idea is to maintain a map of sums, and whenever a sum is repeated means 
    a zero sum subarray has encountered
    By defualt all values of map are set to zero 
*/

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        
        map <ll,ll> mp;
        ll sum = 0;
        ll cnt = 0;
        for(int  i = 0; i<n; i++)
        {
            sum += arr[i];
            if(sum==0)
            {
                cnt++;
            }
            cnt += mp[sum];
            mp[sum]++;
        }
        return cnt;
    }
};