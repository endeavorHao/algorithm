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
	int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int t = n / 2;
    x1 = min(x1, n + 1 - x1);
    y1 = min(y1, n + 1 - y1);
    x2 = min(x2, n + 1 - x2);
    y2 = min(y2, n + 1 - y2);
    x1 = min(x1, y1), x2 = min(x2, y2);
    cout << abs(x1 - x2) << endl;

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