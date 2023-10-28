#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    for(int i = 0; i < n; i ++ ) {
        for(int j = 0; j < n; j ++ ) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n / 2; i ++ ) {
        for(int j = i; j < n - 1 - i; j ++ ) {
            char maxv = 'a';
            int a = i, b = j;
            for(int z = 0; z < 4; z ++ ) {
                maxv = max(maxv, g[a][b]);
                int nea = b, neb = n - 1 - a;
                a = nea, b = neb;
            }
            for(int z = 0; z < 4; z ++ ) {
                ans += maxv - g[a][b];
                int nea = b, neb = n - 1 - a;
                a = nea, b = neb;
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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}