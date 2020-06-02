""" Python 3 compatibility tools. """
from __future__ import division, print_function
import itertools
import sys, threading
import os
from io import BytesIO, IOBase
from types import GeneratorType

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

adj = {}
label = []
target = []
cost = []
data = []

def merge(a, b):
  # node number, zero number, one number, correct, need zero, need one
  tmp = [a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3], a[4] + b[4], a[5] + b[5]]
  return tmp

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
def dfs1(u, p):
  global data, label, target, adj, cost
  now = [
    1, 
    1 if label[u] == 0 and label[u] != target[u] else 0, 
    1 if label[u] == 1 and label[u] != target[u] else 0, 
    1 if label[u] == target[u] else 0, 
    1 if target[u] == 0 and label[u] != target[u] else 0, 
    1 if target[u] == 1 and label[u] != target[u] else 0
  ]

  if p != -1:
    cost[u] = min(cost[u], cost[p])

  if u in adj:
    for v in adj[u]:
      if v != p:
        tmp = yield dfs1(v, u)
        now = merge(now, tmp)

  data[u] = now
  yield now


res = 0

@bootstrap
def call(u, p):
  global data, label, target, adj, cost, res
  
  f_0, f_1 = 0, 0
  if u in adj:
    for v in adj[u]:
      if v != p:
        n_0, n_1 = yield call(v, u)
        f_0 += n_0
        f_1 += n_1

  now = data[u]
  can_be_fixed_zero = min(now[4], now[1]) - f_0
  can_be_fixed_one = min(now[5], now[2]) - f_1
  not_fixed = can_be_fixed_zero + can_be_fixed_one
  res += not_fixed * cost[u]

  yield f_0 + can_be_fixed_zero, f_1 + can_be_fixed_one

def main():
  global data, label, target, adj, cost
  n = input1()
  data = [0 for _ in range(n+4)]
  label = [0 for _ in range(n+4)]
  target = [0 for _ in range(n+4)]
  cost = [0 for _ in range(n+4)]

  z, o, tz, to = 0, 0, 0, 0
  for i in range(1, n+1):
    cost[i], label[i], target[i] = input3()
    z += (label[i] == 0)
    o += (label[i] == 1)

    tz += (target[i] == 0)
    to += (target[i] == 1)
  
  adj = {}
  for i in range(n-1):
    u, v = input2()
    if u not in adj:
      adj[u] = []
    if v not in adj:
      adj[v] = []

    adj[u].append(v)
    adj[v].append(u)


  if (tz != z or o != to):
    print(-1)
    exit()
  dfs1(1, -1)

  # for i in range(1, n+1):
  #   print(data[i], cost[i])

  global res
  res = 0
  call(1, -1)
  print(res)
  pass

if __name__ == '__main__':
  # sys.setrecursionlimit(2**32//2-1)
  # threading.stack_size(1 << 27)

  # thread = threading.Thread(target=main)
  # thread.start()
  # thread.join()
  # sys.setrecursionlimit(200004)
  # READ('in.txt')
  main()