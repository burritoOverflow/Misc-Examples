# python3 solution to open.kattis sum kind of problem

p = int(input())

for i in range(0, p):
    k, n = input().split()
    k = int(k)
    n = int(n)
    print(str(k), str(n * (n + 1) // 2), str(n ** 2), str(n * (n + 1)))
