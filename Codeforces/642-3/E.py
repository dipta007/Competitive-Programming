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
    cum = [0 for _ in arr]
    cum[0] = arr[0]
    last = (0 if arr[0] else -1)
    for i in range(1, n):
      cum[i] = cum[i-1] + arr[i]
      if arr[i] == 1:
        last = i
      
    if last == -1:
      print(0)
      continue
      
    # print(last)
    
    prev_del = 0
    res = 2000000
    for i in range(n):
      if i and i % m == 0:
        break
      lft = i
      now_del = prev_del + (1 if arr[i] == 0 else 0)
      for j in range(i+m, last+1, m):
        now_del += get_val(lft + 1, j-1, cum)
        now_del += (1 if arr[j] == 0 else 0)
        lft = j
        # print("in", j, now_del)
      
      # print(lft)
      now_del += get_val(lft, last, cum)
      res = min(res, now_del)

      if arr[i] == 1:
        prev_del += 1

      # print(i, now_del, prev_del, res, arr[i])

    print(res)
  return

main()