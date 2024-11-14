def xor_two_str(a,b):
    s=''
    for x, y in zip(a, b):
        s+=(chr(ord(x)^ord(y)))
    return s

def find_key(enc, keyLength):
  i=0
  arr=[]
  frq=0
  for x in range(keyLength):
    arr.append(enc[x])
  for i in range(len(enc)):
    if enc[i] == arr[i%keyLength]:
      frq+=1
  return frq

def hex2dec(text):
    res = []
    for i in range(len(text)//2):
        #get the current pair of hex
        curr = text[i*2:(i+1)*2]

        #convert to int
        res.append(int(curr, 16))

    return res

with open('C:/Users/aless/Informatica/Esercizi-Appunti/Uni/Cybersecurity/Lesson4/encrypted.txt', "r") as f:
    file=f.read()

str = hex2dec(file)

freq={}
for keyLength in range(1, 16):
  freq[keyLength]=find_key(str, keyLength)
sortFreq = sorted(freq.items(), key=lambda kv: kv[1], reverse = True)
print(str)
