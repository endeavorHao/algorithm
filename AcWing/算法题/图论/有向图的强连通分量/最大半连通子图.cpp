#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, M = 2000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;

int h[N], hs[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int id[N], scc_cnt, sz[N];
stack<int> stk;
bool in_stack[N];
int f[N], g[N];

void add(int h[], int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u){
    dfn[u] = low[u] = ++ timestamp;
    stk.push(u), in_stack[u] = true;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }else if(in_stack[j]) low[u] = min(low[u], dfn[j]);
    }

    if(dfn[u] == low[u]){
        int y;
        scc_cnt ++;
        do{
            y = stk.top();
            stk.pop();
            in_stack[y] = false;
            id[y] = scc_cnt;
            sz[scc_cnt] ++;
        }while(y != u);
    }
}

void solve(){
	int n, m, mod;
    cin >> n >> m >> mod;
    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof hs);
    for(int i = 0; i < m; i ++ ){
        int a, b;
        cin >> a >> b;
        add(h, a, b);
    }

    for(int i = 1; i <= n; i ++ ){
        if(!dfn[i])
            tarjan(i);
    }

    set<int> S;  // u * 1000000 + v
    for(int i = 1; i <= n; i ++ ){
        for(int j = h[i]; ~j; j = ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a != b && !S.count(a * 1000000 + b)){
                add(hs, a, b);
                S.insert(a * 1000000 + b);
            }   
        }
    }
    for(int i = scc_cnt; i; i -- ){
        if(!f[i]){
            f[i] = sz[i];
            g[i] = 1;
        }
        for(int j = hs[i]; ~j; j = ne[j]){
            int k = e[j];
            if(f[k] < f[i] + sz[k]){
                f[k] = f[i] + sz[k];
                g[k] = g[i];
            }else if(f[k] == f[i] + sz[k]){
                g[k] = (g[k] + g[i]) % mod;
            }
        }
    }

    int maxf = 0, ans = 0;
    for(int i = 1; i <= scc_cnt; i ++ ){
        if(maxf < f[i]){
            maxf = f[i];
            ans = g[i];
        }else if(maxf == f[i]) ans = (ans + g[i]) % mod;
    }
    cout << maxf << endl;
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