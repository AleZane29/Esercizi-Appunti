import base64

MORSE_CODE_DICT = { 'A':'.-', 'B':'-...',
                    'C':'-.-.', 'D':'-..', 'E':'.',
                    'F':'..-.', 'G':'--.', 'H':'....',
                    'I':'..', 'J':'.---', 'K':'-.-',
                    'L':'.-..', 'M':'--', 'N':'-.',
                    'O':'---', 'P':'.--.', 'Q':'--.-',
                    'R':'.-.', 'S':'...', 'T':'-',
                    'U':'..-', 'V':'...-', 'W':'.--',
                    'X':'-..-', 'Y':'-.--', 'Z':'--..',
                    '1':'.----', '2':'..---', '3':'...--',
                    '4':'....-', '5':'.....', '6':'-....',
                    '7':'--...', '8':'---..', '9':'----.',
                    '0':'-----', ', ':'--..--', '.':'.-.-.-',
                    '?':'..--..', '/':'-..-.', '-':'-....-',
                    '(':'-.--.', ')':'-.--.-'}

def base64tostring(text):
    return base64.b64decode(text).decode('utf-8', errors="ignore")

f = open('c:/Users/aless/Informatica/Esercizi-Appunti/Uni/Cybersecurity/Lesson2/zero_one.txt', "r")
str=f.read().replace(' ', '')
str = str.replace('ZERO', '0')
str = str.replace('ONE', '1')
result=''.join(chr(int(str[i*8:i*8+8],2)) for i in range(len(str)//8))
morse = base64tostring(result)
decoded = ''
for i in morse.split():
  decoded += list(MORSE_CODE_DICT.keys())[list(MORSE_CODE_DICT.values()).index(i)]
print(f"Decoded string: {decoded}")