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
    vector<int> w(n), x(n);
    for(int i = 0; i < n; i ++ ) cin >> w[i] >> x[i];
    int ans = 0;
    for(int i = 0; i < 24; i ++ ) {
        int sum = 0;
        for(int j = 0; j < n; j ++ ) {
            int s = (i + x[j]) % 24;
            if(s >= 9 && s <= 17) sum += w[j];
        }
        ans = max(ans, sum);
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