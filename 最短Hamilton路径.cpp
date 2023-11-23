#include <bits/stdc++.h>
#define x first
#define y second
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 25, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int f[1 << 21][N], g[N][N];  // f[i][j] 表示以i二进制的走法且最后一个点走到j的所有方案min
void solve(){
	int n;
    cin >> n;
    for(int i = 0; i < n; i ++ ) 
        for(int j = 0; j < n; j ++ ) cin >> g[i][j];
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;  
    for(int i = 0; i < 1 << n; i ++ ){
        for(int j = 0; j < n; j ++ ){
            if(i >> j & 1){
                for(int k = 0; k < n; k ++ ){
                    if(i >> k & 1){
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + g[k][j]);  // 倒数第二个点为k进行划分
                    }
                }
            }
        }
    }
    cout << f[(1 << n) - 1][n - 1] << endl;
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