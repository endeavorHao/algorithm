#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 998244353;
typedef pair<int, int> PII;
void solve(){
	int l, r, cnt;
    cin >> l >> r >> cnt;
    int s = 0;
    while(l <= r){
        int mid = l + r >> 1;
        s ++;
        if(s == cnt){
            cout << mid << endl;
            return;
        }
        l = mid + 1;
    }
    cout << -1 << endl;
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