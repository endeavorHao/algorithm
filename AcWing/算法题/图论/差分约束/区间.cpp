#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 300010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], w[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N];
int n;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
void spfa(){
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    st[0] = true;
    while(q.size()){
        auto t = q.front();
        q.pop();
        st[t] = false;

        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    } 
}
void solve(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= 50001; i ++ ){
        add(i - 1, i, 0);
        add(i, i - 1, -1);
    }
    for(int i = 1; i <= n; i ++ ){
        int a, b, c;
        cin >> a >> b >> c;
        a ++ , b ++;
        add(a - 1, b, c);
    }
    spfa();
    cout << dist[50001] << endl;
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