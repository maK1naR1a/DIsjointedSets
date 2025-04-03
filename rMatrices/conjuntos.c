#include "conjuntos.h"
#include <stdio.h>
/// Incluir aqui las funciones que implementan las tres operaciones básicas 
/// en la representación de CONJUNTOS DISJUNTOS mediante MATRICES
/// ......................................................................

void crea(particion P)
{
    int i;
    for (i=0;i<MAXIMO;i++)
        P[i]=i; // Inicializa cada elemento como su propio representante
}

tipoConjunto buscar(tipoElemento x, particion P)
{
    return P[x]; // Devuelve el representante del elemento x
}

int unir(tipoConjunto x, tipoConjunto y, particion P)
{
    int i;
    int rX = buscar(x,P);
    int rY = buscar(y,P);

    if (rX != rY) // Si son diferentes representantes
    {
        for (i=0;i<MAXIMO;i++)
            if (P[i] == rY) // Cambia el representante de la clase de equivalencia de y
                P[i] = rX;
        return 1; // Unión exitosa
    }
    return 0; // No se unieron puesto que ya estaban unidos
}

//
// Función auxiliar para ver contenido de Partición 
//
void verParticion(particion P)
{ 
    int i;

    printf("\n");
    for (i =0;i<MAXIMO;i++) printf("|%2d",P[i]);
    printf("| contenido  vector\n");
    for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices vector\n\n");
}
