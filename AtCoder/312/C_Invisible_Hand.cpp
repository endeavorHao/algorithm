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
    vector<int> A(n), B(m);
    for(int i = 0; i < n; i ++ ) cin >> A[i];
    for(int i = 0; i < m; i ++ ) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    auto check = [&](int mid) -> bool{
        int x = upper_bound(A.begin(), A.end(), mid) - A.begin();
        int y = lower_bound(B.begin(), B.end(), mid) - B.begin();
         
        return x >= m - y;
    };
    int l = 0, r = 1e9 + 1;
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