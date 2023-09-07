#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 300010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> row(n, vector<int>(26, 0));
    vector<vector<int>> col(m, vector<int>(26, 0));
    vector<int> cr(n, m);
    vector<int> cl(m, n);
    for(int i = 0; i < n; i ++ ){
        string s;
        cin >> s;
        for(int j = 0; j < m; j ++ ){
            int u = s[j] - 'a';
            a[i][j] = u;
            row[i][u] ++;
            col[j][u] ++;
        }
    }
    while (true) {
		vector<int> dr;
		vector<int> dc;
		for (int i = 0; i < n; i++) {
			if (cr[i] >= 2) {
				int ok = 0;
				for (int j = 0; j < 26; j++) {
					if (row[i][j] == cr[i]) {
						ok = 1;
						break;
					}
				}
				if (ok) {
					dr.push_back(i);
				}
			}
		} 
		for (int i = 0; i < m; i++) {
			if (cl[i] >= 2) {
				int ok = 0;
				for (int j = 0; j < 26; j++) {
					if (col[i][j] == cl[i]) {
						ok = 1;
						break;
					}
				}
				if (ok) {
					dc.push_back(i);
				}
			}
		}
		if (dr.size() == 0 && dc.size() == 0) {
			break;
		}
		for (int i: dr) {
			cr[i] = 0;
			for (int j = 0; j < m; j++) {
				if (a[i][j] != -1) {
					int u = a[i][j];
					a[i][j] = -1;
					cr[i]--;
					cl[j]--;
					row[i][u]--;
					col[j][u]--;
				}
			}
		}
		for (int j: dc) {
			cl[j] = 0;
			for (int i = 0; i < n; i++) {
				if (a[i][j] != -1) {
					int u = a[i][j];
					a[i][j] = -1;
					cr[i]--;
					cl[j]--;
					row[i][u]--;
					col[j][u]--;
				}
			}
		}
	}
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            if(a[i][j] != -1) ans ++;
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