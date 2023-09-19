#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int a, b, l, r;
    cin >> a >> b >> l >> r;
    b -= a;
    int x = ceil((b) * 1.0 / r);
    int y = floor((b) * 1.0 / l);
    if(x > y) cout << -1 << endl;
    else cout << x << ' ' << y << endl;
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