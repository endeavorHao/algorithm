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
	int n, m;
    cin >> n >> m;
    set<int> s;
    auto dfs = [&](auto self, int x){
        if(x % 3) {
            s.insert(x);
            return;
        }
        x /= 3;
        s.insert(x), s.insert(x * 2);
        self(self, x), self(self, x * 2);
    };
    dfs(dfs, n);
    if(s.count(m)) cout << "YES" << endl;
    else cout << "NO" << endl;
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