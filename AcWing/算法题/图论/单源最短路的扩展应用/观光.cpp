#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int dist[N][2], cnt[N][2];
bool st[N][2];
int h[N], e[N], ne[N], w[N], idx;
int n, m;
int S, T;
struct node{
    int id, type, dist;
    bool operator> (const node &W) const{
        return dist > W.dist;
    } 
};
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int dijkstra(){
    priority_queue<node, vector<node>, greater<node>> heap;
    heap.push({S, 0, 0});
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    cnt[S][0] = 1;
    dist[S][0] = 0;
    while(heap.size()){
        auto t = heap.top();
        heap.pop();

        int id = t.id, type = t.type, distance = t.dist, count = cnt[id][type];
        if(st[id][type]) continue;
        st[id][type] = true;

        for(int i = h[id]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j][0] > distance + w[i]){
                dist[j][1] = dist[j][0];
                cnt[j][1] = cnt[j][0];
                heap.push({j, 1, dist[j][1]});
                dist[j][0] = distance + w[i];
                cnt[j][0] = count;
                heap.push({j, 0, dist[j][0]});
            }else if(dist[j][0] == distance + w[i]){
                cnt[j][0] += count;
            }else if(dist[j][1] > distance + w[i]){
                dist[j][1] = distance + w[i];
                cnt[j][1] = count;
                heap.push({j, 1, dist[j][1]});
            }else if(dist[j][1] == distance + w[i]){
                cnt[j][1] += count;
            }
        }
    }
    int ans = cnt[T][0];
    if(dist[T][0] == dist[T][1] - 1) ans += cnt[T][1];
    return ans;
}
void solve(){
	cin >> n >> m;
    memset(h, -1, sizeof h);
    idx = 0;
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cin >> S >> T;
    cout << dijkstra() << endl;

}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}