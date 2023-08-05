#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a.begin(), a.end());
    int sum = 0;
    for(int i = 0; i < n; i ++ ) sum += a[i];
    int t = sum / n;
    int x = sum % n;
    int cnt = 0;
    for(int i = 0; i < n; i ++ ){
        if(a[i] < t) cnt += t - a[i];
    }
    int cnt2 = 0;
    for(int i = n - 1; i >= 0; i -- ){
        if(a[i] > t + 1) cnt2 += (a[i] - (t + 1));
    }
    cout << max(cnt, cnt2) << endl;
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