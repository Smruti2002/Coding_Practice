#include <bits/stdc++.h>
using namespace std;
 
#define ld long double
#define ll long long 
#define ull unsigned long long int
#define uld unsigned long double
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define lb(arr,key) lower_bound(arr.begin(),arr.end(),key)
#define ub(arr,key) upper_bound(arr.begin(),arr.end(),key)
#define f(i,k,n) for(i=k; i<n; i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define google(res) cout << "Case #" << t1 << ": " << res << "\n"
#define pi 3.1415926535
#define flush cout.flush()
#define ff first
#define ss second
#define mod 1000000007
#define ii pair<int,int>
#define precise(n) fixed << setprecision(n) 
 
ll gcd (ll a , ll b)
{
    // O(logN)
    if(a==0 || b==0)
        return a^b;
    return __gcd(a,b);
}
 
ll lcm (ll a , ll b)
{
    // O(logN)
    return a*b/gcd(a,b);
}
 
ll exp(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y % 2 == 1)
            res = (res * x)%mod;
        y = y/2;
        x = (x * x)%mod;
    }
    return res%mod;
}
 
 
// ********************* Real Code begins here ******************************** //
 
 
int LOG = 18;
vector<vector<ll>> m;
 
void build(vector<ll> &v){
    int n = v.size();
    int i,j;
    f(i,0,n){
        m[i][0] = v[i];
    }
    for(j=1; j<LOG; j++){
        for(i=0; i+(1<<(j-1)) < n; i++){
            m[i][j] = min(m[i][j-1],m[i+(1<<(j-1))][j-1]);
        }
    }
}
 
ll query(int a, int b){
    int x = min(a,b);
    int y = max(a,b);
    int len = y-x+1;
    int k = 31-__builtin_clz(len);
    return min(m[x][k],m[y+1-(1<<k)][k]);
}
 
void solve(){
    int i,j,k,n,q;
    cin >> n >> q;
    vector<ll> v(n);
    f(i,0,n)
        cin >> v[i];
    m.clear();
    m.resize(n,vector<ll> (LOG));
    build(v);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout << query(a-1,b-1) << "\n";
    }
}
 
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // ll t;
    // cin >> t;
    // for(ll t1=1; t1<=t; t1++)
        solve();
}