/* https://practice.geeksforgeeks.org/problems/minimum-swaps/1 */

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector <int>sorted_nums = nums;
	    sort(sorted_nums.begin(),sorted_nums.end());
	    int cnt = 0;
	    map <int,int> mp;
	    for(int i = 0; i<n; i++)
	    {
	        mp.insert({nums[i],i});
	    }
	    for(int i=0; i<n; i++)
	    {
	        if(nums[i]==sorted_nums[i])
	            continue;
	        else
	        {
	            cnt++;
	            nums[mp[sorted_nums[i]]] = nums[i];
	            mp[nums[i]] = mp[sorted_nums[i]];
	            mp[sorted_nums[i]] = i;
	            nums[i] = sorted_nums[i];
	        }
	    }
	    return cnt;
	}
};
