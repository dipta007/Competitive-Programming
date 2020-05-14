def input1(type = int):
  return type(input())

def input2(type = int):
  [a, b] = list(map(type, input().split()))
  return a, b

def input3(type = int):
  [a, b, c] = list(map(type, input().split()))
  return a, b, c

def input_array(type = int):
  return list(map(type, input().split()))

def input_string():
  s = input()
  return list(s)

def get_val(l, r, cum):
  if l == r:
    return 0
  res = cum[r]
  if l != 0:
    res -= cum[l-1]
  return res

def main():
  t = input1()
  for ci in range(t):
    n, m = input2()
    arr = list(map(int, input_string()))
    
    tot_on = 0
    last = -1
    res = 2e6
    for i in range(0, n):
      if arr[i] == 1:
        tot_on += 1
        last = i
    
    dp = [0 for _ in range(n+2)]
    for i in range(last+1):
      now = 0
      if arr[i] == 1:
        now += 1
      else:
        now -= 1

      dp[i % m] += now
      dp[i % m] = max(dp[i % m], 0)
      res = min(res, tot_on - dp[i%m])

    res = 0 if last == -1 else res
    print(res)
  return

main()