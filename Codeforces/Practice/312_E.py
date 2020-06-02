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

class Node2:
  def __init__(self):
    self.val = 0
    self.prop = 0

class SegTree:
  def __init__(self):
    self._MX = 100004
    self._tree = [Node2() for i in range(self._MX * 3)]

  def merge(self, n1, n2):
    res = Node2()
    res.val = n1.val + n2.val
    res.prop = 0
    return res
  
  def init(self, node, b, e):
    if b == e:
      self._tree[node].val = 0
      self._tree[node].prop = 0
      return
    
    left = node * 2
    right = left + 1
    mid = (b + e) // 2
    self.init(left, b, mid)
    self.init(right, mid+1, e)
    self._tree[node] = self.merge(self._tree[left], self._tree[right])

  def propagate(self, node, b, e):
    if b == e:
      self._tree[node].prop = 0
      return
    
    left = node << 1
    right = left + 1
    mid = (b+e) >> 1

    self._tree[left].prop += self._tree[node].prop
    self._tree[right].prop += self._tree[node].prop
    self._tree[node].prop = 0

    # Update tree[left].val
    left_range = mid - b + 1
    self._tree[left].val += self._tree[left].prop * left_range
    # Update tree[right].val
    right_range = e - mid
    self._tree[right].val += self._tree[right].prop * left_range

  def query(self, node, b, e, i, j):
    if i > e or j < b:
      return 0
    if self._tree[node].prop:
      self.propagate(node, b, e)
    if b >= i and e <= j:
      return self._tree[node].val
    
    left = node << 1
    right = left + 1
    mid = (b+e) >> 1

    p1 = self.query(left, b, mid, i, j)
    p2 = self.query(right, mid+1, e, i, j)
    return p1 + p2

  def update(self, node, b, e, i, j, new_val):
    if self._tree[node].prop:
      self.propagate(node, b, e)

    if i > e or j < b:
      return 0

    if b >= i and e <= j:
      curr_range = e - b + 1
      self._tree[node].val += (new_val * curr_range)
      self._tree[node].prop += new_val
      return

    left = node << 1
    right = left + 1
    mid = (b+e) >> 1
    
    self.update(left, b, mid, i, j, new_val)
    self.update(right, mid+1, e, i, j, new_val)
    self._tree[node] = self.merge(self._tree[left], self._tree[right])

def main():
  pass

if __name__ == '__main__':
  READ('in.txt')
  main()


https://codeforces.com/blog/entry/22616?locale=en