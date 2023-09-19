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
	int x, y, z;
    cin >> x >> y >> z;
    int l = 0, r = 1e9;
    auto check = [&](int mid)->bool{
        int t = mid * x + (mid + 2) / 3 * y;
        return t >= z;
    };
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
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