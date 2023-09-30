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
	int n;
    cin >> n;
    for(int i = 0; i <= n; i ++ ){
        bool ok = false;
        for(int j = 1; j <= 9; j ++ ){
            if((n % j == 0) && i % (n / j) == 0){
                ok = true;
                cout << j;
                break;
            }
        }
        if(!ok) cout << '-';
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