n = int(input())
ans = 0
i = 1
sum = 1
while i <= n:
    sum *= i
    ans = ans + sum
    i = i + 1
print(ans)