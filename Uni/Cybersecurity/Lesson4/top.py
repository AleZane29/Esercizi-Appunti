#!/usr/bin/env python3
import random
import sys
import time

cur_time = str(time.time()).encode('ASCII')
random.seed(cur_time)

# msg = input('Your message: ').encode('ASCII')
# key = [random.randrange(256) for _ in msg]
# c = [m ^ k for (m,k ) in zip(msg + cur_time, key + [0x88]*len(cur_time))]

# with open(sys.argv[1], "wb") as f:
#     f.write(bytes(c))

with open('C:/Users/aless/Informatica/Esercizi-Appunti/Uni/Cybersecurity/Lesson4/top_secret.txt', "rb") as f:
    str=f.read()
sec_time = str[-len(cur_time):]
dec_time = ''.join([chr(m ^ k) for (m, k) in zip(sec_time, [0x88]*len(cur_time))])
print(sec_time)
