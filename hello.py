import subprocess
import time

try:
    for i in range(100):
        subprocess.run(['say', 'mac is talking'])
except KeyboardInterrupt:
    print("Loop stopped!")
