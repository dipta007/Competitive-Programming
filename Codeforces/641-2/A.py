import math

smallest_div = [i for i in range(1000004)]

for i in range(2, 1000000):
  if smallest_div[i] == i:
    for j in range(i, 1000000, i):
      if smallest_div[j] == j:
        smallest_div[j] = i

# print(smallest_div[2:20])

# def find(n):
#   sq = int(math.sqrt(n))
#   for i in range(2, sq):
#     if smallest_div[i] == i and n % i == 0:
#       return i
#   return n

t = int(input())
for ci in range(t):
  [n, k] = list(map(int, input().split()))
  res = n

  if res % 2 == 0:
    res += (2 * k)
  else:
    res += smallest_div[res]
    res += (2 * (k-1))
  # for i in range(k):
  #   res += smallest_div[res] if res <= 1000000 else find(res)

  print(res)