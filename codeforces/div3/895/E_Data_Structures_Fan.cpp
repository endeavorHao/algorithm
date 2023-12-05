#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 600010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    vector<int> a(n), s(n + 1);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    string str;
    cin >> str;
    int sum = 0, s1 = 0;
    for(int i = 0; i < n; i ++ ){
        s[i + 1] = s[i] ^ a[i];
        sum ^= a[i];
        if(str[i] == '1') s1 ^= a[i];
    }
    int q;
    cin >> q;
    while(q -- ){
        int op;
        cin >> op;
        if(op == 1){
            int l, r;
            cin >> l >> r;
            s1 ^= s[r] ^ s[l - 1];
        }else{
            int x;
            cin >> x;
            if(x == 0){
                cout << (sum ^ s1) << ' ';;
            }else{
                cout << s1 << ' ';
            }
        }
    }
    cout << endl;
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