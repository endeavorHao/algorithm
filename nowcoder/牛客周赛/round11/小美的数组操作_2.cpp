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
	int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < k; i ++ ){
        int u, v;
        cin >> u >> v;
        u --, v --;
        a[u] ++, a[v] --;
    }
    bool ok = false;
    for(int i = 1; i < n; i ++ ){
        if(a[i] < a[i - 1]) ok = true;
    }
    if(ok) cout << "No" << endl;
    else cout << "Yes" << endl;
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