// 思路：用dist[x][y][2]来表示到{x, y}且此时为1或0的最小步数
// 用floyd算法求解

#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
int n, m;
int a[N];
int g[N][N];
int dist[N][N][2];
int st[N][N][2];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
struct node{
    int x, y, e;
};
int bfs(){
    queue<node> q; 
    q.push({1, 1, g[1][1]});
    memset(dist, 0x3f, sizeof dist);
    dist[1][1][g[1][1]] = 0;
    st[1][1][g[1][1]] = true;
    while(q.size()){
        auto t = q.front();
        q.pop();
        st[t.x][t.y][t.e] = false;
//         cout << t.x << ' ' << t.y << ' ' << dist[t.x][t.y][0] << ' ' << dist[t.x][t.y][1] << endl;
        for(int i = 0; i < 4; i ++ ){
            int x = t.x + dx[i], y = t.y + dy[i];
            if(x <= 0 || x > n || y <= 0 || y > m) continue;
            int ne = g[x][y];
            if(ne != t.e){
                if(dist[x][y][ne] > dist[t.x][t.y][t.e] + 1){
                    dist[x][y][ne] = dist[t.x][t.y][t.e] + 1;
                    if(!st[x][y][ne]){
                        st[x][y][ne] = true;
                        q.push({x, y, ne});
                    }
                }
            }else{
                if(dist[x][y][t.e ^ 1] > dist[t.x][t.y][t.e] + 2){
                    dist[x][y][t.e ^ 1] = dist[t.x][t.y][t.e] + 2;
    
                    if(!st[x][y][t.e ^ 1]){
                        st[x][y][t.e ^ 1] = true;
                        q.push({x, y, t.e ^ 1});
                    }
                }
            }
        }
    }
    return min(dist[n][m][1], dist[n][m][0]);
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }
    }
    int t = bfs();
    cout << t << endl;
	return 0;
}