n = int(input())
a = [int(x) for x in input().split()]
ans = 0
len = 1
for i in range(n - 1):
    if abs(a[i + 1] - a[i]) <= 1:
        len += 1
    else :
        len = 1
    ans = max(ans, len)
print(ans)