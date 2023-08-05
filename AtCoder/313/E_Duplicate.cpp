#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 998244353;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    string s;
    cin >> s;
    int last = 1;
    bool ok = false;
    for(int i = 0; i < n; i ++ ){
        if(last == 1 || s[i] == '1'){
            last = s[i] - '0';
            continue;
        }
        ok = true;
    }
    if(ok) cout << -1 << endl;
    else{
        int ans = 1;
        int cnt = 0;
        for(int i = n - 1; i > 0; i -- ){
            cnt = ans * (s[i] - '1') + 1;
            ans = (ans + cnt) % mod;
        }
        cout << ans - 1 << endl;
    }
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