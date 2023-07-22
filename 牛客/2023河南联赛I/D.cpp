#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m, st, ed, hp;
int cut[N];
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool vis[N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
bool check(int mid){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, st}); 
    if(cut[st] > mid) return false;
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[st] = 0;
    while(q.size()){
        auto t = q.top();
        q.pop();
        if(vis[t.y]) continue;
        vis[t.y] = true;
        if(t.y == ed){
            return true;
        }
        for(int i = h[t.y]; ~i; i = ne[i]){
            int j = e[i];
            if(cut[j] > mid) continue;
            if(t.x + w[i] > hp) continue;
            if(dist[j] > t.x + w[i]){
                dist[j] = t.x + w[i];
                q.push({dist[j], j});
            }
        }
    }
    return false;
}
void solve(){
	cin >> n >> m >> st >> ed >> hp;
    for(int i = 1; i <= n; i ++ ) cin >> cut[i];
    memset(h, -1, sizeof h);
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(check(r)) cout << r << endl;
    else cout << -1 << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
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