#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for(int i = 0; i < n; i ++ ) cin >> A[i];
    for(int i = 0; i < m; i ++ ) cin >> B[i];
    vector<vector<int>> C(n, vector<int>(m)), s(n + 1, vector<int>(m + 1));
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            C[i][j] = A[i] * B[j];
            s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + C[i][j];
        }
    }
    int x;
    cin >> x;
    int ans = 0;
    for(int x1 = 1; x1 <= n; x1 ++ ){
        for(int y1 = 1; y1 <= m; y1 ++ ){
            for(int x2 = x1; x2 <= n; x2 ++ ){
                for(int y2 = y1; y2 <= m; y2 ++ ){
                    if(s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] <= x) ans = max(ans, (x2 - x1 + 1) * (y2 - y1 + 1));
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
