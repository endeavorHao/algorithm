#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], w[N], ne[N], idx;
vector<PII> query[N];  // first是查询的另一个点，second是下标
int st[N];  //  0为这个点还没被遍历，1为这个点正在被遍历，2表示这个点已经被遍历过了
int depth[N], ans[N];
int p[N];
void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int u, int fa){
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(j == fa) continue;
		depth[j] = depth[u] + w[i];
		dfs(j, u);
	}
}
int find(int x){
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
void tarjan(int u){
	st[u] = 1;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(!st[j]){
			tarjan(j);
			p[j] = u;
		}
	}
	for(auto [y, id]: query[u]){
		if(st[y] == 2){
			int anc = find(y);
			ans[id] = depth[u] + depth[y] - depth[anc] * 2;
		}
	}
	st[u] = 2;
}
void solve(){
	int n, m;
    cin >> n >> m;
	memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
	for (int i = 0; i < m; i ++ ){
        int a, b;
        cin >> a >> b;
        if (a != b)
        {
            query[a].push_back({b, i});
            query[b].push_back({a, i});
        }
    }
	for (int i = 1; i <= n; i ++ ) p[i] = i;
	dfs(1, -1);
	tarjan(1);

	for(int i = 0; i < m; i ++ ) cout << ans[i] << endl;
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