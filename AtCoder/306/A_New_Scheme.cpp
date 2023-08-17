#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
    int x;
    int sum = 0, last = 0;
	for(int i = 0; i < 8; i ++ ){
        cin >> x;
        sum += x;
        if(x < 100 || x > 675 || x < last){
            cout << "No" << endl;
            return;
        }
        last = x;
    }
    if(sum % 25 == 0){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
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