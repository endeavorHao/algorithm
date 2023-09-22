#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i], a[i] --;
    vector<int> b(m);
    for(int i = 0; i < m; i ++ ) cin >> b[i], b[i] --;
    vector<int> pos(n), rpos(n);
    for(int i = 0; i < n; i ++ ) pos[a[i]] = i, rpos[i] = a[i];
    int sum = 0;
    for(int i = 0; i < m; i ++ ){
        sum += pos[b[i]] / k + 1;
        if(pos[b[i]] >= 1) {
            int t1 = pos[b[i]], t2 = pos[b[i]] - 1;
            swap(pos[b[i]], pos[rpos[t2]]);
            swap(rpos[t1], rpos[t2]);
        }
    }
    cout << sum << endl;
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