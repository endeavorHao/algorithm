#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int b[N];
void solve(){
	int L, n;
    cin >> L >> n;
    for(int i = 0; i < n; i ++ ){
        int l, r;
        cin >> l >> r;
        b[l] ++, b[r + 1] --;
    }
    int ans = 0;
    for(int i = 0; i <= L; i ++ ){
        if(i) b[i] += b[i - 1];
        if(!b[i]) ans ++;
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