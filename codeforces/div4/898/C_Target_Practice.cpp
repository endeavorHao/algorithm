#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	vector<vector<char>> g(10, vector<char>(10));
    for(int i = 0; i < 10; i ++ ) {
        for(int j = 0; j < 10; j ++ ) cin >> g[i][j];
    }
    int ans = 0;
    for(int i = 0; i < 10; i ++ ){
        for(int j = 0; j < 10; j ++ ){
            if(g[i][j] == 'X'){
                for(int z = 0; z < 5; z ++ ){
                    if(i == z || j == z || j == 9 - z || i == 9 - z) {
                        ans += z + 1;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
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