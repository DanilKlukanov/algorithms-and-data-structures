fin = open("input.txt", "r")
fout = open("output.txt", "w")

pervai = ' '.join(fin.readline()).split()
vtorai = ' '.join(fin.readline()).split()
Field =[[0] * (len(pervai) + 1) for i in range(len(vtorai) + 1)] 

for i in range(1, len(vtorai) + 1):
    for j in range(1, len(pervai) + 1):
        if pervai[j - 1] == vtorai[i - 1]:
            Field[i][j] = Field[i - 1][j - 1] + 1
        else:
            Field[i][j] = max(Field[i - 1][j], Field[i][j - 1])

print(Field)

z = ''
x = len(vtorai)
y = len(pervai)
while x > 0 and y > 0:
    if vtorai[x - 1] == pervai[y - 1]:
        z = pervai[y - 1] + z
        x = x - 1
        y = y - 1
    elif Field[x - 1][y] >= Field[x][y - 1]:
        x = x - 1
    else:
        y = y - 1
fout.write(z)