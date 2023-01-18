// https://cses.fi/problemset/task/1754/

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,i;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if(a==b){
            if(a%3==0)cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            if(a<b){
                int t = a;
                a = b;
                b = t;
            }
            int diff = a-b;
            a = a - 2*diff;
            b = b - diff;
            if(a>=0 && b>=0){
                if(a%3==0)cout << "YES\n";
                else cout << "NO\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}
    
