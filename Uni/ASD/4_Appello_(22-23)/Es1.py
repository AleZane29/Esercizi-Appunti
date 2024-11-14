# Sviluppare un algoritmo Split (A,n) che dato in input l'array A[1..2n] dei valori delle proprietà e n, 
# verifica se le proprietà possano essere partizionate in n coppie, 
# tutte con lo stesso valore complessivo (di modo da assegnare una coppia di proprietà a ciascun figlio). 
# Si assume n > 0. Ad esempio, con n = 2, se A=[1,3,4,2] la risposta è positiva visto che le proprietà possono essere partizionate 
# nelle coppie 1,4 e 3,2, mentre se A=[1,3,5,2] la risposta è negativa.

def Split(A, n):
  A.sort() #In pseudo-codice implementare il MergeSort
  value = A[0]+A[2*n-1]
  for i in range(1,2*n):
    if(A[i]+A[2*n-1-i]!=value):
      return False
  return True


A = [1, 3, 2, 7, 5, 6 , 4, 4]
n=int(len(A)/2)
print(Split(A,n))