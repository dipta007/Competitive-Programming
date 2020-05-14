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

def main():
  t = input1()
  for ci in range(t):
    n, k = input2()
    a = input_array()
    b = input_array()
    a.sort()
    b.sort(reverse=True)

    for i in range(k):
      if a[i] < b[i]:
        a[i], b[i] = b[i], a[i]
      else:
        break
    
    print(sum(a))
  return

main()