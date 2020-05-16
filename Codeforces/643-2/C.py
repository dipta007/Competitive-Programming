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


def main():
  [a, b, c, d] = input_array()
  res = 0
  for i in range(a, b+1):
    nb = b + i + 1
    nc = c + i + 1

    l = max(c, nb)
    r = min(d, nc)

    print(nb, nc, l, r)

    if l <= r:
      res = r - l + 1

  print(res)

if __name__ == '__main__':
  main()