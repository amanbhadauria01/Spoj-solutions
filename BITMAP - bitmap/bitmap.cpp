#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
ll n,m;
ll dist[200][200];
ll mover[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

void go()
{
  for(int i = 0 ; i < 200; i++){
      for(int j = 0 ; j < 200 ; j++){
          dist[i][j] = INT_MAX;
      }
  }
  cin >> n >> m;
  queue<pair<int,pair<int,int>>> q;
  for(int i = 0 ; i < n ; i++){
      string s;
      cin >> s;
      for(int j = 0 ; j < s.size() ; j++){
          if(s[j]=='1'){
               q.push({0,{i,j}});
               dist[i][j] = 0;
          }
      }
  }
  while(!q.empty()){
      int x = q.front().second.first;
      int y = q.front().second.second;
      int d = q.front().first;
      q.pop();
      for(int i = 0 ; i < 4 ; i++ ){
          int X = x+ mover[i][0];
          int Y = y+ mover[i][1];
          if(X<0 || X >= n || Y < 0 || Y >= m) continue;
          if(dist[X][Y] > dist[x][y]+1 ){
              dist[X][Y] = dist[x][y] + 1;
              q.push({dist[X][Y],{X,Y}});
          }
      }
  }
  for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
          cout << dist[i][j] << " ";
      }
      cout << endl;
  }
}

int main()
{
    NeedForSpeed int t = 1;
    cin >> t;
    while (t--)
        go();
}