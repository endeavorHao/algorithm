#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int prime[N], cnt;
bool st[N];
void get_primes(int x){
    st[1] = true;
    for(int i = 2; i < x; i ++ ){
        if(!st[i]) prime[cnt ++ ] = i;
        for(int j = 0; i * prime[j] < x; j ++ ){
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
void solve(){
	cin >> n;
    bool ok = false;
    while(n){
        if(st[n]){
            ok = true;
            break;
        }
        n /= 10;
    }
    if(ok) cout << "NO" << endl;
    else cout << "YES" << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    get_primes(N);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}