against = myself - 1
if against < 1 then
    against = N
end

my_bool = colors[against] == 1

hands = raise(my_bool)

afterMe = myself + 1
if afterMe > N then
    afterMe = 1
end

if hands[afterMe] then
    answer = 1
else
    answer = C
end