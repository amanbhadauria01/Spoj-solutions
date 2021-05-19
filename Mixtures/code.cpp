#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e12;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 10;
int a[101],n;   
pair<int,int> dp[101][101];

pair<int,int> rec(int i , int j){
    if(i>j)return {inf,-1};
    if(i==j)return {0,a[i]};
    pair<int,int> & ans = dp[i][j];
    if(ans.fi != -1)return ans;
    ans = {inf,-1};
    for(int k = i; k <= j-1 ; k++){
        pair<int,int> l = rec(i,k) , r = rec(k+1,j);
        int cur = l.fi+r.fi+l.se*r.se;
        if(cur<ans.fi){
            ans.fi = cur;
            ans.se = (((l.se+r.se)%100)+100)%100;
        }
    }
    return ans;
}

void solve(){
    for(int i = 0 ; i < n ; i++)cin >> a[i];
    for(int i = 0 ; i < n ; i++)
      for(int j = 0 ; j < n ; j++)
         dp[i][j] = {-1,-1};
    cout << rec(0,n-1).fi << endl;
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(cin >> n){
            solve();
        }

}