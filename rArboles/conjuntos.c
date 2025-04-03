#include "conjuntos.h"
#include <stdio.h>


/// Incluir aqui las funciones que implementan las tres operaciones básicas 
/// en la representación de CONJUNTOS DISJUNTOS mediante ÁRBOLES
/// ......................................................................

void crea(particion P)
{ 
    int i;
    for (i=0;i<MAXIMO;i++)
    {
        P[i] = i; // Inicializa cada elemento como su propio representante
    }
}


tipoConjunto buscar(tipoElemento x, particion P)
{
    int i = x;
    while (P[i] != i) // Busca el representante
    {
        i = P[i];
    }
    return i; // Retorna el representante
} 

int unir(tipoConjunto x, tipoConjunto y, particion P)
{
    int repX = buscar(x, P); // Busca el representante de x
    int repY = buscar(y, P); // Busca el representante de y

    if (repX == repY) return 1; // Ya están en la misma clase

    P[repY] = repX; // Une las clases
    return 1; // Unión exitosa
}

//
// Función auxiliar para ver contenido de Partición 
//
void verParticion(particion P)
{ int i;
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf("|%2d",P[i]);
    printf("| contenido  vector\n");
    for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices vector\n\n");
}
