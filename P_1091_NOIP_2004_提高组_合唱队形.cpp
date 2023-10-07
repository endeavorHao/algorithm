#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 10010, INF = 0x3f3f3f3f, mod = 1000000007, P = 131;

typedef pair<int, int> PII;
typedef unsigned long long UII;

void solve(){
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    vector<int> f(n + 1), g(n + 1);
    for(int i = 0; i < n; i ++ ){
        f[i] = 1;
        for(int j = 0; j < i; j ++ ){
            if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
    }
    for(int i = n - 1; i >= 0; i -- ){
        g[i] = 1;
        for(int j = n - 1; j > i; j -- ){
            if(a[i] > a[j]) g[i] = max(g[i], g[j] + 1);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i ++ ) {
        ans = max(ans, f[i] + g[i] - 1);
    }
    cout << n - ans << endl;
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