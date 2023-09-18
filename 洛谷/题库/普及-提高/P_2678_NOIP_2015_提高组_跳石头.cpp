#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int L, n, m;
    cin >> L >> n >> m;
    vector<int> a(n + 2);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    a[n + 1] = L;
    auto check = [&](int x) -> bool{
        int last = 0, total = 0;
        for(int i = 1; i <= n + 1; i ++ ){
            if(a[i] - a[last] < x){
                total ++;
            }else{
                last = i;
            }
        }
        return total <= m;
    };
    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << endl;
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