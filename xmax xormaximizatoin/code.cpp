#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e12+10;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int N = 1e5+10;
int arr[N];
vector<int> a[100];

int length(int x){
    int j = 0;
    while(x>0){
        x/=2;
        j++;
    }
    return j;
}


void solve(){
    int n ; cin >> n ; 
    for(int i = 0 ; i < n ; i++)cin >> arr[i];
    for(int i= 0 ; i < 70 ; i++)a[i].clear();
    for(int i = 0 ; i < n ; i++){
        int x = arr[i];
        int j = length(x);
        a[j].push_back(arr[i]);
    }
    int modifiedarr[100],idx = 0;
    for(int i = 64 ; i > 0 ; i--){
        if(a[i].size()){
            modifiedarr[idx++] = a[i][0];
            for(int j = 1 ; j < (int)a[i].size() ; j++){
                int temp = a[i][0]^a[i][j];
                int len = length(temp);
                a[len].push_back(temp);
            }
        }
    }
    int ans = 0 ;
    for(int i = 0 ; i < idx ; i++){
        if(ans < (ans^modifiedarr[i])){
            ans = (ans^modifiedarr[i]);
        }
    }
    cout << ans;
}         

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}