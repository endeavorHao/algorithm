v0, x, y = map(int, input().split())
if v0 * v0 > x * y:
    print(y / v0)
else:
    print(2 * ((y / x) ** 0.5) - v0 / x)