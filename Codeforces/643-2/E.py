""" Python 3 compatibility tools. """
from __future__ import division, print_function
import itertools
import sys

if sys.version_info[0] < 3:
  input = raw_input
  range = xrange

  filter = itertools.ifilter
  map = itertools.imap
  zip = itertools.izip

# input = sys.stdin.read().split('\n')[::-1].pop

# import __pypy__
# out = __pypy__.builders.StringBuilder()


def give_it_all():
  if sys.version_info[0] < 3:
    os.write(1,out.build())
  else:
    os.write(1,out.build().encode())


def result_out(*args):
  for arg in args:
    out.append(arg)
    out.append(' ')
  out.append('\n')


# Built In GDC is much slower on python
def gcd(x, y):
  """ greatest common divisor of x and y """
  while y:
    x, y = y, x % y
  return x


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


def solve(h, arr, a, r, m):
  rgt = len(arr) - 1
  while rgt >= 0 and arr[rgt] <= h:
    rgt -= 1

  i = 0
  res = 0
  while i < len(arr):
    if arr[i] < h:
      if rgt != -1 and m <= a + r:
        nw = min(h - arr[i], arr[rgt] - h)
        res += nw * m
        arr[rgt] -= nw
        arr[i] += nw
        if arr[rgt] == h:
          rgt -= 1
      else:
        res += (h - arr[i]) * a
        arr[i] = h
    elif arr[i] > h:
      res += (arr[i] - h) * r
      arr[i] = h
    
    while rgt >= 0 and arr[rgt] <= h:
      rgt -= 1
    
    if arr[i] == h:
      i += 1
  
  # print('f', h, res)
  return res
        


def main():
  [n, a, r, m] = input_array()
  arr = input_array()
  arr.sort()

  low = -1
  high = max(arr)
  while high - low > 1:
    mid = (high + low) >> 1
    # print('lmh', low, mid, high)
    if solve(mid, arr[:], a, r, m) < solve(mid+1, arr[:], a, r, m):
      high = mid
    else:
      low = mid

  print(solve(low + 1, arr[:], a, r, m))

  pass

if __name__ == '__main__':
  main()
