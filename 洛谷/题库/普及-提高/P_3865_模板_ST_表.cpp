#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int dp_max[N][22];  // 以i为起点跳2^j步的最大值或最小值
int a[N];
int n, m;
void init(){
    for(int i = 1; i <= n; i ++ ){
        dp_max[i][0] = a[i];
    }
    int p = log2(n);
    for(int k = 1; k <= p; k ++ ){
        for(int i = 1; i + (1 << k) <= n + 1; i ++ ){
            dp_max[i][k] = max(dp_max[i][k - 1], dp_max[i + (1 << (k - 1))][k - 1]);
        }
    }
}
int st(int l, int r){
    int k = log2(r - l + 1);
    int x = max(dp_max[l][k], dp_max[r - (1 << k) + 1][k]);
    return x;                           
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
    }
    init();
    for(int i = 0; i < m; i ++ ){
        int l, r;
        cin >> l >> r;
        cout << st(l, r) << endl;
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