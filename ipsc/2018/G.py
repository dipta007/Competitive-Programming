import os

vs = []
with open('easy.txt', 'r') as myfile:
    data=myfile.readline().strip()
    if len(data) > 0:
        vs.append(data)
    while data:
        data = myfile.readline().strip()
        # print(data)
        if len(data) > 0:
            vs.append(data)

# vs.sort()
res = 0
ind = 1
mod = 1000000007

# print(vs)

for st in vs:
    # print(st, len(st))
    for ch in st:
        chn = ord(ch)
        res = (res + (chn * ind)%mod )%mod
        ind += 1
    res = (res + (10 * ind)%mod )%mod
    ind += 1

print(res)

# root = os.getcwd() + "/g"

# res = 0
# mod = 1000000007
# ind = 1

# vs = []

# for root, dirs, files in os.walk(root):
#     for file in files:
#         st = os.path.join(root, file)
#         tmp = st[77:]
#         if tmp[0] == '.':
#             continue
#         vs.append(tmp)


