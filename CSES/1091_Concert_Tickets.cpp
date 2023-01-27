// https://cses.fi/problemset/task/1091/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin() ,v.rend()
#define ss second
#define ff first
#define mk make_pair
#define pb push_back
#define f(i,k,n) for(i=k; i<n; i++)
#define lb(arr,key) lower_bound(arr.begin(),arr.end(),key)
#define ub(arr,key) upper_bound(arr.begin(),arr.end(),key)
//#define sort(arr) sort(arr.begin(),arr.end())
#define google(res) cout << "Case #"<< t1 << ": " << res << "\n";

ll mod = 1000000007;

ll exp(ll a, ll b) // returns a^b % mod
{
    ll ans = 1;
    while(b>0)
    {
        if(b%2==1)
        ans = ans*a % mod;
        a = a*a % mod;
        b = b/2;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,x,i,j;
    cin >> n >> m;
    multiset<int> price;
    f(i,0,n){
        cin >> x;
        price.insert(x);
    }
    f(i,0,m){
        cin >> x;
        auto it = price.upper_bound(x);
        if(it==price.begin()){
            cout << "-1\n";
        }
        else{
            it--;
            cout << *(it) << "\n";
            price.erase(it);
        }
    }
}
    
