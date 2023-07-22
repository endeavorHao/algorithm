#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
int cnt[31];
int sum;
void solve(){
	cin >> n;
    int t = 0;
    for(int i = 0; i < 31; i ++ ){
        t = (1 << i);
        if(t >= n + 1){ t = i; break;} 
    }
    int maxv = 0;
    for(int i = 0; i < 31; i ++ ){
        if(n >> i & 1) cnt[i] ++, sum ++, maxv = i;
    }
   maxv = (1 << maxv);
   sum --;
   for(int i = 0; i < 31; i ++ ){
        if(sum == 0) break;
        sum --;
        maxv += (1 << i);
   } 
   cout << n - maxv << endl;
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