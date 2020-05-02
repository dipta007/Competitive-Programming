/// are elements positive?
all_of(first, first+n, ispositive());

/// at least one positive element?
any_of(first, first+n, ispositive());

/// none positive?
none_of(first, first+n, ispositive());


/// This function returns 1 + least significant 1-bit of x. If x == 0, returns 0. Here x is int, this function with suffix 'l' gets a long argument and with suffix 'll' gets a long long argument.
/// e.g. __builtin_ffs(10) = 2 because 10 is '...10 1 0' in base 2 and first 1-bit from right is at index 1 (0-based) and function returns 1 + index.
/// three)
__builtin_ffs(x)

/// 1 2 3
/// 4 5 6
/// 7 8 9
for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++)
        cout << a[i][j] << " \n"[j == m];

/// It wont copy
/// It will just move the whole container
/// So its faster
vector<int> v = {1, 2, 3, 4};
vector<int> w = move(v);

/// Lambda expression
[](int a, int b) -> int {
    return a+b;
}
