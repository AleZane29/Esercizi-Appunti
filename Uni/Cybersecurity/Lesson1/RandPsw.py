# Define a randomic password generator.
# The password should contain 10 characters.
# Type of characters: alphanumeric
import random
import string

psw=""
for i in range(10):
  psw+=random.choice(string.ascii_letters+string.digits)
print("Random PSW: "+psw)