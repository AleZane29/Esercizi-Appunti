# original data: "El Psy Congroo"
# encrypted data: "IFhiPhZNYi0KWiUcCls="
# encrypted flag: "I3gDKVh1Lh4EVyMDBFo="

# The flag is a composition of two names (two animals (?)).
import base64


def base64tostring(text):
    return base64.b64decode(text).decode('utf-8', errors="ignore")
def xor_two_str(a,b):
    s=''
    for x, y in zip(a, b):
        s+=(chr(ord(x)^ord(y)))
    return s

s="IFhiPhZNYi0KWiUcCls="
f="I3gDKVh1Lh4EVyMDBFo="
key=xor_two_str("El Psy Congroo",base64tostring(s))

print(xor_two_str(key,base64tostring(f)))