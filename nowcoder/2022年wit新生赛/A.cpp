#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m, k;
int dist[N];
int ans;
void solve(){
	cin >> n >> m;
	cout << (n + 1) * n / 2 << endl;
	for(int i = 1; i <= n; i ++ ) cout << i << ' ';
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