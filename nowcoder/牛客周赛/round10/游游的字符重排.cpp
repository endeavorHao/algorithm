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
	string s;
    cin >> s;
    sort(all(s));
    auto f = [&](string s) -> bool{
        int n = s.size();
        s.erase(unique(s.begin(), s.end()), s.end());
        return n == s.size();
    };
    int ans = 0;
    do{
        ans += f(s);
    }while(next_permutation(all(s)));
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