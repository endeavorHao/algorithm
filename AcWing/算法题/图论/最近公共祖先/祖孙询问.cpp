#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], ne[N], idx;
int depth[N], fa[N][31];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void bfs(int root){
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    queue<int> q;
    q.push(root);
    while(q.size()){
        auto t = q.front();
        q.pop();
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(depth[j] > depth[t] + 1){
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t;
                for(int k = 1; k <= 30; k ++ ){
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
                }
            }
        }
    }   
}
int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    // 将a和b跳到同一层
    for(int i = 30; i >= 0; i -- ){
        if(depth[fa[a][i]] >= depth[b]){
            a = fa[a][i];
        }
    }
    if(a == b) return a;
    // 将a和b一起跳到他们lca的下一层
    for(int i = 30; i >= 0; i -- ){
        if(fa[a][i] != fa[b][i]){
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}
void solve(){
	int n, m;
    cin >> n;
    memset(h, -1, sizeof h);
    int root = 0;
    for(int i = 0; i < n; i ++ ){
        int a, b;
        cin >> a >> b;
        if(b == -1) root = a;
        else{
            add(a, b), add(b, a);
        }
    }
    bfs(root);
    cin >> m;
    while(m -- ){
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        if(p == a) cout << 1 << endl;
        else if(p == b) cout << 2 << endl;
        else cout << 0 << endl;
    }
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