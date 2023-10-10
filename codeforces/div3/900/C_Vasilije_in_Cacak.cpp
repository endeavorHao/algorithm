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
	int n, k, x;
    cin >> n >> k >> x;
    int minv = (1 + k) * k / 2;
    int maxv = (n * 2 - k + 1) * k / 2;
    if(x >= minv && x <= maxv) cout << "YES" << endl;
    else cout << "NO" << endl;
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