cuvant = input("Dati un cuvant:")

fisier = open("fisier", 'r')

alfabet = fisier.readline()
noduri = fisier.readline().split()
nr_muchii = int(fisier.readline())
nod_initial = fisier.readline()
lista_stari_finale = fisier.readline().split()
dictionar = {}


def accepta_cuvant(cuvant, nod, listastarifinale):
    sem = 0
    print(cuvant)
    print(dictionar)
    for i in cuvant:
        for lista in dictionar[nod]:
            if lista[0] == i:
                nod = lista[1]
                sem = 1
                break
            else:
                sem = 0
        if sem == 0:
            break
    print(nod)
    if nod in listastarifinale and sem==1:
        return 1
    return 0


def cuvant_apartine_alfabet(x):
    for litera in x:
        if litera not in alfabet:
            return 0
    return 1


for nod in noduri:
    dictionar[str(nod)] = []

for i in range(nr_muchii):
    tranzitie = fisier.readline().split()
    dictionar[tranzitie[0]].extend([[tranzitie[1], tranzitie[2]]])

cuv = []
for c in cuvant:
    cuv.append(c)

if len(cuv) > 0:
    if cuvant_apartine_alfabet(cuv) == 0:
        print("Cuvantul nu este acceptat, contine litere care nu apartin alfabetului.")
    else:
        if accepta_cuvant(cuv, nod_initial.strip(), lista_stari_finale) == 1:
            print("Cuvant acceptat.")
        else:
            print("Cuvant respins.")
else:
    if len(cuv) == 0 and (nod_initial.strip() in lista_stari_finale):
        print("Cuvantul are lungime 0, dar e acceptat, starea initiala fiind si stare finala.")
    else:
        print("Cuvantul are lungime 0, dar starea initiala nu e si finala, cuvant respins.")
