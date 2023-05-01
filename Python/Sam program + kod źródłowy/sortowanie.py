#KOD OPARTY NA MATERIALE PANA MIROSŁAWA ZELENTA.
#WERSJA W PYTHONIE.

import time, random

def sortowanieBabelkowe(tablica, ile):
    temp = 0;

    for i in range(1, ile,1):
        for j in range(ile-1, 1, -1):
            if tablica[i] < tablica[j-1]:
                temp = tablica[i]
                tablica[i] = tablica[j]
                tablica[j] = temp

def sortowanieSzybkie(tablica2, lewy, prawy):
    if(lewy >= prawy):
        return
    pivot = tablica2[(lewy + prawy) // 2]
    p = lewy - 1
    q = prawy + 1
    while(1):
        while(1): #w praktyce do momentu(tablica2[++p] < pivot)               
            p += 1
            if(tablica2[p] >= pivot):
                break
        while(1): #w praktyce do momentu(tablica2[--q] < pivot)                
            q -= 1
            if(tablica2[q] <= pivot):
                break
        if(p >= q):
            break
        temp = tablica2[p]
        tablica2[p] = tablica2[q]
        tablica2[q] = temp
                
    sortowanieSzybkie(tablica2, lewy, q)
    sortowanieSzybkie(tablica2, q+1, prawy)

tablica = []
tablica2 = []
czas = 0

ile = int(input("Podaj, ile elementow ma ta tablica: "))

for i in range(0, ile, 1):
    tablica.append(random.randint(1, 100000))
    #print(tablica[i], sep = " ", end = " ")

for i in range(0, ile, 1):
    tablica2 = tablica

##print("Przed posortowaniem\n")
##for i in range(0, ile, 1):
##    print(tablica2[i], sep = " ", end = " ")

print("\nSortuje teraz babelkowo. Prosze czekac!\n")

start = time.time()
sortowanieBabelkowe(tablica, ile)
stop = time.time()
czas = stop - start

print("Czas trwania sortowania tym sposobem: ", czas, "s.")

print("\nSortuje teraz szybko. Prosze czekac!\n")

start = time.time()
sortowanieSzybkie(tablica2, 0, ile-1)
stop = time.time()
czas = stop - start

print("Czas trwania sortowania tym sposobem: ", czas, "s.")

##print("Po posortowaniu\n")
##for i in range(0, ile, 1):
##  print(tablica2[i], sep = " ", end = " ")

input()
