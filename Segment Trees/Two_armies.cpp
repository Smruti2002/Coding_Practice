// https://www.codechef.com/problems/TWOARM/

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

void update(ll tr[],ll id, ll l, ll r, ll lq , ll rq, ll val)
{
    if(l>rq || r<lq) return;
    if(lq<=l && r<=rq)
    {
        tr[id]+=val;
        return;
    }
    ll mid = (l+r)/2;
    update(tr,2*id,l,mid,lq,rq,val);
    update(tr,2*id+1,mid+1,r,lq,rq,val);
}

ll query(ll tr[], ll id, ll l, ll r, ll pos)
{
    if(l>pos || r<pos) return 0;
    if(l==r)
    {
        return tr[id];
    }
    ll mid = (l+r)/2;
    return tr[id] + query(tr,2*id,l,mid,pos) + query(tr,2*id+1,mid+1,r,pos);
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,m,q,i,j;
    cin >> n >> m >> q;
    vector<ll> k1(n),k2(m);
    f(i,0,n)
        cin >> k1[i];
    f(i,0,m)
        cin >> k2[i];
    ll tr1[800001],tr2[800001];
    memset(tr1,0,sizeof(tr1));
    memset(tr2,0,sizeof(tr2));
    while(q--)
    {
        ll ai,bi,ci,di,k,pos;
        cin >> ai >> bi >> ci >> di >> k >> pos;
        ai--;bi--;ci--;di--;
        if(k==1)
        {
            update(tr1,1,0,n-1,ai,bi,1);
            update(tr2,1,0,m-1,ci,di,-1);
            pos--;
            cout << k1[pos]*(1+query(tr1,1,0,n-1,pos)) << "\n";
        }
        else
        {
            update(tr1,1,0,n-1,ai,bi,-1);
            update(tr2,1,0,m-1,ci,di,1);
            pos--;
            cout << k2[pos]*(1+query(tr2,1,0,m-1,pos)) << "\n";
        }
    }
}
