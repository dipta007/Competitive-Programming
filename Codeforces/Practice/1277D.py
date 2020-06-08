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

def is_it_okay(st01, st10):
  return abs(st01 - st10) <= 1

def is_it_double(st, mp):
  if mp.get(st[::-1], 0) == 1:
    return True
  return False

def main():
  t = input1()
  for ci in range(t):
    n = input1()

    mat = []
    st01, st10 = 0, 0
    mp = {}
    for i in range(n):
      st = input()
      now = [st]
      mp[st] = 1

      if st[0] == '0' and st[-1] == '1':
        st01 += 1
        now.append(0)
        now.append(1)
      elif st[0] == '1' and st[-1] == '0':
        st10 += 1
        now.append(1)
        now.append(0)
      else:
        now.append(ord(st[0]) - 48)
        now.append(ord(st[-1]) - 48)
        
      mat.append(now)

    swapped = []
    # print(st01, st10)

    # No 0...1 or 1...0
    if st01 == 0 and st10 == 0:
      flg = 0
      nw = mat[0]
      for [st, a, b] in mat:
        if nw[1] != a or nw[2] != b:
          print(-1)
          flg = 1
          break
      if not flg:
        print(0)
        print("")
    elif is_it_okay(st01, st10):
      print(0)
      print("")
    else:
      for i, [s, a, b] in enumerate(mat):
        if st01 > st10 + 1 and a == 0 and b == 1 and not is_it_double(s, mp):
          swapped.append(i)
          mp[s] -= 1
          mp[s[::-1]] = 1
          st01 -= 1
          st10 += 1
        elif st10 > st01 + 1 and a == 1 and b == 0 and not is_it_double(s, mp):
          swapped.append(i)
          mp[s] -= 1
          mp[s[::-1]] = 1
          st10 -= 1
          st01 += 1

      if is_it_okay(st01, st10):
        print(len(swapped))
        print(" ".join([str(x+1) for x in swapped]))
      else:
        print(-1)


  pass

if __name__ == '__main__':
  # READ('in.txt')
  main()