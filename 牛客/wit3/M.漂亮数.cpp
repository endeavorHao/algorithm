// 思路：先用线性筛法将所有可能为答案的质数筛出
//      将所有质数遍历一遍找出漂亮数存进alls中  时间复杂度大概O(1000 * cnt)

#include <bits/stdc++.h>
#define x first
#define y second 
#define int long long 
using namespace std;
const int N = 5e7 + 10; 
typedef pair<int, int> PII;
int n;
int a[N]; 
int prime[N], cnt;
bool st[N];
vector<int> alls;
void get_prime(int x){
    for(int i = 2; i < x; i ++ ){
        if(!st[i]) prime[cnt ++ ] = i;
        for(int j = 0; prime[j] * i < x; j ++ ){
            st[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    get_prime(N);
    int sum = 0;
    for(int i = 0; i < cnt; i ++ ){
        for(int j = i; j < cnt; j ++ ){
            int t = prime[i] * prime[j];
            if(t > 1e8) break;
            alls.push_back(t);
         }
    }
    sort(alls.begin(), alls.end());
    int T;
    cin >> T;
    while(T --){
        int l, r;
        cin >> l >> r;
//         cout << upper_bound(alls.begin(), alls.end(), r) - alls.begin() << endl;
//         cout << upper_bound(alls.begin(), alls.end(), l - 1) - alls.begin() << endl;
        cout << upper_bound(alls.begin(), alls.end(), r) - upper_bound(alls.begin(), alls.end(), l - 1) << endl;
    }
	return 0;
} 