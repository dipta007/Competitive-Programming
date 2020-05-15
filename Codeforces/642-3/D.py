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

# from queue import PriorityQueue
import heapq as pq

def get_l(sz, m):
  md = sz // 2
  if sz % 2 == 0:
    md -= 1
  return m - md

def get_r(sz, m):
  return m + sz//2

def mid_point(l, r):
  length = r - l + 1
  m = length // 2
  if length % 2 == 0:
    m -= 1
  return l + m

def break_here(l, r):
  m = mid_point(l, r)
  sz1 = (m-1) - l + 1
  sz2 = r - (m+1) + 1
  return [(-sz1, mid_point(l, m-1)), (-sz2, mid_point(m+1, r))]

def main():
  t = input1()
  for ci in range(t):
    n = input1()

    # pq = heapq()
    h = []
    pq.heappush(h, (-n, mid_point(0, n-1)))

    ind = 1
    arr = [0 for _ in range(n)]
    while len(h):
      now = pq.heappop(h)

      arr[now[1]] = str(ind)
      ind += 1

      [a, b] = break_here(get_l(-now[0], now[1]), get_r(-now[0], now[1]))
      # print(a, b)
      if a[0] < 0:
        pq.heappush(h, a)
      if b[0] < 0:
        pq.heappush(h, b)

    print(" ".join(arr))

  return

main()