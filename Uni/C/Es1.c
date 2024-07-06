#include <stdio.h>
#include <>
#include <basic/matrix.h>

/*
* Scrivete una funzione che verifichi se una matrice sia ortogonale.
* Una matrice quadrata si dice ortogonale se la sua trasposta coincide con la sua inversa. 
* In altre parole, se la moltiplicazione tra la matrice e la sua trasposta produce una matrice identità, 
* allora la matrice è ortogonale.
* 
* Esempio:
* |a b|   x  |a c|  =  |1 0|
* |c d|      |b d|     |0 1|
*            
*
* La funzione deve restituire 1 se la variabile è ortogonale o se 0 non è ortogonale.
* Dato che stiamo lavorando con double, utilizzeremo una tolleranza di 0.001 sui valori della matrice identità.
*
* Esempio:
* 0.999 = 1
* 1.001 = 1
*
* Potete utilizzare le funzioni già presenti nella libreria per risolvere l'esercizio 
* (ne abbiamo aggiunte alcune, andate a vedervi i file .h)
*/

int main()
{
    // Per testare più velocemente il vostro algoritmo potete 	
    // usare la matrice sotto (modificandola secondo le vostre necessità)
    // invece di leggerla da input con scanf. Quando siete pronti a
    // consegnare potete ricommentare le 2 righe seguenti.

    /*int dim = 3;
    double mat1[3][3] = {0.3334, 0.6667, 0.6667, 0.6667, 0.3334, -0.6665, -0.6665, 0.6667, -0.3332};*/

    // creaimo e instanziamo le variabili di supporto per la dimensione della matrice
    int dim;
    scanf("%d", &dim);

    // definiamo ed instanziamo la matrice
    double mat1[dim][dim];
    leggi_array_double(*mat1, dim*dim);

    // verificare se la matrice è ortogonale

    // stampare il risultato
    if (res == 1)
        printf("Matrice ortogonale");
    else
        printf("Matrice non ortogonale");

    return 0;
}