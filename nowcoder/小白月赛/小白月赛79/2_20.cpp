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
    int res = 20;
    for(int _ = 0; _ <= 20; _ ++ ) {
        int pos = 0;
        int t = _ + n;
        for(int i = 0; i < 30; i ++ ) {
            if(t >> i & 1) {
                pos = i;
                break;
            }
        }
        int ans = _ + max(0ll, 20 - pos);
        res = min(res, ans);
    }
    cout << res << endl;
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