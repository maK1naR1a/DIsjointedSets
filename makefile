# Ejercicio 3 
cArboles:prueba.c rArboles/conjuntos.o 
	gcc -g prueba.c -DARBOLES rArboles/conjuntos.o -o cArboles
rArboles/conjuntos.o: rArboles/conjuntos.c rArboles/conjuntos.h
	gcc -c -g rArboles/conjuntos.c -o rArboles/conjuntos.o
# Ejercicio 4, 5 y 6
#  ....

limpiar:
	rm c*
