#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1010; 
int f[N][N];
int h[N], e[N], ne[N], idx;
int v[N], w[N];
int n, m;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int u){
    for(int i = h[u]; ~i; i = ne[i]){
        int son = e[i];
        dfs(son);
        
        for(int j = m - v[u]; j >= 0; j -- )  // 循环体积
            for(int k = 0; k <= j; k ++ )  // 循环决策
                f[u][j] = max(f[u][j], f[son][k] + f[u][j - k]);
    }
    for(int i = m; i >= 0; i -- ) f[u][i] = f[u][i - v[u]] + w[u];
    for(int i = 0; i < v[u]; i ++ ) f[u][i] = 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
    memset(h, -1, sizeof h);
	int root;
	for(int i = 1; i <= n; i ++ ){
	    int p;
	    cin >> v[i] >> w[i] >> p;
	    if(p == -1) root = i;
	    else add(p, i);
	}
	
	dfs(root);
	
	cout << f[root][m] << endl;
	
	return 0;
}