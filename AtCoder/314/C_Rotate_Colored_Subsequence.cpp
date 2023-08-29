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
    string s;
    cin >> s;
    vector<int> c(n);
    for(int i = 0; i < n; i ++ ) cin >> c[i];
    vector<vector<int>> mp(m + 1);
    for(int i = 0; i < n; i ++ ){
        mp[c[i]].push_back(i);
    }
    for(int i = 1; i <= m; i ++ ){
        if(mp[i].size() >= 1){
            char p = s[mp[i].back()];
            for(int j = mp[i].size() - 2; j >= 0; j -- ){
                s[mp[i][j + 1]] = s[mp[i][j]];
            }
            s[mp[i][0]] = p;
        }
    }
    cout << s << endl;
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