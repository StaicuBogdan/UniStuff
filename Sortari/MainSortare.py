from math import log
import time
from copy import deepcopy as dc
import random as r

def bubblesort(numere):
    st = time.time()
    lista=dc(numere)
    l = len(lista)
    for i in range(l):
        for j in range(l - i - 1):
            if (lista[j] > lista[j + 1]):
                lista[j], lista[j + 1] = lista[j + 1], lista[j]
    et = time.time()
    return "Bubble time:",et-st

def countsort(numere):
    st = time.time()
    lista=dc(numere)
    nmax = max(lista)
    n = [0 for i in range(nmax + 1)]
    m = 0
    for element in lista:
        n[element] += 1
    for i in range(0, nmax + 1):
        while n[i] > 0:
            lista[m] = i
            n[i] -= 1
            m += 1
    et = time.time()
    return "Countsort time:",et-st

def interclasare(lst, ldr):
    i = j = 0
    rez = []
    while i < len(lst) and j < len(ldr):
        if lst[i] < ldr[j]:
            rez.append(lst[i])
            i += 1
        else:
            rez.append(ldr[j])
            j += 1
    rez.extend(lst[i:])
    rez.extend(ldr[j:])
    return rez
def mergesort(lista):
    if len(lista) <= 1:
        return lista
    else:
        mij = len(lista) // 2
        lst = mergesort(lista[:mij])
        ldr = mergesort(lista[mij:])
        return interclasare(lst, ldr)

def setup():
    d = {}
    for i in range(BASE):
        d[i] = []
    return d
def dicToList(d):
    l = []
    for values in d.values():
        for value in values:
            l.append(value)
    return l
def radix(lista):
    key = 1  # adica cifra unitatilor (abcd // key = d)
    st = time.time()
    for _ in range(digits):
        d = setup()
        for i in lista:
            d[(i // key) % BASE].append(i)
        lista = dicToList(d)
        key *= BASE
    et = time.time()
    return "Radix time:",et-st

def quicksort(numere):
    lista=dc(numere)
    less = []
    equal = []
    greater = []
    if len(lista) > 1:
        pivot = lista[0]
        for x in lista:
            if x < pivot:
                less.append(x)
            elif x == pivot:
                equal.append(x)
            elif x > pivot:
                greater.append(x)
        return quicksort(less)+equal+quicksort(greater)
    else:
        return lista

fisier_numere=open ("fisier_numere","w")
for i in range(int(input("How many numbers?"))):
    numar=str(r.randint(10000000,100000000))
    fisier_numere.write(numar)
    fisier_numere.write(' ')
fisier_numere=open("fisier_numere","r")

numere=fisier_numere.readline().split()

for i in range(len(numere)):
    numere[i]=int(numere[i])

print(bubblesort(numere))

print(countsort(numere))

st = time.time()
mergesort(numere)
et = time.time()
print("mergesort time: ", et - st)

BASE = 255
digits = (int(log(max(numere), BASE)) + 1)
print(radix(numere))

st2=time.time()
quicksort(numere)
et2=time.time()
print("quicksort time: ",et2-st2)

st2=time.time()
sorted(numere)
et2=time.time()
print("sortare python",et2-st2)