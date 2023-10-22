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
	int n;
    cin >> n;
    stack<ULL> stk;
    while(n -- ) {
        string s;
        cin >> s;
        if(s == "push") {
            ULL x;
            cin >> x;
            stk.push(x);
        }else if(s == "query") {
            if(stk.size()) cout << stk.top() << endl;
            else cout << "Anguei!" << endl;
        }else if(s == "size") {
            cout << stk.size() << endl;
        }else {
            if(stk.size()) stk.pop();
            else cout << "Empty" << endl; 
        }
    }
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