n = int(input())
t = input()
count = 0
t.strip()
_list = []
for char in t:
    _list.append(char)
for char in _list:
    if char == '-':
        count += 1
print(count)


