#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for(int i = 0; i < n; i ++ )    
        for(int j = 0; j < m; j ++ ) cin >> g[i][j];
    bool ok = false;
    string target = "vika";
    int c = 0;
    for(int j = 0; j < m; j ++ ){
        set<char> s;
        for(int i = 0; i < n; i ++ ){  
            s.insert(g[i][j]);
            if(i == n - 1 && !s.count(target[c])){
                ok = true;
                break;
            }else if(i == n - 1){
                c ++;
            }
        }
    }
    if(c == 4) cout << "YES" << endl;
    else cout << "NO" << endl;
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