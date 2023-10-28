#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
    multiset<int> S;
    int a, b, c;
    cin >> a >> b >> c;
    S.insert(a), S.insert(b), S.insert(c);

    int cnt = 0;
    while(cnt <= 3) {
        int a = *S.begin(), b = *S.rbegin();
        if(a == b) {
            cout << "YES" << endl;
            return;
        }
        cnt ++;
        S.erase(S.find(b));
        S.insert(a);
        S.insert(b - a);
    }
    cout << "NO" << endl; 
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}