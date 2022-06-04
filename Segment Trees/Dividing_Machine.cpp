// https://www.codechef.com/problems/DIVMAC

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
// #define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr.rbegin(),arr.rend())
#define google(res) cout << "Case #" << t1 << ": " << res << "\n"
#define pi 3.1415926535
#define flush cout.flush()

// ********************* Real Code begins here ******************************** //

ll lprime[1000001];

void precompute()
{
    for(int i = 1; i<=1000000; i++)
        lprime[i] = 0;
    ll i;
    ll N = 1000000;
    lprime[1] = 1;
    f(i,2,N+1)
    {
        if(lprime[i]==0)
        {
            lprime[i] = i;
            for(ll j = i*i; j<=N; j=j+i)
            {
                if(lprime[j]==0)
                    lprime[j] = i;
            }  
        }
    }
}

ll tr[400040];
vector<ll> arr;

void build(ll index, ll l, ll r)
{
    if(l==r)
    {
        tr[index] = lprime[arr[l]];
        return;
    }
    ll mid = (l+r)/2;
    build(2*index,l,mid);
    build(2*index+1,mid+1,r);
    tr[index] = max(lprime[tr[2*index]],lprime[tr[2*index+1]]);
}

void update(ll index, ll l, ll r, ll lq, ll rq)
{
    if(r<lq || l>rq)
        return;
    if(tr[index]==1)
    {
        return;
    }
    if(l==r)
    {
        arr[l] = arr[l]/lprime[arr[l]];
        tr[index] = lprime[arr[l]];
        return;
    }
    ll mid = (l+r)/2;
    update(2*index,l,mid,lq,rq);
    update(2*index+1,mid+1,r,lq,rq);
    tr[index] = max(tr[2*index],tr[2*index+1]);
}

ll query(ll index, ll l, ll r, ll lq, ll rq)
{
    if(lq>r || rq<l)
        return 1;
    if(lq<=l && r<=rq)
        return tr[index];
    ll mid = (l+r)/2;
    ll t1 = query(index*2,l,mid,lq,rq);
    ll t2 = query(index*2+1,mid+1,r,lq,rq);
    return max(t1,t2);
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    precompute();
    ll t,n,m,i,j,k;
    ll a,b,c;
    cin >> t;
    while(t--)
    {
        memset(tr,0,sizeof(tr));
        cin >> n >> m;
        vector<ll> v(n);
        f(i,0,n)
            cin >> v[i];
        arr = v;
        build(1,0,n-1);
        f(i,0,m)
        {
            cin >> a >> b >> c;
            if(a==0)
                update(1,0,n-1,b-1,c-1);
            else
            {
                cout << query(1,0,n-1,b-1,c-1) << " ";
            }
        }
        cout << "\n";
    }
}
