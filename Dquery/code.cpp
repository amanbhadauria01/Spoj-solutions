#include <bits/stdc++.h>
using namespace std;
const long long MOD //= 998244353; 
               = 1e9 + 7;
typedef long long ll;
// #define INF 1e18 + 0
#define fi first
#define se second
#define pb push_back
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const ll N = 4e6 + 10;
const ll INF = 1e18 + 0;
typedef long double D;
int A[N],rev[N],cnt[N];
class query{
    public :
    ll idx,l,r,lb,rb;
};
query q[N];
int compressed_val;
int ans[N],curr_ans;

void add_element(int x){
    if(++cnt[A[x]] == 1) curr_ans++;
}
void remove_element(int x){
    if(--cnt[A[x]] == 0) curr_ans--;
}

bool cmp(query a, query b){
    return (a.lb < b.lb) || (a.lb == b.lb && a.r < b.r); 
}


void go(){ 
   int n ; cin >> n;
   int block = max(1,int(pow(n, 1.0/2.0)));
   map<int,int> mp;
   for(int i = 1 ; i <= n ; i++){
       cin >> A[i];
       mp[A[i]];
   }
   int m ; 
   cin >> m ;
   for(int i = 1 ; i <= m ; i++){
       int x, y ; 
       cin >> x >> y ;
       q[i] = {i , x, y , x / block , y / block };
   } 
   // coordinate compression
   for(auto &it : mp){
       it.second = ++compressed_val;
       rev[compressed_val] = it.first;
   }
   for(int i = 1; i <= n ; i++){
       A[i] = mp[A[i]];
   }
   sort(q+1,q+m+1,cmp);

   for(int i = 1 , L = 1, R = 0; i <= m ; i++){
       while(R < q[i].r)add_element(++R);
       while(L > q[i].l)add_element(--L);
       while(R > q[i].r)remove_element(R--);
       while(L < q[i].l)remove_element(L++);
       ans[q[i].idx] = curr_ans;
   }
   for(int i = 1 ; i <= m ; i++){
       cout << ans[i] << endl;
   }
}

int main() {
        NeedForSpeed
        int t = 1;
        // cout << fixed << setprecision(9) ;
        // cin >> t;
        while(t--){
            go();
        }

}


   	 			 		   	 		 						 	  		