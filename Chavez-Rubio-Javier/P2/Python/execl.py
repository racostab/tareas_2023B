# $ python3 execl.py

import subprocess

arg1 = "1234567890"
pathname = "./hello"

result = subprocess.run([pathname, pathname, arg1], capture_output=True)

if result.returncode == 0:
    print(result.stdout.decode())
else:
    print(f"Error: {result.stderr.decode()}")
