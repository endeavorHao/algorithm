#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 3010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
char g[N][N];
void solve(){
	cin >> n >> m;
	if(!(n % 2)){
		for(int i = 1; i <= n; i ++ ){
			int cnt = 0;
			for(int j = 1; j <= m; j ++ ){
				if(((j - 1) % 4) == 0) cnt ++;
				if((i % 2) && (cnt % 2)) g[i][j] = 'x';
				else if((i % 2) && !(cnt % 2)) g[i][j] = 'o';
				else if(!(i % 2) && (cnt % 2)) g[i][j] = 'o';
				else if(!(i % 2) && !(cnt % 2)) g[i][j] = 'x';
			}
		}
		
	}else{
		for(int i = 1; i <= n; i ++ ){
			int cnt = 0;
			for(int j = 1; j <= m; j ++ ){
				if(((j - 1) % 4) == 0) cnt ++;
				if((i % 2) && (cnt % 2)) g[i][j] = 'x';
				else if((i % 2) && !(cnt % 2)) g[i][j] = 'o';
				else if(!(i % 2) && (cnt % 2)) g[i][j] = 'o';
				else if(!(i % 2) && !(cnt % 2)) g[i][j] = 'x';
			}
		}
			for(int i = 1, cnt = 1; i <= m; i ++ ){
				if((cnt % 2)) g[n][i] = 'x';
				else g[n][i] = 'o';
				cnt ++;
			} 
		}
	
    for(int i = 1; i <= n; i ++ ){
			for(int j = 1; j <= m; j ++ ) cout << g[i][j];
			cout << endl;
		}
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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}