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
  return

main()