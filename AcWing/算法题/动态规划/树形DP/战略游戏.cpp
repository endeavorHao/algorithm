#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], ne[N], idx;
int f[N][2];
bool st[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++; 
}
void dfs(int u){
    f[u][0] = 0, f[u][1] = 1;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        dfs(j);

        f[u][0] += f[j][1];
        f[u][1] += min(f[j][0], f[j][1]);
    }
}
void solve(){
	int n;
    while(cin >> n){
        memset(h, -1, sizeof h);
        idx = 0;
        for(int i = 0; i < n; i ++ ){
            int id, cnt;
            scanf("%d:(%d)", &id, &cnt);
            while(cnt -- ){
                int x;
                cin >> x;
                add(id, x);
                st[x] = true;
            }
        }
        int root = 0;
        while(st[root]) root ++;
        dfs(root);
        cout << min(f[root][0], f[root][1]) << endl;
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