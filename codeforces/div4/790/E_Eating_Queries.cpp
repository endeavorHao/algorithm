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
	int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    sort(all(a), greater<int>());
    vector<int> s(n + 1);
    for(int i = 0; i < n; i ++ ) s[i + 1] = s[i] + a[i];
    while(q -- ){
        int x;
        cin >> x;
        int t = lower_bound(all(s), x) - s.begin();
        if(s[n] < x) cout << -1 << endl;
        else cout << t << endl;
    }
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