t = int(input())
for ci in range(t):
  n = int(input())
  arr = list(map(int, input().split()))

  # print(n, arr) 
  # import random
  # arr = random.sample(range(1, 1000000), n)
  # print(arr)

  mark = [0 for _ in range(n+4)]
  for i in range(n-1, -1, -1):
    nw = i + 1
    maxy = 0
    for j in range(i+nw, n, nw):
      if arr[j] > arr[i]:
        # print(i, j, arr[j], arr[i])
        maxy = max(maxy, mark[j])
    
    mark[i] = maxy + 1
  
  print(max(mark))
