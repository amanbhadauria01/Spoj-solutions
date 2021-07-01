#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
ll a[100100];
ll n;
ll mover[8][2] = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
class t{
  public :
  ll d ;
  ll x ;
  ll y ;
  ll prev ;
  t(ll d, ll x, ll y ,ll prev){
      x = x;
      y = y;
      prev = prev;
      d = d;
  }
  t(const t & b){
      this->d = b.d;
      this->x = b.x;
      this->y = b.y;
      this->prev = b.prev;
  } 
  bool operator > (const t & b) const{
     if((this->d) > (b.d)){
         return true;
     }return false;
  }
  bool operator  < (const t & b) const{
     if((this->d) < (b.d)){
         return true;
     }return false;
  }
  bool operator = (const t & b) const{
     if((this->d) == (b.d)){
         return true;
     }return false;
  }  
};

void go()
{
   ll n,m;
   cin >> n >> m;
   vector<string> graph;
   pair<ll,ll> start, fin;
   ll moves[1001][1001];
   for(int i = 0 ; i < 1001; i++){
       for(int j = 0 ; j < 1001 ; j++){
          moves[i][j] = INT_MAX;
       }
   }
   priority_queue<t, vector<t> , greater<t> > q;
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
   moves[start.first][start.second] = 0;
   cout << start.first << " " << start.second<< " : " ;
   t obj(0,start.first,start.second,-1);
   q.push(obj);
   while(!q.empty()){
       ll d = q.top().d;
       ll x = q.top().x;
       ll y = q.top().y;
       ll prev = q.top().prev;
       q.pop();
       for(int i = 0 ;i < 8 ; i++){
           ll X  = x+mover[i][0];
           ll Y  = y+mover[i][1];
           if(X < 0 || Y < 0 || X >= n || Y >= m || (graph[X][Y] != '.' && graph[X][Y]!='F')) continue;

           if((prev == i)  && (moves[X][Y] > moves[x][y])){
               moves[X][Y] = moves[x][y];
               t temp(moves[X][Y],X,Y,i); 
               q.push(temp);
           } 
           if((prev != i) &&  (moves[X][Y]  > moves[x][y] + 1)){
               moves[X][Y] = moves[x][y] + 1;
               t temp(moves[X][Y],X,Y,i);
               q.push(temp);
           }
       }
   }
   for(int i = 0 ; i < n ; i++){
       for(int j = 0 ; j < m ; j++){
           cout << moves[i][j] << " ";
       }
       cout << endl;
   }
   
}


int main()
{
    NeedForSpeed 

    int t = 1;
    cin >> t;
    while (t--)
        go();
}
