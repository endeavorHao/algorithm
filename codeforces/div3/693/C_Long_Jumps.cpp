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
	int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    vector<int> nex(n + 1);
    for(int i = 0; i < n; i ++ ) nex[i] = i + a[i];
    vector<int> b(n + 1);
    for(int i = n - 1; i >= 0; i -- ){
        nex[i] = min(nex[i], n);
        b[i] = a[i] + b[nex[i]];
    }
    cout << *max_element(all(b)) << endl;
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