#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
	int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    auto check = [&](int x) ->bool {
        string t = to_string(x);
        map<char, int> cnt;
        for(auto c: t) {
            cnt[c] ++;
        } 
        for(auto c: s) {
            cnt[c] --;
        }
        for(auto [x, y]: cnt) {
            if(x == '0') {
                if(y > 0) return false;
            }else if(y) return false;
        }
        return true;
    };
    for(int i = 0; i <= sqrt(1e13); i ++ ) {
        if(check(i * i)) {
            ans ++;
        }
    }
    cout << ans << endl;
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