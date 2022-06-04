// https://practice.geeksforgeeks.org/contest/challenge-1-array-matrix/problems


class Solution{
  public:
  vector<vector<int>> setMatrix(int n, int m, int q, vector<vector<int>> vec){
      vector<vector<int>> res(n,vector<int> (m,0));
      for(int i =0; i<q; i++)
      {
          int x1 = vec[i][0]-1;
          int y1 = vec[i][1]-1;
          int x2 = vec[i][2]-1;
          int y2 = vec[i][3]-1;
          
          // building a 2D partial sum matrix
          
          res[x1][y1]++;
          if(x2!=n-1)
          {
              res[x2+1][y1]--;
          }
          if(y2!=m-1)
          {
              res[x1][y2+1]--;
          }
          if(x2!=n-1 && y2!=m-1)
            res[x2+1][y2+1]++;
      }
      for(int i = 0; i<n; i++)
      {
          for(int j = 0; j<m; j++)
          {
              // finding the prefix sum of the matrix
              if(i==0 && j==0)
              {
                  res[i][j] = res[i][j];
              }
              else if(i==0)
              {
                  res[i][j] = res[i][j] + res[i][j-1];
              }
              else if(j==0)
              {
                  res[i][j] = res[i][j] + res[i-1][j];
              }
              else
              {
                  res[i][j] = res[i][j] + res[i-1][j] + res[i][j-1] - res[i-1][j-1];
              }
          }
      }
      return ans;
  }
};
