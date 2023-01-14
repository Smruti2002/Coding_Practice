// https://cses.fi/problemset/task/1071

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

void helper(int n){
    for(int i=n; i>=1; i-=2){
        cout << i << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t,x,y;
    cin >> t;
    while(t--){
        cin >> x >> y;
        ll diag = y*y - y + 1;
        if(x==y){
            cout << diag << '\n';
        }
        else if(y>x){
            if(y%2){
                cout << diag + y-x << "\n";
            } 
            else{
                cout << diag - (y-x) << "\n";
            }
        }
        else{
            diag = x*x - x + 1;
            if(x%2){
                cout << diag - (x-y) << "\n";
            }
            else{
                cout << diag + x-y << "\n";
            }
        }
    }
}
    
