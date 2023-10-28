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
	int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    while(s.find(t) == -1 && (ans == 0 || s.size() < 2 * t.size())) {
        ans ++;
        s = s + s;
    }
    if(s.find(t) == -1)
        cout << -1 << endl;
    else cout << ans << endl;
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