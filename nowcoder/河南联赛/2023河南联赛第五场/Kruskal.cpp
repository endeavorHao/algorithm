#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
    int n;
    cin >> n;
    int maxv = 0;
    for(int i = 0; i < 30; i ++ ){
        if(n >> i & 1) maxv = i;
    }
    cout << (n == (1 << maxv + 1) - 1) << endl;
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