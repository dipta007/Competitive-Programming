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
  t = input1(int)
  for ci in range(t):
    n, m = input2(int)

    if n == 1:
      print(0)
      continue
      
    if n == 2:
      print(m)
      continue
      

    pos_value_boshbe = n // 2
    na = n - 1
    
    if n % 2 == 0:
      pos_value_boshbe -= 1
      na -= 1
    
    half = m // pos_value_boshbe

    res = 0
    if pos_value_boshbe > 0:
      res += (half * (na - 2))
      if m % pos_value_boshbe == 0:
        res += (half * 2)
      else:
        rem = m // pos_value_boshbe + m % pos_value_boshbe
        res += (rem * 2)
    print(res)
  
  return

main()