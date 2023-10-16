#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 300010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i ++ ){
        int c;
        cin >> c;
        for(int j = 0; j < c; j ++ ){
            int x;
            cin >> x;
            x --;
            adj[i].push_back(x);
        }
    }
    vector<bool> read(n);
    auto dfs = [&](auto self, int x) -> void{
        if(read[x]){
            return;
        }
        for(auto y: adj[x]){
            self(self, y);
        }
        read[x] = true;
        if(x != 0) cout << x + 1 << ' ';
    };
    dfs(dfs, 0);
    cout << endl;
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