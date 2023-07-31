#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
void solve(){
	string str;
	while(cin >> str){
		if(str[0] == 'e') break;
		vector<vector<bool>> col(9, vector<bool>(9, false)), row(9, vector<bool>(9, false));
		vector<vector<vector<bool>>> st(3, vector<vector<bool>>(3, vector<bool>(9, false)));	
		vector<vector<char>> g(9, vector<char>(9));
		for(int i = 0; i < 9; i ++ ){
			for(int j = 0; j < 9; j ++ ){
				g[i][j] = str[i * 9 + j];
				if(g[i][j] != '.'){
					col[j][g[i][j] - '1'] = row[i][g[i][j] - '1'] = st[i / 3][j / 3][g[i][j] - '1'] = true;
 				} 
 				cout << g[i][j];
			}
			cout << endl;
		}
		function<void(int, int)> dfs = [&](int x, int y) {
			if(y == 9) x ++, y = 0;
			if(x == 9) return;
			cout << x << ' ' << y << endl;
			if(g[x][y] != '.'){
				
				dfs(x, y + 1);
			}
			else{
				for(int i = 1; i <= 9; i ++ )
					if(!col[y][i - 1] && !row[x][i - 1] && !st[x / 3][y / 3][i - 1]){
						col[y][i - 1] = row[x][i - 1] = st[x / 3][y / 3][i - 1] = true;
						g[x][y] = (char)i + '0';
						dfs(x, y + 1);
						g[x][y] = '.';
						col[y][i - 1] = row[x][i - 1] = st[x / 3][y / 3][i - 1] = false;
					}
			}
		};
		dfs( 0, 0);
		for(int i = 0; i < 9; i ++ )
			for(int j = 0; j < 9; j ++ ) cout << g[i][j];
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
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}