#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int hs[N], hr[N], e[N], ne[N], idx;
int w[N];
int dmax[N], dmin[N];
bool st[N];
int n, m;
void add(int h[], int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dijkstra(int h[], int dist[], int type){
    queue<int> q;
    memset(st, false, sizeof st);
    if(type == 0){
        memset(dist, 0x3f, sizeof dmax);
        q.push(1);
        dist[1] = w[1];
    }else{
        memset(dist, -0x3f, sizeof dmax);
        q.push(n);
        dist[n] = w[n];
    }
    while(q.size()){
        auto t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(type == 0){
                if(dist[j] > min(dist[t], w[j])){
                    dist[j] = min(dist[t], w[j]);
                    if(!st[j]){
                        q.push(j);
                        st[j] = true;
                    }
                }
            }else{
                if(dist[j] < max(dist[t], w[j])){
                    dist[j] = max(dist[t], w[j]);
                    if(!st[j]){
                        q.push(j);
                        st[j] = true;
                    }
                }
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> w[i];
    memset(hs, -1, sizeof hs);
    memset(hr, -1, sizeof hr);
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(hs, a, b), add(hr, b, a);
        if(c == 2) add(hs, b, a), add(hr, a, b);
    }
    dijkstra(hs, dmin, 0);
    dijkstra(hr, dmax, 1);
    int ans = 0;

    for(int i = 1; i <= n; i ++ )
        ans = max(ans, dmax[i] - dmin[i]);
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