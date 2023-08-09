#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int i = 0; i < n; i ++ ) cin >> b[i];
    vector<PII> s(n);
    for(int i = 0; i < n; i ++ ) s[i] = {a[i] - b[i], i};
    sort(s.begin(), s.end(), [](PII a, PII b){
        if(a.x == b.x) return a.y < b.y;
        return a.x > b.x;
    });

    int cnt = 1;
    for(int i = 1; i < n; i ++){
        if(s[i].x == s[0].x) cnt ++;
    }
    cout << cnt << endl;
    for(int i = 0; i < cnt; i ++ ) cout << s[i].y + 1 << ' ';
    cout << endl;
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