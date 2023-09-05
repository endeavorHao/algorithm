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
	int n = 2;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < n; j ++ ){
            cin >> a[i][j];
        }
    }
    vector<int> t(n), s(n);
    for(int i = 0; i < n; i ++ ){
        int h = 0, r = 0;
        for(int j = 0; j < n; j ++ ){
            h += a[i][j], r += a[j][i];
        }
        t[i] = h, s[i] = r;
    }
    if(t[0] == s[0] && t[1] == s[1] || t[1] == s[0] && t[0] == s[1]) cout << "YES" << endl;
    else cout << "NO" << endl;
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