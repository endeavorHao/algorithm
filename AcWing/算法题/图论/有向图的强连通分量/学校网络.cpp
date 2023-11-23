#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;

int h[N], e[N], ne[N], idx;
int dfn[N], low[N], timestamp;
int id[N], scc_cnt, sz[N];
stack<int> stk;
bool in_stack[N];
int din[N], dout[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
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
            in_stack[y] = false;
            id[y] = scc_cnt;
            sz[scc_cnt] ++;
        }while(y != u);
    }
}

void solve(){
    int n;
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1, x; i <= n; i ++ ){
        while(cin >> x, x) add(i, x);
    }

    for(int i = 1; i <= n; i ++ ){
        if(!dfn[i])
            tarjan(i);
    }

    for(int i = 1; i <= n; i ++ ){
        for(int j = h[i]; ~j; j = ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a != b){
                dout[a] ++, din[b] ++;
            }
        }
    }
    
    int a = 0, b = 0;
    for(int i = scc_cnt; i; i -- ){
        if(!din[i]) a ++;
        if(!dout[i]) b ++;
    }   

    cout << a << endl;
    if(scc_cnt == 1){
        cout << 0 << endl;
    }else cout << max(a, b) << endl;
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