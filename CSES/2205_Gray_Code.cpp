// https://cses.fi/problemset/task/2205/

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

vector<string> generate(int n){
    if(n==1)return {"0","1"};
    vector<string> temp = generate(n-1);
    vector<string> ans;
    for(int i=0; i<temp.size(); i++){
        ans.pb("0"+temp[i]);
    }
    for(int i=temp.size()-1; i>=0; i--){
        ans.pb("1"+temp[i]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> ans = generate(n);
    for(auto s: ans){
        cout << s << "\n";
    }
}
    
