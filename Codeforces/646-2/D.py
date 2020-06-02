""" Python 3 compatibility tools. """
from __future__ import division, print_function
import itertools
import sys
import os
from io import BytesIO, IOBase


if sys.version_info[0] < 3:
  input = raw_input
  range = xrange

  filter = itertools.ifilter
  map = itertools.imap
  zip = itertools.izip


def is_it_local():
  script_dir = str(os.getcwd()).split('/')
  username = "dipta007"
  return username in script_dir


def READ(fileName):
  if is_it_local():
    sys.stdin = open(f'./{fileName}', 'r')


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

def make_query(arr):
  st = f"? {len(arr)}"
  for v in arr:
    st += " " + str(v)
  return st

mx = 0

def call(l, r):
  if l == r:
    return l
  mid = (l + r) >> 1
  # print("lr", l, r, mid)
  lft = make_query([i for i in range(l, mid+1)])
  print(lft)
  lmx = input1()
  if lmx == mx:
    return call(l, mid)
  return call(mid+1, r)
  # rgt = make_query([i for i in range(mid+1, r+1)])
  # print(rgt)
  # rmx = input1()



def main():
  t = input1()
  for ci in range(t):
    n, k = input2()
    ar = []
    for i in range(k):
      nw = input_array()[1:]
      ar.append(nw)

    print(make_query([i for i in range(1, n+1)]))
    # stdout.flush()
    global mx
    mx = input1()
    mx_ind = call(1, n)

    password = [0 for _ in range(k)]
    for i, var in enumerate(ar):
      if mx_ind in var:
        print(make_query([i for i in range(1, n+1) if i not in var]))
        nw = input1()
        password[i] = nw
      else:
        password[i] = mx

    st = '!'
    for v in password:
      st += " " + str(v)
    print(st)

    res = input()
    if res == 'Incorrect':
      break


  pass

if __name__ == '__main__':
  # READ('in.txt')
  main()

# 3 4 1 2