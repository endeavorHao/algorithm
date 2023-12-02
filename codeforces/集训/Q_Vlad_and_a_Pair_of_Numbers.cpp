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
	int x;
    cin >> x;
    if(x & 1) {
        cout << "-1" << endl;
        return;
    }
    map<int, bool> vis;
    for(int i = 0; i < 30; i ++ ){
        if(x >> i & 1){
            if(vis[i - 1]){
                cout << "-1" << endl;
                return;
            }
            vis[i] = true;
        }
    }
    cout << x + x / 2 << ' ' << x / 2 << endl;
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