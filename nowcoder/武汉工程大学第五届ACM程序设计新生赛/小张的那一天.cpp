#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	vector<int> a(4);
    for(int i = 0; i < 4; i ++ ) cin >> a[i];
    
    vector<int> f(20);
    f[0] = 1;
    for(int i = 1; i < 20; i ++ ) f[i] = f[i - 1] * i;

    int ans = 0;
    for(int i = 1; i <= a[0]; i ++ )
        for(int j = 1; j <= a[1]; j ++ )
            for(int k = 1; k <= a[2]; k ++ )
                for(int z = 1; z <= a[3]; z ++ ){
                    ans += f[i + j + k + z] / (f[i] * f[j] * f[k] * f[z]);
                    ans -= f[i - 1 + j + k + z] / (f[i - 1] * f[j] * f[k] * f[z]);
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