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
        ans = ans*a % (mod);
        a = a*a % (mod);
        b = b/2;
    }
    return ans;
}

// https://cses.fi/problemset/task/1072/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,j;
    cin >> n;
    if(n<4){
        if(n==1){
            cout << "0\n";
        }
        else if(n==2){
            cout << "0\n";
            cout << "6\n";
        }
        else{
            cout << "0\n";
            cout << "6\n";
            cout << "28\n";
        }
    }
    else{
        cout << "0\n";
        cout << "6\n";
        cout << "28\n";
        cout << "96\n";
        ll t1 = 24;
        f(i,5,n+1){
            t1 = t1 + 8*(i-2);
            ll ans = i*i*(i*i-1)/2 - t1;
            cout << ans << "\n";
        }
    }
}
    
