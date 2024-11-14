import string

enc='vhixoieemksktorywzvhxzijqni'
key='caesar'

def ceasar_cracker(text):
        i=0
        curr_step = ''
        for c in text:
          print(c, string.ascii_lowercase.index(c), string.ascii_lowercase.index(key[i%len(key)]))
          curr_step+=string.ascii_lowercase[(string.ascii_lowercase.index(c) - string.ascii_lowercase.index(key[i%len(key)]))%len(string.ascii_lowercase)]
          i+=1

        #print
        print(curr_step)

ceasar_cracker(enc)