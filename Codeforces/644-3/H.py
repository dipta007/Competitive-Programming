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

# region fastio
BUFSIZE = 8192

class FastIO(IOBase):
  newlines = 0

  def __init__(self, file):
    self._fd = file.fileno()
    self.buffer = BytesIO()
    self.writable = "x" in file.mode or "r" not in file.mode
    self.write = self.buffer.write if self.writable else None

  def read(self):
    while True:
      b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
      if not b:
          break
      ptr = self.buffer.tell()
      self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
    self.newlines = 0
    return self.buffer.read()

  def readline(self):
    while self.newlines == 0:
      b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
      self.newlines = b.count(b"\n") + (not b)
      ptr = self.buffer.tell()
      self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
    self.newlines -= 1
    return self.buffer.readline()

  def flush(self):
    if self.writable:
      os.write(self._fd, self.buffer.getvalue())
      self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
  def __init__(self, file):
    self.buffer = FastIO(file)
    self.flush = self.buffer.flush
    self.writable = self.buffer.writable
    self.write = lambda s: self.buffer.write(s.encode("ascii"))
    self.read = lambda: self.buffer.read().decode("ascii")
    self.readline = lambda: self.buffer.readline().decode("ascii")

if not is_it_local():
  sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
  input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion


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
import math

removed = []

def check(n):
  cnt = 0
  for v in removed:
    flg = 1
    for i in range(len(v)):
      if v[i] > n[i]:
        flg = 0
        break
      elif v[i] < n[i]: break
    # print(v, flg, n)
    cnt += flg
  return cnt

def s_to_b(st):
  c = 1
  res = 0
  for i in range(len(st)-1, -1, -1):
    res += c if st[i] == '1' else 0
    c *= 2
  return res

def b_to_s(n, m):
  res = ''
  while n:
    nw = n%2
    res += str(nw)
    n = n//2
  return "0" * (m - len(res)) + "".join(reversed(res))

def main():
  t = input1()
  for ci in range(t):
    global removed
    removed.clear()
    n, m = input2()
    for i in range(n):
      st = input_string()
      removed.append(st)

    total = 2 ** m
    mid = (total - 1) // 2
    need = (total - n - 1) // 2

    low = max(0, mid - n)
    high = min(total - 1, mid + n)
    for i in range(low, high + 1):
      pos = b_to_s(i, m)
      org_pos = i - check(pos)
      # print(i, pos, org_pos, need)
      # print(i, pos, removed)
      if org_pos == need:
        # res = b_to_s(i)
        # res = "0" * (m - len(res)) + res
        print(pos)
        break
  pass

if __name__ == '__main__':
  READ('in.txt')
  main()