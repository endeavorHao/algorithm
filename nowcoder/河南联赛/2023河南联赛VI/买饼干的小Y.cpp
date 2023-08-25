#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    cin >> n >> m;
    int cnt = 0;
    n -= m;
    while(m > 1 && n > 0){
        int s = (m + 1) / 2;
        n -= s;
        cnt ++;
        m = s;
    }
    if(n > 0)
        cnt += n;
    cout << cnt << endl;
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