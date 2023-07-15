// #include <bits/stdc++.h>
// #define x first
// #define y second
// #define int long long
// using namespace std;
// const int N = 200010, INF = 0x3f3f3f3f;
// typedef pair<int, int> PII;
// int n, m;
// int a[N];
// void sovle(){
	
// }
// signed main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);
// 	int T = 1;
// 	cin >> T;
// 	while(T -- ){
// 		sovle();
// 	}
// 	return 0;
// }

#include<bitsdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];

void solve(){

}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif

  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}