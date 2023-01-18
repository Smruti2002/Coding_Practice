// https://cses.fi/problemset/task/1092/

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

void printt(vector<int> arr){
    cout << arr.size() << "\n";
    for(int i=0; i<arr.size(); i++)cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i;
    vector<int> arr1,arr2;
    cin >> n;
    if(n%4==3){
        arr1.pb(1);
        arr1.pb(2);
        arr2.pb(3);
        i=4;
        while(i<=n){
            arr1.pb(i++);
            arr2.pb(i++);
            arr2.pb(i++);
            arr1.pb(i++);
        }
        cout << "YES\n";
        printt(arr1);
        printt(arr2);
    }
    else if(n%4==0){
        arr1.pb(1);
        arr1.pb(4);
        arr2.pb(2);
        arr2.pb(3);
        i = 5;
        while(i<=n){
            arr1.pb(i++);
            arr2.pb(i++);
            arr2.pb(i++);
            arr1.pb(i++);
        }
        cout << "YES\n";
        printt(arr1);
        printt(arr2);
    }
    else{
        cout << "NO\n";
    }
}
    
