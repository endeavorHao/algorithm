#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void solve(){
	int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ) cin >> g[i][j];
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            if(g[i][j] == '*'){
                for(int z = 0; z < 8; z ++ ){
                    if(i + dx[z] < 0 || i + dx[z] >= n || j + dy[z] < 0 || j + dy[z] >= m) continue;
                    vis[i + dx[z]][j + dy[z]] = true;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            if(g[i][j] == 'P' && !vis[i][j]) ans ++;
        }
    }
    cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}