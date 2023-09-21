#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void solve(){
	int n, m;
    cin >> n >> m;
    if(n == 1){
        cout << "Yes" << endl;
        return;
    }
    if(m == 1){
        cout << "No" << endl;
        return;
    }
    while(n > 1){
        int t = n / m;
        n %= m;
        n += t;
        if(!t) break;
    }
    if(n == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
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