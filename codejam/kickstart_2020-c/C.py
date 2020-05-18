def input1(type=int):
  return type(input())


def input2(type=int):
  [a, b] = list(map(type, input().split()))
  return a, b


def input3(type=int):
  [a, b, c] = list(map(type, input().split()))
  return a, b, c


def input_array(type=int):
  return list(map(type, input().split()))


def input_string():
  s = input()
  return list(s)

##############################################################

def main1():
  squares = [x * x for x in range(0, 3200)]
  t = input1()
  for ci in range(t):
    n = input1()
    arr = input_array()


    tot = sum(arr)
    mp = { 0: 1 }
    res = 0
    now = 0
    for v in arr:
      now += v
      # print(now)
      for sq in squares:
        if sq > now:
          break
        rem = now - sq
        # print(sq, rem, mp.get(rem, -1))
        if rem >= 0 and rem in mp:
          res += mp[rem]
        
      if now not in mp:
        mp[now] = 0
      mp[now] += 1
    
    st = "".join(["Case #", str(ci + 1), ": ", str(res)])
    print(st)
    # print(f"Case #{ci+1}: {cnt}")

main1()