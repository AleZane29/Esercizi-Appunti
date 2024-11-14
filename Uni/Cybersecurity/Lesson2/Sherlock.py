# Sherlock has a mystery in front of him. Help him to find the flag.

f = open('c:/Users/aless/Informatica/Esercizi-Appunti/Uni/Cybersecurity/Lesson2/challenge.txt', "r")
read=f.read()
str=''.join([c for c in read if c.isupper()])
str = str.replace('ZERO', '0')
str = str.replace('ONE', '1')
result=''.join(chr(int(str[i*8:i*8+8],2)) for i in range(len(str)//8))
print(result)