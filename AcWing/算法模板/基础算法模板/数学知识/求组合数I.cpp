#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1e9 + 7;
typedef pair<int, int> PII;
int n, m;
int a[N];
int f[N][N];
void init(){
	for(int i = 0; i < N; i ++ )
		for(int j = 0; j <= i; j ++ )
		if(!j) f[i][j] = 1;
		else f[i][j] = (f[i-1][j] + f[i-1][j-1]) % mod;
}
void solve(){
	cin >> n >> m;
	cout << f[n][m] << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}