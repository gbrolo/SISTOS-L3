# SISTOS-L3
Universidad del Valle de Guatemala
Sistemas Operativos, S.10 2018 - Laboratorio 3

## Codigo de C
En la carpeta ```/code```.

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

1. ¿Qué significa la Z, y a qué se debe? Esa Z corresponde a la columna de estado del proceso y significa que el proceso es un proceso zombie.

2. ¿Qué sucede en la ventana donde ejecutó su programa? Se para la ejecucion del programa.

3. ¿Quién es el padre del proceso que quedó huérfano? No tiene padre. El proceso se queda como ```<defunct>``` con el flag Z.

### Ejercicio 5

1. ¿Qué diferencia hay en realizar comunicación usando memoria compartida en lugar de usando un archivo común y corriente? En el modelo de memoria compartida, multiples workers operan bajo los mismos datos. De la otra forma, se obliga a que los workers se comuniquen a traves de otros sistemas, como mensajeria y archivos. Esto mantiene a todos separados, para que asi ningun trabajador pueda modificar los datos de otro. 

2. ¿Por qué no se debe usar el file descriptor de memoria compartida recibido de otra instancia para realizar el mmap? Porque cuando se utiliza un archivo mappeado compartido, los cambios iniciados por un solo proceso o por varios procesos se reflejan de nuevo al archivo original, entonces podría ocurrir que el mappeo arruine la ejecucion del proceso padre al compartirle al otro proceso las mismas localidades de memoria sobre las que se encuentra trabajando. 

3. ¿Es posible enviar el output de un programa ejecutado con exec a otro proceso por medio de un pipe? Investigue y explique cómo funciona esto en la terminal (e.g., ls | less). Se tendría que crear un pipe desde el proceso padre hacia el hijo y luego redirigir el standard output y el error output usando ```dup``` o ```dup2``` hacia el pipe, lo que hara que el proceso padre lea desde el pipe. 

4. ¿Cómo puede asegurarse de que ya se ha abierto un espacio de memoria compartida con un nombre determinado? Investigue y explique errno. ¿Qué pasa si se ejecuta shm_unlink cuando hay procesos que todavía están usando la memoria compartida? Pueden usarse los comandos ```ipcs -m```, ```ipcs -pm```. Errno corresponde a los errores del sistema, a los que comunmente se les asocia un numero de error. Puede ejecutarse ```shm_unlink``` pero los datos del archivo permaneceran hasta que el nombre desaparezca y el ultimo proceso que lo este usando deje de utilizarlo. 

5. ¿Cómo puede referirse al contenido de un espacio en memoria al que apunta un puntero? Observe que su programa deberá tener alguna forma de saber hasta dónde ha escrito su otra instancia en la memoria compartida para no sobre escribirle. El puntero no es suficiente por si solo, se necesitaria saber a que proceso pertenece el puntero, por esto se necesitaria obtener el pid del programa que usa el espacio. 

6. Imagine que una ejecución de su programa sufre un error que termina la ejecución prematuramente, dejando el espacio de memoria compartido abierto y provocando que nuevas ejecuciones se queden esperando el file descriptor del espacio de memoria compartida. ¿Cómo puede liberar el espacio de memoria compartida “manualmente”? Primero podria verse la memoria compartida con ```ipcs``` y luego de identificar el segmento, se podria borrar con ```ìpcrm```. 

7. Observe que el programa que ejecute dos instancias de ipc.c debe cuidar que una instancia no termine mucho antes que la otra para evitar que ambas instancias abran y cierren su propio espacio de memoria compartida. ¿Aproximadamente cuánto tiempo toma la realización de un fork()? Investigue y aplique usleep. El tiempo de un fork puede variar dependiendo del tamanio del espacio virtual de direcciones, pero por lo general, un fork es rapido y toma tiempos con orden de microsegundos. 

#### Screenshot de la llamada
### Screenshots
![1](https://github.com/gbrolo/SISTOS-L3/blob/master/img/1.PNG)
![2](https://github.com/gbrolo/SISTOS-L3/blob/master/img/2.PNG)
![3](https://github.com/gbrolo/SISTOS-L3/blob/master/img/3.PNG)
![4](https://github.com/gbrolo/SISTOS-L3/blob/master/img/4.PNG)
![5](https://github.com/gbrolo/SISTOS-L3/blob/master/img/5.PNG)
![6](https://github.com/gbrolo/SISTOS-L3/blob/master/img/6.PNG)
![7](https://github.com/gbrolo/SISTOS-L3/blob/master/img/7.PNG)
![8](https://github.com/gbrolo/SISTOS-L3/blob/master/img/8.PNG)
![9](https://github.com/gbrolo/SISTOS-L3/blob/master/img/9.PNG)
![10](https://github.com/gbrolo/SISTOS-L3/blob/master/img/10.PNG)
![11](https://github.com/gbrolo/SISTOS-L3/blob/master/img/11.PNG)
![12](https://github.com/gbrolo/SISTOS-L3/blob/master/img/12.PNG)
![13](https://github.com/gbrolo/SISTOS-L3/blob/master/img/13.PNG)
