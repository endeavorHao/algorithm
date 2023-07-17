#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m, x;
int a[N];
void sovle(){
	cin >> x;
    for(int i = 1; i <= 9; i ++ ){
        int t = 0;
        t = x * 10 + i;
        if(t % 7 == 0){
            cout << t << endl;
            break;
        }
    }
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T -- ){
		sovle();
	}
	return 0;
}


