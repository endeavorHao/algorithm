#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    cin >> n >> m;
    int p[1010];
    p[1] = 1;
    for(int i = 2; i < 1010; i ++ ) p[i] = (p[i - 1] * 2 + 2) % mod;
    while(m -- ){
        int x, y;
        cin >> x >> y;
        int sum = 0;
        for(int i = x; i <= y; i ++ ) sum = (sum + p[i]) % mod;
        cout << sum << endl;
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