/*
    x = x ^ x % 1000
    每个a[i] >= 1
    用隔板法 x个球用k - 1个隔板
    答案为C(x - 1, k - 1)
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f, mod = 5000011;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int f[N][110][160];

int qmi(int a, int b, int p) {
    int ans = 1;
    while(b){
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

void add(int c[], int a[], int b[]) {
    int t = 0;
    for(int i = 0; i < 150; i ++ ) {
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
}

void solve(){  
    int k, x;
    cin >> k >> x;
    x = qmi(x % 1000, x, 1000);
    // 求C(x - 1, k - 1);
    for(int i = 0; i < x; i ++ ) {
        for(int j = 0; j < k && j <= i; j ++ ) {
            if(!j) f[i][j][0] = 1;
            else add(f[i][j], f[i - 1][j], f[i - 1][j - 1]);
        }  
    }
    int i = 149;
    while(!f[x - 1][k - 1][i]) i --;
    while(i >= 0) cout << f[x - 1][k - 1][i --];
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