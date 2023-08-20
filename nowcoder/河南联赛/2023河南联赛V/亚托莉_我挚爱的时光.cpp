#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    map<string, int> mp1, mp2;
    while(n -- ){
        string s;
        cin >> s;
        if(s == "sudo"){
            string s1, s2, s3;
            cin >> s1 >> s2 >> s3;
            if(s1 == "pacman"){
                mp1[s3] ++;
                mp2[s3] ++;
            }else{
                cout << "wuwuwu" << endl;
                break;
            }
        }else if(s == "pacman"){
            string s1, s2;
            cin >> s1 >> s2;
            mp1[s2] = 0;
            if(s1 == "-Rscn"){
                mp2[s2] = 0; 
            }
        }else if(s == "1"){
            string s1;
            cin >> s1;
            if(mp1[s1]) cout << "yes" << endl;
            else cout << "no" << endl;
        }else {
            string s1;
            cin >> s1;
            if(mp2[s1]) cout << "yes" << endl;
            else cout << "no" << endl;
        }
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