#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 5000010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
int cnt1[N], cnt2[N];
int s1[N], s2[N];
int get2(int x){
    int cnt = 0;
    while(x % 2 == 0){
        x /= 2;
        cnt ++;
    }
    return cnt;
}
int get5(int x){
    int cnt = 0;
    while(x % 5 == 0){
        x /= 5;
        cnt ++;
    }
    return cnt;
}
void solve(){
	cin >> n;
    int h = 1;
    for(int i = 1; i <= n; i ++ ){
        cnt1[i] = cnt1[i - 1] + get2(4 * i - 2) - get2(i + 1);
        cnt2[i] = cnt2[i - 1] + get5(4 * i - 2) - get5(i + 1);
        s1[i] = s1[i-1] + cnt1[i], s2[i] = s2[i-1] + cnt2[i];
    }
    cout << min(s1[n], s2[n]) << endl;
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