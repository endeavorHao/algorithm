#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
const double expr = 1e-6;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
	int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    auto check = [&](double mid) ->bool{
        vector<double> s(n + 1);
        for(int i = 0; i < n; i ++ ) s[i + 1] = s[i] + a[i] - mid;
        deque<int> deq;
        for(int i = m; i <= n; i ++ ) {
            while(deq.size() && s[deq.back()] >= s[i - m]) deq.pop_back();
            deq.push_back(i - m);
            if(s[i] - s[deq.front()] >= 0) return true;
        }
        return false;
    };
    double l = 0, r = 1e6;
    while(r - l > expr){
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << (int)(r * 1000) << endl;
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