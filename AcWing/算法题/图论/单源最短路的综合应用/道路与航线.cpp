#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int n, mr, mp, S;
int h[N], e[N], w[N], ne[N], idx;
vector<int> block[N];
int d[N];
int id[N], dist[N];
bool st[N];
int cnt;
queue<int> q;
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}
void dfs(int u, int bid){
    id[u] = bid, block[bid].push_back(u);

    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!id[j])
            dfs(j, bid);
    }
}
void dijkstra(int bid){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    
    for(auto u: block[bid]){
        heap.push({dist[u], u});
    }
    while(heap.size()){
        auto t = heap.top();
        heap.pop();

        if(st[t.y]) continue;
        st[t.y] = true;

        for(int i = h[t.y]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > t.x + w[i]){
                dist[j] = t.x + w[i];
            }
            if(id[j] == id[t.y]){
                heap.push({dist[j], j});
            }else{
                if(--d[id[j]] == 0) q.push(id[j]);
            }
        }
    }
}
void topsort(){
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;

    // 将入度为0的板块放进队列
    for(int i = 1; i <= cnt; i ++ ) 
        if(!d[i]) q.push(i);
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        dijkstra(t);
    }
}
void solve(){
    cin >> n >> mr >> mp >> S;
    memset(h, -1, sizeof h);
    while(mr -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    for(int i = 1; i <= n; i ++ )
        if(!id[i]){
            cnt ++;
            dfs(i, cnt);
        }
    while(mp -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        d[id[b]] ++;
    }

    topsort();

    for(int i = 1; i <= n; i ++ ){
        if(dist[i] > INF / 2) cout << "NO PATH" << endl;
        else cout << dist[i] << endl;
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