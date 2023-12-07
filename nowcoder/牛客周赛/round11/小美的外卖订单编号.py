n = int(input())
for i in range(n):
    m, x = map(int, input().split())
    if x % m == 0:
        print(m)
    else :
        print(x % m)