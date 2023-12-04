#	Autor: Cureño Contreras Erick Brandon
#	Ejecución: python3 fork.py

import os

pid = os.fork()

if pid == -1:
    print("Error de creación")
elif pid == 0:
    print(f"PID del hijo: {os.getpid()}")
else:
    print(f"PID del padre: {os.getpid()}")