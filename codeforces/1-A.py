import os
# num = input()
# n = input()
# m = input()
# a = input()
# n = int(n)
# m = int(m)
# a = int(a)
n, m, a = map(int, input().split())
x = 0
y = 0
if n%a==0:
    x = n // a
else:
    x = n // a + 1

if m%a==0:
    y = m // a
else:
    y = m // a + 1

print(x*y)