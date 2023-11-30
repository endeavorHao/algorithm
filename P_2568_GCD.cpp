#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 10000010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int prime[N], cnt;
bool st[N];
int phi[N];
int s[N];

void init(int n) {
    phi[1] = 1;
    for(int i = 2; i <= n; i ++ ) {
        if(!st[i]) {
            prime[cnt ++ ] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; prime[j] <= n / i; j ++ ) {
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j]; 
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    for(int i = 1; i <= n; i ++ ) {
        s[i] = s[i - 1] + phi[i];
    }
}

void solve(){
    int n;   
    cin >> n;
    init(n);
    int ans = 0;
    for(int i = 0; i < cnt; i ++ ) {
        int p = prime[i];
        ans += s[n / p] * 2 - 1;
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T -- ){
        solve();
    }
    return 0;
}