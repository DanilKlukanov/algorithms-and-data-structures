def qsort(mass, s, r):
    if s <= r:
        ll, rr =  s, r
        x = mass[(s + r) // 2]
        while ll <= rr:
            while mass[ll] < x:
                ll = ll + 1
            while mass[rr] > x:
                rr = rr - 1
            if ll <= rr:
                mass[ll], mass[rr] = mass[rr], mass[ll]
                ll = ll + 1
                rr = rr - 1     
        qsort(mass, int(s), int(rr))
        qsort(mass, int(ll), int(r))  
    return mass
fin = open ("input.txt", "r" ) 
fout = open ("output.txt", "w" ) 
mass = [int(i) for i in fin.read().split()]
mass.pop(0)
fout.write(str(qsort(mass, 0, len(mass)-1)).replace('[', '').replace(']', '').replace(',',''))