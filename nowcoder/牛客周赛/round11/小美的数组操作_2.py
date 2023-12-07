t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()]

    for j in range(k):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        a[u] += 1
        a[v] -= 1
    
    for j in range(n - 1):
        if a[j + 1] < a[j]:
            print("No")
            break
        if j == n - 2:
            print("Yes")
