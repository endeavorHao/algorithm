#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int b[N];
void solve(){
	int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    vector<array<int, 3>> q(m + 1);
    for(int i = 1; i <= m; i ++ ){
        int d, s, t;
        cin >> d >> s >> t;
        s --, t --;
        q[i] = {d, s, t};
    }
    auto check = [&](int x) -> bool{
        memset(b, 0, sizeof b);
        for(int i = 1; i <= x; i ++ ){
            auto [d, s, t] = q[i];
            b[s] += d;
            b[t + 1] -= d;
        }
        for(int i = 0; i < n; i ++ ){
            b[i] += b[i - 1];
            if(b[i] > a[i]) return false;
        }
        return true;
    };
    int l = 1, r = m + 1;
    while(l < r){
        int mid = l + r >> 1;
        if(!check(mid)) r = mid;
        else l = mid + 1;
    }
    if(r == m + 1) cout << 0 << endl;
    else{
        cout << -1 << endl;
        cout << r << endl;
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