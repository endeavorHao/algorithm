#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int dp[N], q[N];
void solve(){
	int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    int m;
    cin >> m;
    while(m -- ) {
        int k;
        cin >> k;
        memset(dp, 0, sizeof dp);
        int hh = 1, tt = 1;
        q[hh] = 1;
        for(int i = 2; i <= n; i ++ ) {
            if(i - q[hh] > k) hh ++;
            dp[i] = dp[q[hh]] + (a[i] >= a[q[hh]]);
            while(hh <= tt && (dp[q[tt]] > dp[i]) || (dp[q[tt]] == dp[i] && a[q[tt]] < a[i])) tt--;
            q[ ++ tt ] = i;
        }
        cout << dp[n] << endl;
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