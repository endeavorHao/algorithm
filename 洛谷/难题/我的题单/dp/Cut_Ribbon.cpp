#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 5010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
    int n;
    vector<int> a(3);
    cin >> n;
    for(int i = 0; i < 3; i ++ ) cin >> a[i];
    vector<int> dp(n + 1, -INF);
    dp[0] = 0;
    for(int i = 0; i < 3; i ++ ) {
        for(int j = a[i]; j <= n; j ++ ) {
            dp[j] = max(dp[j], dp[j - a[i]] + 1);
        }
    }    
    cout << dp[n] << endl;
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