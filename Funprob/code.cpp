#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const ll N = 400100;
D m , n;
void go()
{  
    if(n > m) {cout << 0.0 << endl; return;}
    else {
        cout << (m+1-n)/(m+1) << endl;
    }
}


int main()
{
    NeedForSpeed 

    ll t = 1;
    // cin >> t;
    cout << fixed << setprecision(6) ;
    while (1){
        cin >> n >> m;
        if( ((int)m == 0) && ((int)n == 0)) break;
        go();
    }    
}   