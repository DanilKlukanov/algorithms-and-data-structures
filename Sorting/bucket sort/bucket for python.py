def list_merge(mass_ord):
    all=[]
    for lst in mass_ord:
        for el in lst:
            all.append(el)
    return all
def bucket(mass_ord, n):
    if n < 0:
        return mass_ord
    else:       
        rang = 123
        b = [[] for k in range(rang)]
        new_mass = []
        for i in range(len(mass_ord)):
            b[mass_ord[i][n]].append(mass_ord[i])
        for q in b:
            if q != []:
                new_mass.append(q)
        new_mass1 = list_merge(new_mass)
        n = n - 1
        return bucket(new_mass1, n)
fin = open('input.txt', 'r')
fout = open('output.txt', 'w')
mass_word = []
mass_ord = []

for line in fin.read().splitlines():
    mass_word.append(line)
del mass_word[0]

for i in mass_word:
    mass_ord.append([ord(j) for j in i])

n = len(mass_ord[0]) - 1 
merge_mass = (bucket(mass_ord, n))
non_nested_mass = list_merge(merge_mass)

a = []
for i in range(len(non_nested_mass)):
    a.append(chr(non_nested_mass [i]))

unit_mass =[a[i:i+3] for i in range(0, len(a), 3)]
for i in unit_mass:
    fout.write(''.join(i) + '\n')