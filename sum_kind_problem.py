# sum of n positive numbers n(n + 1)/2

p = int(input())

for i in range(0, p):
    k, n = input().split()
    k = int(k)
    n = int(n)
    s1 = n * (n + 1) // 2
    s2 = n ** 2
    s3 = n * (n + 1)
    print(str(k), str(s1), str(s2), str(s3))
