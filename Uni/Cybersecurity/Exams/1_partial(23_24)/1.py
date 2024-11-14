# encryption method
def encryption(plain_text, key):
    encrypted_text = ""
    key_extended = (key * (len(plain_text) // len(key))) + key[:len(plain_text) % len(key)]

    for i in range(len(plain_text)):
        char_plain = plain_text[i]
        char_key = key_extended[i]

        offset = 97

        if char_plain.isalpha():
            # here is the most important part
            encrypted_char = chr((ord(char_plain) + ord(char_key) - 2 * offset)   % 26 + offset)
            
            encrypted_text += encrypted_char
        else:
            encrypted_text += char_plain

    return encrypted_text

def decryption(plain_text, key):
    decrypted_text = ""
    key_extended = (key * (len(plain_text) // len(key))) + key[:len(plain_text) % len(key)]

    for i in range(len(plain_text)):
        char_plain = plain_text[i]
        char_key = key_extended[i]

        offset = 97

        if char_plain.isalpha():
            # here is the most important part
            decrypted_char =  chr((ord(char_plain) - ord(char_key)) % 26 + offset)
            
            decrypted_text += decrypted_char
        else:
            decrypted_text += char_plain

    return decrypted_text

# key for the encryption
k = "tellmewhy"

# this is my message
flag = 'ltctfd{p-peye-mp-raee-ieu}'
        
c = encryption(flag, k)


print(decryption(c, k))
# print("Encrypted text:", c)

# OUTPUT: ltctfd{p-peye-mp-raee-ieu}