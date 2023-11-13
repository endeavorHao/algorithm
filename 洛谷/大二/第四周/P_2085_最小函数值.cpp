#include <bits/stdc++.h>
#define x first
#define y second
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
	int n, m;
    cin >> n >> m;
    vector<array<int, 3>> g(n);
    for(int i = 0; i < n; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        g[i] = {a, b, c};
    }
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(int i = 0; i < n; i ++ ) {
        auto [a, b, c] = g[i];
        heap.push({a + b + c, i});
    }
    vector<int> now(n, 1);
    for(int i = 0; i < m; i ++ ) {
        auto [x, y] = heap.top();
        heap.pop();
        cout << x << ' ';
        auto [a, b, c] = g[y];
        now[y] ++;
        heap.push({a * now[y] * now[y] + b * now[y] + c, y});
    }
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