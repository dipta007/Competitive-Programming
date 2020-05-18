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
  t = input1()
  for ci in range(t):
    n, k = input2()
    arr = input_array()

    cnt = 0
    i = 0
    while i < n:
      if arr[i] == k:
        now = k
        while i < n and now == arr[i]:
          i += 1
          now -= 1
        if now == 0:
          cnt += 1
      else:
        i+=1
    
    st = "".join(["Case #", str(ci + 1), ": ", str(cnt)])
    print(st)
    # print(f"Case #{ci+1}: {cnt}")

main1()