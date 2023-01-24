// https://cses.fi/problemset/task/2431/

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
        ans = ans*a;
        a = a*a;
        b = b/2;
    }
    return ans;
}

string adder(string a, string b){
    string c(a.length(),'0');
    int carry = 0;
    int diff = a.length()-b.length();
    string temp = "";
    for(int i=1; i<=diff; i++)temp+='0';
    b = temp + b;
    for(int i=a.length()-1; i>=0; i--){
        int ans = carry + a[i]-'0' + b[i] - '0';
        int bit = ans%10;
        carry = ans/10;
        c[i] = (char)(bit+'0');
    }
    if(carry>0){
        c = (char)(carry+'0') + c;
    }
    return c;
}

int helper(int digit, ll left){
   string base = "1";
   for(int i=0; i<digit-1; i++){
        base+='0';
   }
   ll num = (left%digit==0)?left/digit:left/digit+1;
   ll ans = (num-1);
   string c = to_string(ans);
   string s = adder(base,c);
   ll ind = left%digit;
   ind--;
   if(ind < 0 )ind = digit-1;
   // cout << digit << " " << left << " " << num << "\n";
   // cout << s << "\n";
   return s[ind]-'0';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q,i;
    cin >> q;
    vector<ll> digits;
    digits.pb(0);
    i = 1;
    while(digits[i-1]<=1e18){
        digits.pb((digits[i-1] + 9*exp(10,i-1)*i)); 
        i++;
    }
    while(q--){
        ll k;
        cin >> k;
        auto it = lower_bound(all(digits),k);
        int digit = (it)-digits.begin();
        ll left = k - *(--it);
        cout << helper(digit,left) << '\n';
    }
}
    
