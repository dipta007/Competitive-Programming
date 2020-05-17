primes = []
def sieve(n):
  marked = [True for i in range(n+4)] 
  p = 2
  while (p * p <= n): 
    if (marked[p] == True):
      for i in range(p * p, n+1, p): 
        marked[i] = False
    p += 1
  for p in range(2, n+1): 
    if marked[p]: 
      primes.append(p)


def get_result(arr):
  res = 1
  for p in primes:
    now = []
    zeros = 0
    for i in range(len(arr)):
      cnt = 0
      while arr[i] % p == 0:
        arr[i] /= p
        cnt += 1
      
      if cnt == 0:
        zeros += 1
      now.append(cnt)

      if zeros == 2:
        break
    if zeros == 2:
      continue
    now.sort()
    mx = max(now[0], now[1])

    # print(p, mx, p**mx)
    res *= (p ** mx)
  
  return res

sieve(200000)
# print(len(primes))


n = input()
arr = list(map(int, input().split()))
print(get_result(arr))

