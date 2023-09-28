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
	int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < m; i ++ ) cin >> b[i];
    int minv = 0, maxv = 0;
    int t = 0;
    for(int i = 0; i < m; i ++ ) t |= b[i];
    vector<int> cnt(30);
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < 30; j ++ ){
            if(a[i] >> j & 1) cnt[j] ++;
        }
    }
    for(int i = 0; i < n; i ++ ){
        minv ^= a[i];
    }
    cout << minv << ' ' << maxv << endl;
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