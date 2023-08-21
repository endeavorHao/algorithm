#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 300010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    map<string, vector<string>> G;
    string target = "bessie";
    for(int i = 0; i < n; i ++ ){
        string a, b;
        cin >> a >> b;
        for(auto &u: a) u = tolower(u);
        for(auto &v: b) v = tolower(v);
        G[b].push_back(a);
    }
    int ans = 0;
    auto dfs = [&](auto self, string u, int depth) -> void{
        ans = max(ans, depth);
        for(auto v: G[u]){
            self(self, v, depth + 1);
        }
    };
    dfs(dfs, target, 1);
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