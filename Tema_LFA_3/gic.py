file = open("date", 'r')

lista_stari = file.readline().split()
alfabet = file.readline().split()
nrTransformari = int(file.readline())
listaTransformari = []

for i in range(nrTransformari):
    listaTransformari.append(list(file.readline().split()))
print(listaTransformari)


def verifica_cuvant(cuv):
    for j in range(len(cuv)):
        if cuv[j] not in alfabet:
            return 0
    return 1


def accepta_cuvant(cuv):
    global sem, lista_stari
    #print(cuv)
    for q in range(len(cuv)):
        if cuv[q] == "e":
            cuv = cuv.replace(cuv[q],'')
            break
    if cuv == cuvant:
        sem = 1
        #print("^")


def prelsol(x, k):
    #print(x[:k+1])
    cuvantx = "S"
    global listaTransformari
    for i in range(k+1):
        cuvantx = cuvantx.replace(listaTransformari[x[i]-1][0], listaTransformari[x[i]-1][1])
        accepta_cuvant(cuvantx)
        if x[i] == 4:
            break


def valid(x, k):
    for i in range(k + 1):
        if x[i] == 2:
            if 1 in x[i + 1:k + 1] or 2 in x[i + 1:k + 1]:
                return 0
    for i in range(k + 1):
        if x[i] in [3, 4]:
            if 2 not in x[:i]:
                return 0
    if 4 not in x:
        return 0
    if 2 not in x:
        return 0
    if x[0] != 1 and x[0] != 2:
        return 0
    return 1


def bkt(k):
    global x, n, nrTransformari, sem
    for v in range(1, nrTransformari + 1):
        if sem == 1:
            break
        x[k] = v
        if k == n - 1:
            if valid(x, k):
                prelsol(x, k)
        else:
            bkt(k + 1)


cuvant = input("Dati un cuvant: ")
sem = 0
n = len(cuvant)+2
x = [0 for i in range(n)]
if(len(cuvant)==0):
    print(1)
else:
    if(verifica_cuvant(cuvant)):
        bkt(0)
        print(sem)
    else:
        print("Cuvantul contine litere care nu apartin alfabetului")
