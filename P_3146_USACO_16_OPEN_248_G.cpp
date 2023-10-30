#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 270010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int f[61][N];
int n;
void solve(){
	cin >> n;
    for(int i = 1, x; i <= n; i ++ ) {
        cin >> x;
        f[x][i] = i + 1;
    }
    int ans = 0;
    for(int i = 2; i <= 60; i ++ ) {
        for(int j = 1; j <= n; j ++ ) {
            if(!f[i][j]) 
                f[i][j] = f[i - 1][f[i - 1][j]];
            if(f[i][j]) 
                ans = i;
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