#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
char g[N][N];
int n, m;
bool check(int x, int y){
    if(x + 8 > n || y + 8 > m) return false;
    for(int i = x; i <= x + 2; i ++ )
        for(int j = y; j <= y + 2; j ++ ){
            if(g[i][j] == '.') return false;
        }
    for(int i = x; i <= x + 3; i ++ ) {
        if(g[i][y + 3] == '#') return false;
    }
    for(int i = y; i <= y + 3; i ++ ){
        if(g[x + 3][i] == '#') return false;
    }
    int a = x + 6, b = y + 6;
    for(int i = a; i <= a + 2; i ++ ){
        for(int j = b; j <= b + 2; j ++ ){
            if(g[i][j] == '.') return false;
        }
    }
    for(int i = a - 1; i <= a + 2; i ++ ){
        if(g[i][b - 1] == '#') return false;
    }
    for(int i = b - 1; i <= b + 2; i ++ ){
        if(g[a - 1][i] == '#') return false;
    }
    return true;
}
void solve(){
	cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> g[i] + 1;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            if(check(i, j)){
                cout << i << ' ' << j << endl;
            }
        }
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