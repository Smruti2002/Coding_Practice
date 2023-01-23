// https://cses.fi/problemset/task/1622/

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

int fact(int n){
    if(n==0 || n==1)return 1;
    return n*fact(n-1);
}

void rec(vector<int> freq, string s, int n){
    if(s.length()==n){
        cout << s << "\n";
        return;
    }
    for(int i=0; i<26; i++){
        if(freq[i]>0){
            freq[i]--;
            s += (char)(i+'a');
            rec(freq,s,n);
            s.pop_back();
            freq[i]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int ans = 0;
    vector<int> freq(26,0);
    for(int i=0; i<s.length(); i++){
        freq[s[i]-'a']++;
    }
    ans = fact(s.length());
    for(int i=0; i<26; i++){
        ans = ans / fact(freq[i]);
    }
    cout << ans << "\n";
    rec(freq,"",s.length());
}
    
