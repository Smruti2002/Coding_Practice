// https://leetcode.com/problems/frog-jump/

class Solution {
public:
    
    int dp[2005][2005];
    map<int,int> mp;
    int recur(int i, int k, vector<int> &stones)
    {   
        if(k>2000 || k<=0)
            return 0;
        if(i<=0 || i>=stones.size())
            return 0;
        if(i==1)
        {
            if(k==1)
                return 1;
            else
                return 0;
        }
        if(dp[i][k]==-1)
        {
            dp[i][k] = 0;
            if(mp.find(stones[i]-k)!=mp.end())
            {
                int j = mp[stones[i]-k];
                dp[i][k] = dp[i][k] | recur(j,k,stones) | recur(j,k-1,stones) | recur(j,k+1,stones);
            }
        }
        return dp[i][k];
    }
    
    bool canCross(vector<int>& stones) {
        
        if(stones[1]!=1)
            return false;
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i<stones.size(); i++)
        {
            mp[stones[i]] = i;
        }
        int n = stones.size()-1;
        int ans = 0;
        for(int k = 1; k<=2000; k++)
        {
            if(recur(n,k,stones)==1)
            {
                ans = 1;
                break;
            }
        }
        return ans==1;
    }
};
