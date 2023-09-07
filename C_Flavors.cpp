#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int d1[N], d2[N];
void solve(){
	int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ){
        int f, s;
        cin >> f >> s;
        if(s >= d1[f]) d2[f] = d1[f], d1[f] = s;
        else if(s >= d2[f]) d2[f] = s;
    }
    int ans = 0;
    // 用不同的口味
    vector<int> a;
    for(int i = 1; i <= n; i ++ ){
        a.push_back(d1[i]);
    }
    sort(all(a));
    ans = a[n - 1] + a[n - 2];
    // 用相同口味
    for(int i = 1; i <= n; i ++ ){
        ans = max(ans, d1[i] + d2[i] / 2);
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