#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 400010, INF = 0x3f3f3f3f, mod = 100003;
typedef pair<int, int> PII;
int dist[N], cnt[N];
bool st[N];
int h[N], e[N], ne[N], idx;
int n, m;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void bfs(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    cnt[1] = 1;
    queue<int> q;
    q.push(1);
    while(q.size()){
        auto t = q.front();
        q.pop();

        if(st[t]) continue; 
        st[t] = true;
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + 1){
                dist[j] = dist[t] + 1;
                cnt[j] = cnt[t];
                q.push(j);
            }else if(dist[j] == dist[t] + 1){
                cnt[j] = (cnt[j] + cnt[t]) % mod;
            }
        }
    }
}
void solve(){
	cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m -- ){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bfs();
    for(int i = 1; i <= n; i ++ ){
        cout << cnt[i] << endl;
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