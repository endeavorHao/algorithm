#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 500010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N], backup[N];
bool check(int mid){
    memcpy(backup, a, sizeof a);
    backup[1] += mid;
    for(int i = 2; i <= n; i ++ ){
        if(backup[i] - mid >= backup[i - 1]) return false;
        backup[i] = min(backup[i-1] - 1, backup[i] + mid);
    }
    return true;
}
void solve(){
	cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
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