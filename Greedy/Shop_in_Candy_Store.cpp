//https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int num,min_amt = 0,max_amt =0;
        num = N/(K+1);
        if(N%(K+1)!=0)
            num++;
        for(int i = 0; i<num; i++)
            min_amt += candies[i];
            
        int i = N-1;
        while(num--)
        {
            max_amt += candies[i];
            i--;
        }
        vector<int> res = {min_amt,max_amt};
        return res;
    }
};
