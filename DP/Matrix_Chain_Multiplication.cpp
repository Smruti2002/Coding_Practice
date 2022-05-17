// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/

class Solution{
public:

    int dp[101][101];
    int recur(int i, int j,int arr[])
    {
        if(j-i==1)
        {
            dp[i][j] = arr[i-1]*arr[i]*arr[j];
            return dp[i][j];
        }
        else if(i==j)
        {
            dp[i][j] = 0;
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        else
        {
            dp[i][j] = INT_MAX;
            for(int k = i; k<j; k++)
            {
                dp[i][j] = min(dp[i][j],recur(i,k,arr)+recur(k+1,j,arr)+arr[i-1]*arr[k]*arr[j]);
            }
            
            return dp[i][j];
        }
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        
        return recur(1,N-1,arr);
    }
};
