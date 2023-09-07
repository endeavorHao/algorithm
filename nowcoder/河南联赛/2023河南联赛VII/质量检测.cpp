#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int q[N];
void solve(){
	int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int hh = 0, tt = -1;
    for(int i = 1; i < n; i ++ ){
        if(hh <= tt && i - k >= q[hh]) hh ++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt --;

        q[ ++ tt] = i;
        if(i >= k - 1) cout << a[q[hh]] << '\n';
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