#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 5010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
char g[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void solve(){
	cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> g[i] + 1;
    int ans = 0;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            if(g[i][j] == '0'){
                int cnt = 0;
                for(int k = 0; k < 4; k ++ ){
                    int a = i + dx[k], b = j + dy[k];
                    if(a <= 0 || a > n || b <= 0 || b > m) continue;
                    if(g[a][b] == '2') {cnt = 0; break;}
                    if(g[a][b] == '1') cnt ++;
                }
                if(cnt == 3) ans ++;
            }
        }
    }
    if(ans){
        cout << "YES" << endl;
        cout << ans << endl;
    }else cout << "NO" << endl;
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