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
    vector<int> month(n);
    int sum = 0;
    for(int i = 0; i < n; i ++ ){
        cin >> month[i];
        sum += month[i];
    }
    sum /= 2;
    sum = sum + 1;
    int s = 0;
    int a, b;
    for(int i = 0; i < n; i ++ ){
        if(s + month[i] >= sum) {
            a = i + 1, b = sum - s;
            break;
        }
        s += month[i];
        // cout << s << endl;
    }
    cout << a << ' ' << b << endl;
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