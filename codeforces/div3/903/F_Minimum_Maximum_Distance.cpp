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
	int n, k;
    cin >> n >> k;
    vector<int> mark(n);
    for(int i = 0; i < k; i ++ ) {
        int x;
        cin >> x;
        x -- ;
        mark[x] = 1;
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i ++ ) {
        int a, b;
        cin >> a >> b;
        a --, b --;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dis(n);
    auto bfs = [&](int x){
        queue<int> q;
        dis.assign(n, -1);
        q.push(x);
        dis[x] = 0;
        while(q.size()) {
            auto x = q.front();
            q.pop();
            for(auto y: adj[x]) {
                if(dis[y] == -1) {
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
        }
        int t = -1;
        for(int i = 0; i < n; i ++ ) {
            if(mark[i] && (t == -1 || dis[i] > dis[t])) {
                t = i;
            }
        }
        return t;
    };
    int a = bfs(0);
    int b = bfs(a);
    auto f = dis;
    bfs(b);
    for(int i = 0; i < n; i ++ ) {
        f[i] = max(f[i], dis[i]);
    }
    int ans = *min_element(all(f));
    cout << ans << endl;
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