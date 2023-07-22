#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 15, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
char g[N][N];
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ){
		for(int i = 1; i <= 8; i ++ ) cin >> g[i] + 1;
		int x = 0, y = 0;
		for(int i = 1; i <= 8; i ++ ){
			for(int j = 1; j <= 8; j ++ ){
				if(g[i][j] != '.'){
					x = i, y = j;
					break;
				}
			}
			if(x || y) break;
		}
		for(int i = x; i <= 8; i ++ ){
			if(g[i][y] != '.') cout << g[i][y];
		}
		if(T) cout << endl;
	}
	return 0;
}