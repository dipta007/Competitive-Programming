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

def get_min(n):
  mn = 100
  while n:
    x = n%10
    mn = min(mn, x)
    n = n // 10
  
  return mn

def get_max(n):
  mx = -100
  while n:
    x = n%10
    mx = max(mx, x)
    n = n // 10
  
  return mx


def main():
  t = input1()
  # print(t)
  
  for ci in range(t):
    n, k = input2()
    for i in range(k-1):
      mn = get_min(n)
      mx = get_max(n)
      # print(i, mn, mx, n)
      if mn == 0:
        break
        
      n = n + (mn * mx)
    print(n)
  # give_it_all()


if __name__ == '__main__':
  main()