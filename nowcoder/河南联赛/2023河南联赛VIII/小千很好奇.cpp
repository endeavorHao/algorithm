#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int prime[N], cnt;
bool st[N];
int s[N];
void get_prime(int x){
    st[1] = true;
    for(int i = 2; i <= x; i ++ ){
        if(!st[i]) prime[cnt ++ ] = i;
        for(int j = 0; i * prime[j] <= x; j ++ ){
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
void solve(){
	int l, r;
    cin >> l >> r;
    cout << s[r] - s[l - 1] << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    get_prime(N - 1);
    for(int i = 1; i < N; i ++ ){
        s[i] = s[i - 1];
        if(!st[i]) s[i] ++;
    }
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}