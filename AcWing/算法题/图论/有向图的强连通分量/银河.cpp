#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, M = 6000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;

int h[N], hs[N], e[M], ne[M], w[N], idx;
int dfn[N], low[N], timestamp;
int id[N], scc_cnt, sz[N];
stack<int> stk;
bool in_stack[N];
int dist[N];

void add(int h[], int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
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
        scc_cnt ++;
        int y;
        do{
            y = stk.top();
            stk.pop();
            id[y] = scc_cnt;
            in_stack[y] = false;
            sz[scc_cnt] ++;
        }while(y != u);
    }
}

void solve(){
	int n, m;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof hs);
    for(int i = 1; i <= n; i ++ ) add(h, 0, i, 1);
    while(m -- ){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) add(h, b, a, 0), add(h, a, b, 0);
        else if(t == 2) add(h, a, b, 1);
        else if(t == 3) add(h, b, a, 0);
        else if(t == 4) add(h, b, a, 1);
        else add(h, a, b, 0);
    }

    tarjan(0);
    
    bool success = true;
    for(int i = 0; i <= n; i ++ ){
        for(int j = h[i]; ~j; j = ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a == b) {
                if(w[j] > 0){
                    success = false;
                    break;
                }
            }else add(hs, a, b, w[j]);
        }
    }
    if(!success) cout << -1 << endl;
    else{
        for(int i = scc_cnt; i; i -- ){
            for(int j = hs[i]; ~j; j = ne[j]){
                int k = e[j];
                dist[k] = max(dist[k], dist[i] + w[j]);
            }
        }

        int ans = 0;
        for(int i = 1; i <= scc_cnt; i ++ ){
            ans += dist[i] * sz[i];
        }
        cout << ans << endl;
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