#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
ll mover[8][2] = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool done[1001][1001][10];
#define f first
#define s second
ll n,m;

bool inside(ll x, ll y){
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void go()
{
   
   cin >> n >> m;
   vector<string> graph;
   pair<ll,ll> start, fin;
   ll moves[1001][1001];
   for(int i = 0 ; i < 1001; i++){
       for(int j = 0 ; j < 1001 ; j++){
          moves[i][j] = INT_MAX;
       }
   }
   memset(done,false,sizeof(done));
   for(int i = 0 ; i < n ; i++){
       string s;
       cin >> s;
       graph.push_back(s);
   }
   for(int i = 0 ;i < n ; i++){
       for(int j = 0 ; j < m ; j++){
           if(graph[i][j] == 'S'){
               start.first = i ;
               start.second = j;
           }
           if(graph[i][j] == 'F'){
               fin.first = i;
               fin.second = j;
           }
       }
   }
   
   // bfs starts
   graph[fin.f][fin.s] = '.';
   queue<pair<int,pair<int,int> >> q;
   q.push({0,{start.f,start.s}});
   for(int i = 0 ; i < 8 ; i++)
   done[start.f][start.s][i] = true;
   moves[start.f][start.s] = 0;
   while(q.empty()==false){
       ll x = q.front().s.f;
       ll y = q.front().s.s;
       ll c = q.front().f;
       q.pop();
      if(c > moves[x][y]) continue;
       if(x == fin.f && y == fin.s){
           cout << c << endl;
           return;
       }
       for(int i = 0 ; i < 8 ; i++){
           ll fact = 1;
           while(1){
             ll nx = x + mover[i][0]*fact;
             ll ny = y + mover[i][1]*fact;
             if(nx < 0 || ny < 0 || nx >= n || ny >= m) break;
             if(fin.f == nx && fin.s == ny){
                 cout << c+1 << endl;
                 return;
             }
             if(done[nx][ny][i] || graph[nx][ny] =='X')break;
             done[nx][ny][i] = true;
             if(moves[nx][ny] > c+1 ){
                 moves[nx][ny] = c+1;
                 q.push({moves[nx][ny],{nx,ny}});
             }
             fact++;
           }
           
       }
   }

  if(moves[fin.f][fin.s] == INT_MAX) cout << -1 << endl;
  else  cout << moves[fin.f][fin.s] << endl;
}


int main()
{
    NeedForSpeed 

    int t = 1;
    cin >> t;
    while (t--)
        go();
}
