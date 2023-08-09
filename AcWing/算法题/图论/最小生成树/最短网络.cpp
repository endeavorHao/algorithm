#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int g[N][N];
int d[N];
bool st[N];
int n;
int prim(){
    int res = 0;
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for(int i = 0; i < n; i ++ ){
        int t = -1;
        for(int j = 1; j <= n; j ++ ){
            if(!st[j] && (t == -1 || d[j] < d[t]))
                t = j;
        }
        st[t] = true;
        res += d[t];
        for(int j = 1; j <= n; j ++ )
            d[j] = min(d[j], g[t][j]);
    }
    return res;
}
void solve(){
    cin >> n;
    
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= n; j ++ ) cin >> g[i][j];
    
    cout << prim() << endl;
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