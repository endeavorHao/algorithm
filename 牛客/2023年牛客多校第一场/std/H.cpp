#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
long long a[N + 5], b[N + 5];
struct node
{
    long long l, r;
    int type;
    node(long long _l, long long _r)
    {
        l = min(_l, _r);
        r = max(_l, _r);
        type = _l > _r;
    }
    bool operator<(const node &b)const
    {
        return r < b.r;
    }
};
const long long inf = 0x3f3f3f3f3f3f3f3fll;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%lld", b + i);
    vector<node> q;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += abs(a[i] - b[i]);
        q.emplace_back(a[i], b[i]);
    }
    sort(q.begin(), q.end());
    long long overlap = 0, l[2] = {inf, inf};
    for (int i = n - 1; i >= 0; i--)
    {
        int difType = q[i].type ^ 1;
        if (l[difType] < q[i].r)
            overlap = max(overlap, q[i].r - max(q[i].l, l[difType]));
        l[q[i].type] = min(l[q[i].type], q[i].l);
    }
    printf("%lld", sum - 2 * overlap);
    return 0;
}