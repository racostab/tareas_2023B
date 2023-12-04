# max process

Este programa entrega la cantidad máxima de procesos que puede crear un usuario.
La cantidad máxima de procesos que puede crear un usuario se encuentra definido en el archivo: 
/etc/security/limits.conf
En este archivo se debe especificar a que usuario o grupo se le aplicaran las restriciones. Además, se debe especificar que tipo de recurso que se limitará.
Para mi caso se agrego la siguiente linea:
vbpc hard nproc 10000
Lo cual, limita a 1000 procesos al usuario vbpc.


# Compilación

gcc -o max_process max_process.c

# Ejecución

./max_process

