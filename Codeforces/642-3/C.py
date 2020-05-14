def input1(type = int):
  return type(input())

def input2(type = int):
  [a, b] = list(map(type, input().split()))
  return a, b

def input2(type = int):
  [a, b, c] = list(map(type, input().split()))
  return a, b, c

def input_array(type = int):
  return list(map(type, input().split()))

def input_string():
  s = input()
  return list(s)

def main():
  t = input1()
  for ci in range(t):
    n = input1()
    c = 8
    res = 0
    for i in range(1, n // 2 + 1):
      # print(i, c)
      res += (c*i)
      c += 8
    print(res)
  return

main()