import base64

file = "yxyxxyy yxyxxxx yxyxxyx yxxyxxy yxyxyxx yxyyxyx yxxxxyy yxyxyxx yxxxyyx yyyyxy yyyyxyy yyxxyxy yyxyyyx yyxxxyy yyyxxyx yyyyxxy yyyxxxx yyyxyxx yyxyxxy yyxyyyy yyxyyyx yyxxxx yyxxxx yyxxxx yyxxxx yyxxxx yyxxxy yyyyyxy"

file=file.replace("y", "1")
file=file.replace("x", "0")
vec = file.split(" ")
dec=""
for i in vec:
    dec+=chr(int(i,2))
    # dec+=chr(hex(file[i*7:i*7+7],2))
print(dec)

# decrypt=base64.b64decode(file).decode('utf-8', errors="ignore")
# print(decrypt)