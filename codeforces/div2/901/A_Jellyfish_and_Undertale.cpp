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
	int a, b, n;
    cin >> a >> b >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i ++ ) cin >> c[i], c[i] = min(c[i], a - 1ll);
    int sum = 0;
    for(int i = 0; i < n; i ++ ) sum += c[i];
    cout << sum + b << endl;
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