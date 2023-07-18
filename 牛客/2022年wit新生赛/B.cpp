#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 3010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m, k;
int ans;
int f[N][N][6];
int score[N][6];
int drow[N];
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
		cin >> drow[i];
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= 4; j ++ ) cin >> score[i][j];
	for(int i = 1; i <= n; i ++ ){
		for(int j = 0; j <= m; j ++ ){
			for(int k = 1; k <= 4; k ++ ){	
                f[i][j][k] = max(f[i][j][k], f[i-1][j][k]);
				for(int l = 1; l <= k; l ++ )
					if(j >= drow[i]){
						f[i][j][k] = max(f[i][j][k], f[i-1][j - drow[i]][l] + score[i][k]);
			
				}
			}
		}
	}
    int ans = 0;
	for(int i = 1; i <= 4; i ++ ) ans = max(ans, f[n][m][i]);
	cout << ans << endl;
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
	//cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}