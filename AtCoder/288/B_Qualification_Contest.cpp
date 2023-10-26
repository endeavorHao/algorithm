#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 500010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
	int n, m;
    cin >> n >> m;
    vector<string> s(m);
    for(int i = 0; i < n; i ++ ) {
        string t;
        cin >> t;
        if(i < m) s[i] = t;
    }
    sort(all(s));
    for(int i = 0; i < m; i ++ ) cout << s[i] << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
    cout << fixed << setprecision(16);
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}