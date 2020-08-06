fin  = open("linear.in", "r")
fout = open("linear.out", "w")
#main----------------------------------------------
main_mass = [int(i) for i in fin.read().split()]
n = main_mass[0]
mass_times = main_mass[(main_mass[0]*2) + 2:]
time = []
cor = main_mass[1 : (main_mass[0]*2) + 1 : 2]
massiv_s_n = main_mass[0 : (main_mass[0]*2) + 1 : 2]
quantum = massiv_s_n[1:len(massiv_s_n)] 
#counting time-------------------------------------
if len(quantum) % 2 == 0:
    for i in range(len(quantum)-1):
        if quantum[i+1]<0 and quantum[i]>0:
            time.append(abs((cor[i+1] - cor[i])/2))
elif len(quantum) % 2 != 0:
    for i in range(len(quantum)-1):
        if quantum[i]>0 and quantum[i+1]<0:
            time.append(abs((cor[i+1] - cor[i])/2))
time.sort()
#counting and output-------------------------------
i = 0
for moment in mass_times:
    while i < len(time) and moment >= time[i]:
        i += 1
    fout.write(str(n - (i * 2)) + "\n")