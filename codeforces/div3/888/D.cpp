#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
void solve(){
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	map<int, int> vis;
	int res = 0;
	for (int i = 1; i < n; i++) {
		int d = a[i] - a[i - 1];
		if (vis[d]) res = d;
		else vis.erase(d);
		if (d > n) res = d;
		else vis[d]++;
	}
	if (res == 0) {
		cout << "Yes" << endl;
		return;
	}
	if (vis.size() != n - 2) {
		cout << "No" << endl;
		return;
	}
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && !a) a = i;
		else if (!vis[i]) b = i;
	}
	if (a + b == res) cout << "Yes" << endl;
	else cout << "No" << endl;
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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}