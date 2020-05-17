t = int(input())

for ci in range(t):
  [n, k] = list(map(int, input().split()))
  arr = list(map(int, input().split()))

  # print(n, k)
  # print(arr)

  flg = 0
  for (ind, v) in enumerate(arr):
    if v == k and ind != 0 and ind != n-1:
      print('yes')
      flg = 1
  
  if flg == 0:
    print('no')


