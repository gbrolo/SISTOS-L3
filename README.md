# SISTOS-L3
Universidad del Valle de Guatemala
Sistemas Operativos, S.10 2018 - Laboratorio 3

## Respuestas

### Ejercicio 1

1. ¿Cuántos procesos se crean en cada uno de los programas? En el primero se crean 16 procesos. En el segundo se crean tambien 16 procesos. Cabe destacar que no se contaron los PIDS iguales. En el segundo programa, hay 16 PIDS, pero sin repetir. Estos mismos procesos se repiten y hay 30 ocurrencias de procesos.

2. Explique cómo se crea cada proceso y qué sucede después. En el primer programa se crea un proceso. Este luego finaliza y cuando finaliza, se hace la llamada a la creacion del fork. Luego todos los demas forks son ejecutados simultaneamente. Luego el programa no finaliza por quee todavia hay procesos que fueron llamados simultaneamente, entonces estan siendo ejecutados en paralelo. En el segundo programa se ejecutan tres procesos distintos de forma simultanea y cuando finaliza el fork, se ejecuta el ultimo proceso del ciclo. Este crea nuevos procesos simultaneos y sucede lo mismo que en el primer programa.

### Ejercicio 2
1. ¿Cuál, en general, toma tiempos más largos? El programa no concurrente toma tiempos mas largos.

2. ¿Qué causa la diferencia de tiempo, o por qué se tarda más el que se tarda más? El no concurrente se tarda mas por que solamente un proceso es el encargado de realizar todas las iteraciones, para cada uno de los fors. En el programa concurrente, gracias a que se hace un ```WAIT```, cada uno de los fors se hace concurrentemente y cuando cada uno ya fue terminado por su parte, se finaliza el programa hasta que el ultimo for se haga.

3. Compare y describa el efecto de los cambios. Cuando son menos iteraciones, ```i = 1000```, el programa no concurrente es mas rapido que el concurrente. Cuando las iteraciones son mayores el programa concurrente es mejor.

### Ejercicio 3

1. ¿Qué tipo de cambios de contexto incrementa notablemente en cada caso, y por qué? Incrementan mas los cambios de contexto voluntarios en ambos casos, ya que al estar recibiendo inupt de IO, el SO tiene que tratar con esos cambios directamente, lo que hace que el contexto involuntario incremente.

2. En la segunda terminal, ejecute los dos programas y tome el tiempo en segundos que toma cada uno en terminar. El primero toma 15 segundos. Al segundo le toma 14 segundos.

3. Anote  el  número  de  cambios  de  contexto  de  cada  tipo  para  el  proceso  correspondiente  a  la ejecución de su programa. El primero tiene 1 de cada tipo. El segundo tiene 4 de cada tipo.

4. ¿Qué diferencia hay en el número de cambios de contexto de entre programas y entre tipos de cambio de contexto? ¿Por qué? El programa concurrente tiene mas cambios de contexto de ambos tipos que el no concurrente. Esto se debe a que el programa concurrente experimenta cambios voluntarios cada vez que se tiene que hacer un fork.

5. ¿A qué puede atribuir los cambios de contexto voluntarios realizados por sus programas? En el concurrente se debe a que las llamadas a fork por los hijos crean nuevos procesos, entonces cada vez que crean un proceso se olbiga a un cambio de contexto. En el programa no concurrente, el mismo proceso hace los tres ciclos, entonces solo existe ese cambio de contexto que se encarga de realizar todo.

6. ¿A   qué   puede   atribuir   los   cambios   de   contexto   involuntarios   realizados  por   sus programas? Se puede deber a que los otros procesos del sistema influyen en los procesos creados por los programas, entonces estos crean cambios de contexto involuntarios a los que los procesos de los programas deben luego acoplarse.

7. ¿Por  qué  el  reporte  de  cambios  de  contexto  para  su  programa  con fork()s muestra cuatro procesos, uno de los cuales reporta cero cambios de contexto? Muestra 4 por que el primero corresponde al proceso de la ejecucion del programa, el segundo se debe al primer fork, el tercero al segundo fork y el cuarto al ultimo fork. El segundo reporta cero cambios por que es el primer fork, entonces este dio a luz a los demas y es el que espero a que todos terminaran para finalizar el programa.

8. ¿Qué efecto percibe sobre el número de cambios de contexto de cada tipo? Los cambios voluntarios incrementan bastante, y dependiendo del programa se notan mas cambios. En el programa concurrente, los cambios son muchos mas.

### Ejercicio 4



#### Screenshot de la llamada
![alt text](https://github.com/gbrolo/SISTOS-L1/blob/master/3h.PNG)

#### Archivos de C
* [Ejercicio H](./ejercicio3h.c)
