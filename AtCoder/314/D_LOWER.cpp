#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 500010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
struct node{
    int t, x;
    char c;
};
void solve(){
	int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    int last = 0;
    vector<node> op(q);
    for(int i = 0; i < q; i ++ ) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        x --;
        if(t >= 2) last = i;
        op[i] = {t, x, c};
    }
    for(int i = 0; i < q; i ++ ){
        if(op[i].t == 1){
            s[op[i].x] = op[i].c;
        }else if(i == last){
            if(op[i].t == 2)
                for(int j = 0; j < n; j ++ )
                    s[j] = tolower(s[j]);
            else 
                for(int j = 0; j < n; j ++ )
                    s[j] = toupper(s[j]);
        }
    }
    cout << s << endl;
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