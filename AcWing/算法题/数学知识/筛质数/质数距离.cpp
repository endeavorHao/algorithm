/*
    r太大试着用sqrt（r）的大小来找到l ~ r这一段
    l ~ r 中的质数个数为 (r - l + 1) / ln(r - l + 1)
    因此只枚举质数能可以降低ln（n）的时间复杂度 
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int primes[N], cnt;
bool st[N];
void get_prime(int n){
    memset(st, 0, sizeof st);
    cnt = 0;
    for(int i = 2; i <= n; i ++ ) {
        if(!st[i]) primes[cnt ++ ] = i;
        for(int j = 0; primes[j] * i <= n; j ++ ) {
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}
void solve(){
    int l, r;
	while(cin >> l >> r){
        get_prime(50000);
        memset(st, 0, sizeof st);
        for(int i = 0; i < cnt; i ++ ) {
            int p = primes[i];
            for(int j = max(2 * p, (l + p - 1) / p * p); j <= r; j += p){
                st[j - l] = true;
            }
        }
        cnt = 0;
        for(int i = 0; i <= r - l; i ++ ) {
            if(!st[i] & i + l >= 2) primes[cnt ++ ] = i + l;
        }
        if(cnt < 2) {
            printf("There are no adjacent primes.\n");
        }else {
            int minp = 0, maxp = 0;
            for(int i = 0; i + 1 < cnt; i ++ ) {
                int d = primes[i + 1] - primes[i];
                if(d < primes[minp + 1] - primes[minp]) minp = i;
                if(d > primes[maxp + 1] - primes[maxp]) maxp = i;
            }
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", 
            primes[minp], primes[minp + 1],
            primes[maxp], primes[maxp + 1]);
        }
    }
}
signed main() {
	int T = 1;
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}