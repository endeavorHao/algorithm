#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int g[N][N];
int dist[N];
bool st[N];
int n, m;
void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 1; i <= n; i ++ ){
        int t = -1;
        for(int j = 1; j <= n; j ++ ){
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        st[t] = true;
        for(int j = 1; j <= n; j ++ ){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
}
void solve(){
	cin >> m >> n;
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; i ++ ) g[i][i] = 0;
    string line;
    getline(cin, line);
    while(m -- ){
        getline(cin, line);
        stringstream ssin(line);
        int x;
        vector<int> stop;
        while(ssin >> x){
            stop.push_back(x);
        }
        for(int i = 0; i < stop.size(); i ++ )
            for(int j = i + 1; j < stop.size(); j ++ )
                g[stop[i]][stop[j]] = 1;
    }
    dijkstra();
    if(dist[n] == INF) cout << "NO" << endl;
    else
        cout << max(0, dist[n] - 1) << endl;
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