#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 600010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int primes[N], cnt;
bool st[N];
void get_prime(int x){
    for(int i = 2; i <= x; i ++ ){
        if(!st[i]) primes[cnt ++ ] = i;
        for(int j = 0; i * primes[j] <= x; j ++ ){
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break; 
        }
    }
}
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
void solve(){
	int l, r;
    cin >> l >> r;
    if(r != l){
        if(r <= 3) cout << "-1" << endl;
        else if(r & 1){
            cout << 2 << ' ' << r - 3 << endl;  
        }else{
            cout << 2 << ' ' << r - 2 << endl;
        }
    }else{
        if(r & 1){
            bool ok = true;
            int t = r;
            for(int i = 0; i < cnt; i ++ ){
                if(primes[i] > r) break;
                if(r % primes[i] == 0){
                    int x = t / primes[i];
                    if(x >= 2){
                        ok = false;
                        cout << primes[i] << ' ' <<  t - primes[i] << endl;
                        break;
                    }
                }
                while(r % primes[i] == 0){
                    r /= primes[i];
                }
            }
            if(ok) cout << -1 << endl;
        }else{
            if(r <= 3) cout << "-1" << endl;
            else cout << 2 << ' ' << r - 2 << endl;
        }
    }
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    get_prime(N - 1);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}