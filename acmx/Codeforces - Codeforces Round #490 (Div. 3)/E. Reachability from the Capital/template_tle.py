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

if is_it_local():
  def debug(*args):
    st = ""
    for arg in args:
      st += f"{arg} "
    print(st)
else:
  def debug(*args):
    pass

##############################################################

good = []
marked = []
mp = {}
tc = 0

from types import GeneratorType

def bootstrap(f, stack=[]):
  def wrappedfunc(*args, **kwargs):
    to = f(*args, **kwargs)
    if stack:
      return to
    else:
      while True:
        if type(to) is GeneratorType:
          stack.append(to)
          to = next(to)
        else:
          stack.pop()
          if not stack:
            return to
          to = stack[-1].send(to)
  return wrappedfunc


@bootstrap
def dfs(u):
  global good, mp
  good[u] = 1
  for v in mp.get(u, []):
    if good[v] == 0:
      yield dfs(v)
  yield

@bootstrap
def dfs1(u):
  global marked, mp
  marked[u] = tc
  res = 0
  for v in mp.get(u, []):
    if marked[v] != tc and good[v] == 0:
      res += yield dfs1(v)
  yield res + 1

def main():
  global marked, mp, good, tc
  n, m, s = input3()

  good = [0 for i in range(n+2)]
  marked = [0 for i in range(n+2)]
  mp = {i: [] for i in range(1, n+1)}
  
  for i in range(m):
    u, v = input2()
    mp[u].append(v)

  dfs(s)

  q = []
  for i in range(1, n+1):
    if good[i] == 0:
      tc += 1
      q.append((dfs1(i), i))
  
  # q = [(v, i) for i, v in enumerate(ind) if i >= 1 and i <= n]
  q.sort(reverse=True)

  dfs(s)
  cnt = 0
  for _, i in q:
    if good[i] == 0:
      dfs(i)
      # print(i)
      cnt += 1
  
  print(cnt)

  pass

if __name__ == '__main__':
  # READ('in.txt')
  main()