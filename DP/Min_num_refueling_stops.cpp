// https://leetcode.com/problems/minimum-number-of-refueling-stops/solution/

class Solution {
public:
    #define ll long long int
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if(n==0){
            if(startFuel >= target)
                return 0;
            return -1;
        }
        stations.push_back({0,0});
        for(int i = n; i>0; i--){
            stations[i]=stations[i-1];
        }
        stations[0][0]=0;
        ll dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i<=n; i++){
            dp[i][0] = startFuel;
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=i; j++){
                dp[i][j] = 0;
                if(dp[i-1][j]>=stations[i][0])
                    dp[i][j] = max(dp[i][j],dp[i-1][j]);
                if(dp[i-1][j-1]>=stations[i][0])
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+stations[i][1]);
            }
        }
        int inf = 1000;
        int ans = inf;
        for(int j = 0; j<=n; j++){
            if(dp[n][j]>=target){
                ans = min(ans,j);
            }
        }
        if(ans==inf)
            return -1;
        return ans;
    }
};
