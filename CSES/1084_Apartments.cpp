// https://cses.fi/problemset/task/1084/

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

    int n,m,k,i,j;
    cin >> n >> m >> k;
    vector<int> stud(n);
    vector<int> apart(m);
    f(i,0,n)cin >> stud[i];
    f(i,0,m)cin >> apart[i];
    sort(all(stud));
    sort(all(apart));
    i=0,j=0;
    int ans = 0;
    f(i,0,n){
        while(j<m){
            if(stud[i]-k <= apart[j] && apart[j]<= stud[i]+k){
                ans++;
                // cout << i << " : " << j << "\n";
                j++;

                break;
            }
            else if(apart[j]< stud[i]-k){
                j++;
            }
            else{
                break;
            }
        }
    }
    cout << ans;
}
    
