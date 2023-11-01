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
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; i ++ ) {
        if(!a[i]) {
            if(i - 1 >= 0) ans = max(ans, a[i - 1]);
            if(i + 1 < n) ans = max(ans, a[i + 1]);
        }
    }
    sort(all(a));
    int x = 0;
    for(int i = 0; i < n; i ++ ) {
        if(a[i] == x) x ++;
    }
    ans = max(ans, x);
    if(*max_element(all(a)) == 0) ans = 0;
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