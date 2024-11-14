import string

enc="MKXU IDKMI DM BDASKMI NLU XCPJNDICFQ! K VDMGUC KW PDT GKG NLKB HP LFMG DC TBUG PDTC CUBDTCXUB.K'Q BTCU MDV PDT VFMN F WAFI BD LUCU KN KB WAFI GDKMINLKBHPLFMGKBQDCUWTMNLFMFMDMAKMUNDDA"

freq={}
for i in enc:
  if i in freq:
    freq[i]+=1
  else:
    freq[i]=1

sortFreq = sorted(freq.items(), key=lambda kv: kv[1], reverse = True)
print(sortFreq)

enc=enc.replace("K", "i")
enc=enc.replace("F", "a")
enc=enc.replace("P", "y")
enc=enc.replace("Q", "m")
enc=enc.replace("U", "e")

enc=enc.replace("B", "s")
enc=enc.replace("T", "u")
enc=enc.replace("C", "r")

enc=enc.replace("N", "t")
enc=enc.replace("L", "h")

enc=enc.replace("D", "o")

enc=enc.replace("W", "f")

enc=enc.replace("A", "l")
enc=enc.replace("I", "g")

enc=enc.replace("M", "n")

enc=enc.replace("X", "c")
enc=enc.replace("S", "v")
enc=enc.replace("J", "p")
enc=enc.replace("V", "w")
enc=enc.replace("G", "d")
enc=enc.replace("H", "b")
print(enc)