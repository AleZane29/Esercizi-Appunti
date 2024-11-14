import base64


def base64tostring(text):
    return base64.b64decode(text).decode('utf-8', errors="ignore")

enc='fYZ7ipGIjFtsXpNLbHdPbXdaam1PS1c5lQ=='
enc=base64tostring(enc)

def ceasar_cracker(text, from_ = -30, to_=+30):
    for i in range(from_, to_): #possible keys [-30, 30]
        #decode
        curr_step = ''.join([chr(ord(c) + i) for c in text])

        #print
        print(f"Step={i}\t{curr_step}")

ceasar_cracker(enc)