def replace_chars(input_string, char_dict):
    result = ""
    for char in input_string:
        result += char_dict.get(char, char)
    return result

with open("C:/Users/aless/Informatica/Esercizi-Appunti/Uni/Cybersecurity/Exams/1_partial(22_23)/ciphertext.txt", "r") as file:
    cipher = ''.join(file.readlines())
    
counter={}

for i in cipher:
    if counter.get(i)!=None:
      counter[i]+=1
    else:
      counter[i]=1

cipher=cipher.replace("D", "s")
cipher=cipher.replace("M", "p")
cipher=cipher.replace("P", "r")
cipher=cipher.replace("X", "i")
cipher=cipher.replace("S", "t")
cipher=cipher.replace("T", "z")
dictionary={"L":"e", "H":"a", "E":"o", "O":"n", "A":"h", "D":"l", "Z":"c", "R":"u", "C":"m", "V":"f", "M":"m", "K":"h", "Y":"d", "W":"g"}
# print(sorted(counter.items(), key=lambda kv: kv[1], reverse = True))
# print(len(cipher))
print(replace_chars(cipher,dictionary))