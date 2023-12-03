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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < n; i ++ ) {
        k /= __gcd(k, a[i]);
        a[i] /= __gcd(k, a[i]);
    }
    if(k == 2) {
        cout << 1 << endl;
        return;
    }
    if(k == 4) {
        if(n == 1) {
            if(a[0] % 4 == 1) {
                cout << 3 << endl;
                return;
            }else if(a[0] % 4 == 3) {
                cout << 1 << endl;
                return;
            }
        }else {
            for(int i = 0; i < n; i ++ ) {
                if(a[i] % 4 == 3) {
                    cout << 1 << endl;
                    return;
                }
            }
            cout << 2 << endl;
            return;
        }
    }
    int ans = 5;
    for(int i = 0; i < n; i ++ ) {
        int cnt = 0;
        while(a[i] % k != 0) {
            cnt ++;
            a[i] ++;
        }
        ans = min(ans, cnt);
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