#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
#define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
// random_device rd;
// mt19937 rng(rd());
// int getRand(int l,int r){ // get random number in the range [l,r]
//   uniform_int_distribution<int> uid(l,r);
//   return uid(rng);
// }
const int N = 1e5 + 10;
int n , m ;
vector<int> graph[N] ; 
// low[u] stores the low time which can be reached from vertex u
// disc[u] stores discovery time of u
// par[u] stores par of u
// child[u] stores no of child of u 
// here we are making a dfs tree
int low[N] , disc[N] , par[N] , child[N];
bool vis[N] ;
int tim = 0 ;
bool ap[N];

void init(int n){
	tim = 0 ; 
	for(int i = 0 ; i <= n ; i++)
	 par[i] = -1 , 
	 vis[i] = 0  , 
	 graph[i].clear() ,
	 ap[i] = 0 , 
	 child[i] = 0;
}

void dfs(int u , int p){
	par[u] = p;
	vis[u] = 1;
	disc[u] = low[u] = ++tim;
	for(auto v : graph[u]){
		if(!vis[v]){
			// make v child of u 
			child[u]++;
			dfs(v,u);
			// 
			low[u] = min(low[u],low[v]);
			// u is articulation point if
			// 1. low[v] >= low[u] (means no other vertex of subtree v can connect to u or above)
			if(par[u] != -1 && low[v]>=disc[u])ap[u] = 1;
            // 2. u is par of dfs tree and there are more than one child of u 
			// as in this case of a child of u connects other child of u 
			// it have to be in same subtree and hence it will be same child
			if(par[u] == -1 && child[u]>1)ap[u] = 1;
		}else if(v!=par[u]){ 
			   // in this case v is already visited and hence is above u in the dfs tree
		       // so we can only update the low[u] here 
               low[u] = min(disc[v],low[u]);
		}
	}
}

void go(){
    cin >> n >> m;
	if(n==0 && m==0)return ;
	init(n);
	for(int i = 0 ; i < m ; i++){
		int x , y ; cin >> x >> y ;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i = 1 ; i <= n ; i++){
		if(!vis[i])dfs(i,-1);
	}
	int cnt = 0 ;
	for(int i = 1 ; i <= n ; i++)cnt += ap[i] ; 
	cout << cnt << endl;
	go();
} 

signed main() {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(12) ;
        // cin >> t;
        while(t--){
            // cout << "Case #" << cases << ": ";
            go();
        }

}