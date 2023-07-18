#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int res=1e18;
    for(int i=0;i<26;i++)
    {
    	int sum=0;
    	for(int j=0;j<s.size();j++)
	    {
	        int x=(s[j]-'a');
	        x=min(abs(x-i),26-abs(x-i));
	    	sum+=x;
		}
		res=min(res,sum);
	}
    printf("%lld\n",res);
} 
signed main()
{
	int t;
//	cin >> t;
    t=1;
	while(t--)
	{
		solve();
	}
}