// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

class Solution
{
    public:
    
    int dp[1000][1000];
    
    int recur(int i, int j, string s1, string s2)
    {
        if(i<0 || j<0 )
            return 0;
        if(i==0 && j==0)
        {
            if(s1[i]==s2[j])
                return 1;
            else
                return 0;
        }
        if(dp[i][j]==-1)
        {
            if(s1[i]==s2[j])
                dp[i][j] = 1+recur(i-1,j-1,s1,s2);
            else
            {
                dp[i][j] = max(recur(i-1,j,s1,s2),recur(i,j-1,s1,s2));
            }
        }
        return dp[i][j];
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();
        memset(dp,-1,sizeof(dp));
        return recur(m-1,n-1,s1,s2);
    }
};
