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
	string s;
    cin >> s;
    char mov[] = {'a', 'e', 'i', 'o', 'u'};
    for(auto u: s){
        bool ok = true;
        for(int i = 0; i < 5; i ++ ){
            if(u == mov[i]) {
                ok = false;
            }
        }
        if(ok) cout << u;
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