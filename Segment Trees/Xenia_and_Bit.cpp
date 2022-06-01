// https://codeforces.com/contest/339/problem/D

#include <bits/stdc++.h>
using namespace std;
 
#define ld long double
#define ll long long 
#define ull unsigned long long int
#define uld unsigned long double
#define pb push_back
#define mk make_pair
#define lb(arr,key) lower_bound(arr.begin(),arr.end(),key)
#define ub(arr,key) upper_bound(arr.begin(),arr.end(),key)
#define f(i,k,n) for(i=k; i<n; i++)
#define all(v) v.begin(),v.end()
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr.rbegin(),arr.rend())
#define google(res) cout << "Case #" << t1 << ": " << res << "\n"
#define pi 3.1415926535
#define flush cout.flush()
  
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
 
ll digit_count(ll n)
{
    ll cnt = 0;
    ll m = n;
    while(m>0)
    {
        cnt++;
        m/=10;
    }
    return cnt;
}
 
ll mod(ll a , ll p)
{
    ll res = a%p;
    if(res>=0)
        return res;
    return res+p;
}
 
ll exp(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y % 2 == 1)
            res = (res * x);
        y = y/2;
        x = (x * x);
    }
    return res;
}



// ********************* Real Code begins here ******************************** //

ll N = 1+(1<<19);
vector<ll> v;
vector<ll> tr(N);

void build (ll index, ll l, ll r, ll n)
{
    if(l==r){
        tr[index] = v[l];
        return;
    }
    ll k = floor(log2(index));
    ll mid= (l+r)/2;
    build(2*index,l,mid,n);
    build(2*index+1,mid+1,r,n);
    if((n-k)%2==1)
        tr[index] = tr[2*index]|tr[2*index+1];
    else
        tr[index] = tr[2*index]^tr[2*index+1];
}

void update(ll index, ll l, ll r,ll n, ll pos, ll val)
{
    if(pos<l || pos>r) return;
    if(l==r){
        tr[index] = val;
        v[l] = val;
        return;
    }
    ll mid = (l+r)/2;
    update(2*index,l,mid,n,pos,val);
    update(2*index+1,mid+1,r,n,pos,val);
    ll k = floor(log2(index));
    if((n-k)%2==1)
        tr[index] = tr[2*index]|tr[2*index+1];
    else
        tr[index] = tr[2*index]^tr[2*index+1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,t,i,j,k,p,b;
    cin >> n >> m;
    k = exp(2,n);
    v.resize(k+1);
    f(i,1,k+1)
    {
        cin >> v[i];
    }
    build(1,1,k,n);
    while(m--)
    {
        cin >> p >> b;
        update(1,1,k,n,p,b);
        cout << tr[1] << "\n";
    }
}
