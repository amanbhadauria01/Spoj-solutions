#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define MOD 1000000007
// #define f first
#define se second
#define inf 1e9 
const int N = 1e6+5;
// random_device rd;
// mt19937 rng(rd());
// int getRand(int l,int r){ // get random number in the range [l,r]
//   uniform_int_distribution<int> uid(l,r);
//   return uid(rng);
// }
int seg[N],a[N],lazy[N];

void build(int low , int high , int node){
  if(low == high){
    seg[node] = a[low];
    return;
  }
  int mid = (low + high) / 2;
  build(low,mid,2*node+1);
  build(mid+1,high,2*node+2);
  seg[node] = seg[2*node+1] + seg[2*node+2];
}

int query(int low, int high , int node, int l , int r){
  if(lazy[node]!=0){
    seg[node] += (high-low+1)*lazy[node];
    if(low != high){
      lazy[2*node+1] += lazy[node];
      lazy[2*node+2] += lazy[node]; 
    }
    lazy[node] = 0;
  }
  if( high < l || low > r || low > high)return 0;
  if( l <= low && high <= r) return seg[node];
  int mid = (low + high)/ 2;
  int left = query(low,mid,2*node+1,l,r);
  int right = query(mid+1,high,2*node+2,l,r);
  return left + right;
}

void update(int low , int high , int node , int l , int r, int val){
  if(lazy[node]!=0){
    seg[node] += (high-low+1)*lazy[node];
    if(low != high){
      lazy[2*node+1]+=lazy[node];
      lazy[2*node+2]+=lazy[node];
    }
    lazy[node] = 0;
  }
  if( high < l || low > r || low > high)return;
  if( l <= low && high <= r){
    seg[node] += (high-low+1)*val;
    if(low!=high){
      lazy[2*node+1] += val;
      lazy[2*node+2] += val; 
    }
    return;
  }
  int mid = (low + high) /2 ;
  update(low,mid,2*node+1,l,r,val);
  update(mid+1,high,2*node+2,l,r,val);
  seg[node] = seg[2*node+1] + seg[2*node+2];
}


void print(int n){
  for(int i = 0 ; i < n ; i++) cout << query(0,n-1,0,i,i) << " " ; cout << endl;
}

void go(){
  int n, c ; cin >> n >> c;
  for(int i = 0 ; i < n ; i++){
      a[i] = 0;
  }
  for(int i = 0 ; i <= 4*n ; i++) seg[i] = 0,lazy[i] = 0;
  // build(0,n-1,0);
  for(int i = 0 ;i < c ; i++){
    int ch ; cin >> ch ;
    if(ch==0){
       int l,r,v;cin >> l>> r >> v; l--; r--;
       update(0,n-1,0,l,r,v);
    }else{
      int l,r; cin >> l >> r; l--; r--;
      cout << query(0,n-1,0,l,r) << endl;
    }
    // print(n);
  }
}  



signed main() {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(12) ;
        cin >> t;
        while(t--){
            go();
        }

}