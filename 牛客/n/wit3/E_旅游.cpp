// 思路修路以耗费最少的权重排序
// 用并查集找出1到n全部连通的边
// 因为要维护k*p[i]最小 所以从最大消费开始枚举找答案

#include <bits/stdc++.h>
#define x first
#define y second 
#define int long long 
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f; 
typedef pair<int, int> PII;
int n, m;
int g[N][N];
string line;
int dist[N];
bool st[N];
int p[N], cnt;
int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for(int i = 0; i < n; i ++ ){
        int t = -1;
        for(int j = 1; j <= n; j ++ ){
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        } 
        
        st[t] = true;
        for(int j = 1; j <= n; j ++ ){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    return dist[n];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> m >> n;
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; i ++ ) g[i][i] = 0;
    getline(cin, line);
    while(m -- ){
        getline(cin, line);
        stringstream ss(line);
        int x, cnt = 0;
        while(ss >> x)
            p[cnt ++ ] = x;
        for(int i = 0; i < cnt; i ++ )
            for(int j = i + 1; j < cnt; j ++ )
                g[p[i]][p[j]] = 1;
    }
    int t = dijkstra();
    if(t > INF / 2) cout << "NO" << endl;
    else cout << t - 1 << endl;
	return 0;
} 