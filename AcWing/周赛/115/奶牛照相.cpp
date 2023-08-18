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
    vector<int> w(n), h(n);
    int sum = 0;
    int maxv = 0, lmaxv = 0;
    for(int i = 0; i < n; i ++ ){
        cin >> w[i] >> h[i];
        sum += w[i];
        if(h[i] > maxv){
            lmaxv = max(maxv, lmaxv);
            maxv = h[i];
        }else if(h[i] > lmaxv) lmaxv = h[i];
    }
    for(int i = 0; i < n; i ++ ){
        if(h[i] != maxv){
            cout << maxv * (sum - w[i]) << ' ';
        }
        else cout << lmaxv * (sum - w[i]) << ' ';
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