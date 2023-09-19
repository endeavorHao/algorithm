#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
char g[N][N];
void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < m; j ++ ) cin >> g[i][j];
    int ans = 0;
    for(int i = 0; i < n - 1; i ++ ){
        for(int j = 0; j < m - 1; j ++ ){
            set<char> s;
            for(int l = i; l <= i + 1; l ++ ){
                for(int r = j; r <= j + 1; r ++ ){
                    s.insert(g[l][r]);
                }
            }
            if(s.count('y') && s.count('u') && s.count('o')) ans ++;
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