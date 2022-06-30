
// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1
class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int pre[R][C];
        for(int i =0; i<R; i++){
            for(int j=0; j<C; j++){
                pre[i][j] = M[i][j];
                if(i!=0)
                    pre[i][j] += pre[i-1][j];
                if(j!=0)
                    pre[i][j] += pre[i][j-1];
                if(i!=0 && j!=0)
                    pre[i][j] -= pre[i-1][j-1];
            }
        }
        
        int global_maxi = INT_MIN;
        for(int i=0; i<R; i++){
            for(int j =i ; j<R; j++){
                int max_so_far = INT_MIN,temp;
                int prev = pre[j][0];
                if(i!=0)
                    prev-= pre[i-1][0];
                max_so_far = prev;
                for(int k=1; k<C; k++){
                    temp = pre[j][k]-pre[j][k-1];
                    if(i!=0){
                        temp = temp - pre[i-1][k] + pre[i-1][k-1];
                    }
                    prev = max(prev+temp,temp);
                    max_so_far = max(max_so_far,prev);
                }
                global_maxi = max(global_maxi,max_so_far);
            }
        }
        return global_maxi;
    }
};
