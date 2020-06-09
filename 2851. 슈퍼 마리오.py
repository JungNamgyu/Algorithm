mush = []
for i in range(10):
    mush.append(int(input()))

for i in range(1, 10):
    mush[i] += mush[i-1]

Max = 0
for i in range(1, 10):
    if abs(100 - mush[i]) <= abs(100 - mush[Max]) : Max = i

print(mush[Max])
