fin = open("input.txt", "r")
fout = open("output.txt", "w")
z = [int(i) for i in fin.read().split()]
del z[0]
l = []
h = 100
for i in range(int(h)):
    l.append(0)
for f in range(0, len(z)-1, 2):
    for i in range(z[f] - z[f+1], z[f+1] + z[f]):
        if i < 0:
            continue
        l[i] = l[i] + 1    
        if i == 99:
            break       
fout.write(str(max(l)))