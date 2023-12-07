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
	int n;
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int ans = 0;
    for(int len = 2; len <= n; len ++ ){
        for(int l = 0; l + len - 1 < n; l ++ ){
            int r = l + len - 1;
            for(int i = l; i <= r; i ++ ){
                for(int j = i + 1; j <= r; j ++ ){
                    ans = (ans + (a[i] ^ a[j])) % mod;
                }
            }
        }
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