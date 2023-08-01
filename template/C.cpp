#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int mod = 2333;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    vector<vector<int>> f(n, vector<int>(m, 0));
    for(int i = 0; i < n; i ++ )
      for(int j = 0; j < m; j ++ ) cin >> g[i][j];
    f[n-1][0] = 1;
    for(int i = n - 1; i >= 0; i -- )
      for(int j = 0; j < m; j ++ ){
        if(!g[i][j]){
          if(i + 1 < n) f[i][j] = f[i + 1][j] % mod;
          if(j - 1 >= 0) f[i][j] = (f[i][j] + f[i][j - 1]) % mod; 
          cout << f[i][j] << endl;
        }
      }
      cout << f[0][m - 1] << endl;
}
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T -- ){
      solve();
    }
    return 0;
}