#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
void solve(){
	int n;
    cin >> n;
    vector<array<int, 3>> e(n);
    for(int i = 0; i < n; i ++ ){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
    sort(all(e));
    for(auto [a, b, c]: e){
        cout << a << ' ' << b << ' ' << c << endl;
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