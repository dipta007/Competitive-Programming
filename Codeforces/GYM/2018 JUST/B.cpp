t = int(raw_input())
for _ in range(t):
    n,m = map(int, raw_input().split())
    low = 0, high = n*m;
    sz = n*m;
    while low <= high:
        mid = (low + high) // 2;
        val = (mid * (mid-1)) // 2;
        if(val > sz):
            high = mid -1;
        else:
            ans = mid;
            low = mid + 1;
    print(ans);
