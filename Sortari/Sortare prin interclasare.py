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
def mergesort(ls):
    if len(ls) <= 1:
        return ls
    else:
        mij = len(ls)//2
        lst = mergesort(ls[:mij])
        ldr = mergesort(ls[mij:])
        return interclasare(lst, ldr)

lista = [4,6,2,87,56,34,90,123,4,55,19]
print(mergesort(lista))