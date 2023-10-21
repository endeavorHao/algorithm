#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int prime[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
int maxv, number;
int n;
void dfs(int u, int last, int p, int s) {
	if(s > maxv || s == maxv && p < number) {
		maxv = s, number = p;
	}
	if(u == 9) return;
	for(int i = 1; i <= last; i ++ ) {
		if(p * prime[u] > n) break;
		p *= prime[u];
		dfs(u + 1, i, p, s * (1 + i));
	}
}

void solve(){
	cin >> n;
	dfs(0, 30, 1, 1);
	cout << number << " " << maxv << endl;
}
signed main() {
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