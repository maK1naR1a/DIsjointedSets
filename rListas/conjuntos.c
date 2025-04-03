#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"

/// Incluir aqui las funciones que implementan las tres operaciones básicas 
/// en la representación de CONJUNTOS DISJUNTOS mediante LISTAS
/// ......................................................................void crea(


void crea(particion P)
{
    int i;
    for (i=0;i<MAXIMO;i++)
    {
        P[i].primero = (tipoCelda *) malloc(sizeof(tipoCelda));
        P[i].primero->elemento = i;
        P[i].primero->sig = NULL;
        P[i].ultimo = P[i].primero;
    }
}

tipoConjunto buscar(tipoElemento x, particion P)
{
    int i;
    tipoCelda *aux;

    for (i=0;i<MAXIMO;i++)
    {
        aux = P[i].primero;
        while (aux != NULL)
        {
            if (aux->elemento == x) return i;
            aux = aux->sig;
        }
    }
    return -1; // No encontrado
}

int unir(tipoConjunto x, tipoConjunto y, particion P)
{
    tipoCelda *aux;

    if (x == y) return 0; // No se unen

    // Buscamos el representante de la clase de equivalencia de x
    int i = buscar(x,P);
    if (i == -1) return -1; // No encontrado

    // Buscamos el representante de la clase de equivalencia de y
    int j = buscar(y,P);
    if (j == -1) return -1; // No encontrado

    // Unimos las listas
    P[i].ultimo->sig = P[j].primero;
    P[i].ultimo = P[j].ultimo;
    P[j].primero = NULL;
    P[j].ultimo = NULL;

    return 1; // Unido correctamente
}

void verParticion(particion P)
{
  int i;
  tipoCelda *aux;

  for (i = 0; i < MAXIMO; i++)
  {
    aux = P[i].primero;
    if (aux != NULL)
      printf("\n\nClase equivalencia representante %d: ", i);
    while (aux != NULL)
    {
      printf("%d ", aux->elemento);
      aux = aux->sig;
    }
  }
}

void verClaseEquivalencia(tipoElemento x,particion P)
{
  int representante;
  tipoCelda *aux;
  
    representante = buscar(x,P);
    printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x,representante);
    aux = P[representante].primero;
    while (aux)
        { printf(" %d ",aux->elemento);
          aux=aux->sig;
        }
    printf("\n\n");
}
