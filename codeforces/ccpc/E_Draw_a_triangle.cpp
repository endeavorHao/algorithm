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

int exgcd(int a, int b, int &x, int &y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve(){
	int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2) {
        cout << x1 + 1 << " " << y1 << endl; 
        return;
    }
    if(y1 == y2) {
        cout << x1 << " " << y1 + 1 << endl;
        return;
    }  
    int a = x2 - x1, b = y2 - y1;
    int x, y;
    int d = exgcd(-b, a, x, y);  // y * a - b * x = gcd(a, b)
    cout << x1 + x << " " << y1 + y << endl;
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