// https://cses.fi/problemset/task/1755/

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
 
    string s;
    cin >> s;
    vector<int> freq(26,0);
    int i,odd = 0;
    f(i,0,s.length()){
        freq[s[i]-'A']++;
    }
    f(i,0,26){
        if(freq[i]%2==1){
            odd++;
        }
    }
    if(odd>1){
        cout << "NO SOLUTION\n";
    }
    else{
        int j = -1;
        string r = "";
        f(i,0,26){
            if(freq[i]%2==0){
                for(int k=0; k<freq[i]/2; k++){
                    r += (char)('A'+i);
                }
            }
            else{
                j = i;
            }
        }
        cout << r;
        for(int k=0; k<freq[j]; k++){
            cout << (char)('A'+j);
        }
        reverse(r.begin(),r.end());
        cout << r;
    }
}
