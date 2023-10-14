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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<vector<int>> cnt(n + 1, vector<int>(60));
    for(int i = 1; i <= n; i ++ ){
        cnt[i] = cnt[i - 1];
        for(int j = 0; j < 60; j ++ ){
            if(a[i] >> j & 1) cnt[i][j] ++;
        }
    }
    while(q -- ){
        int l, r, x;
        cin >> l >> r >> x;
        int t = 0;
        for(int i = 0; i < 60; i ++ ){
            if(cnt[r][i] - cnt[l - 1][i] > 0){
                t += 1ll << i;
            }
        }
        cout << (t | x) << endl;
    }
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