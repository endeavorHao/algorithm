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
	int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    sort(all(a));
    int ans = 0;
    for(int i = 0, j = 0, k = 0; i < n; i ++ ){
        while(j < n && a[j] - a[i] < c) j ++;
        while(k < n && a[k] - a[i] <= c) k ++;
        if(a[j] - a[i] == c) ans += k - j;
    }
    cout << ans << endl;
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