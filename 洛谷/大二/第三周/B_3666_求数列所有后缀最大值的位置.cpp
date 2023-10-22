#include <bits/stdc++.h>
#define x first
#define y second
#define int unsigned long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];

    stack<int> stk;
    int orl = 0;
    for(int i = 0; i < n; i ++ ) {
        while(stk.size() && a[i] >= a[stk.top()]) {
            orl ^= stk.top() + 1;
            stk.pop();
        }
        stk.push(i);
        orl ^= i + 1;
        cout << orl << endl;
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