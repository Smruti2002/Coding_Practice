// https://practice.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1/

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        
        vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++)
        {
            v[i].first = price[i];
            v[i].second = i+1;
        }
        sort(v.begin(),v.end());
        int stocks = 0,temp;
        for(int i = 0; i<n; i++)
        {
            temp = k/v[i].first;
            if(temp>= (v[i].second))
            {
                k = k - v[i].second*(v[i].first);
                stocks += v[i].second;
            }
            else
            {
                k = k - temp*(v[i].first);
                stocks += temp;
            }
        }
        return stocks;
    }
};
