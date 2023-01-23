// https://cses.fi/problemset/task/1624/

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

map<int,int> ld,rd,col;

bool isSafe(int r, int c, vector<string> &chess){
    if(ld[r+c]==0 && rd[r-c]==0 && col[c]==0 && chess[r][c]=='.')return 1;
    return 0;
}

ll ans = 0;

void rec(int r, int queens, vector<string> &chess){
    if(queens==0){
        ans++;
        return ;
    }
    if(r>=8)return ;
    int tmp = 0;
    for(int i=0; i<8; i++){
        if(isSafe(r,i,chess)){
            ld[r+i]=1;
            rd[r-i]=1;
            col[i]=1;
            rec(r+1,queens-1,chess);
            ld[r+i] = 0;
            rd[r-i] = 0;
            col[i]  = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> chess(8);
    for(int i=0; i<8; i++)cin >> chess[i];
    rec(0,8,chess);
    cout << ans << "\n";
}
    
