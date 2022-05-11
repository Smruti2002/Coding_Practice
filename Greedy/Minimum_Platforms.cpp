// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	multiset<pair<int,char>> mt;
    	for(int i = 0; i<n; i++)
    	{
    	    mt.insert(make_pair(arr[i],'a'));
    	    mt.insert(make_pair(dep[i],'d'));
    	}
    	int platform = 0;
    	int temp = 0;
    	for(auto it : mt)
    	{
    	    if(it.second=='a')
    	        temp++;
    	    else
    	        temp--;
    	    platform = max(temp,platform);
    	}
    	return platform;
    }
};
