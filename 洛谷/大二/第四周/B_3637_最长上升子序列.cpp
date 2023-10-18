#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<int> q(n + 1);
    int len = 0;
    for(int i = 1; i <= n; i ++ ) {
        int l = 0, r = len;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(a[i] > q[mid]) l = mid;
            else r = mid - 1;
        }
        q[r + 1] = a[i];
        len = max(len, r + 1);
    }
    cout << len << endl;
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