# Define a simple calculator.
# The user uses the terminal and it has three variables.
#  - input1: first integer number
#  - input2: second integer number
#  - type of operation: a number associated to the operation
#     (e.g., 0 for the addition)

num1 = int(input("Enter a number:"))
num2 = int(input("Enter a number:"))
operation = int(input("Enter operation:"))
if(operation==0):
  print(f"Result:{num1+num2}")
elif(operation==1):
  print(f"Result:{num1-num2}")
elif(operation==2):
  print(f"Result:{num1*num2}")
elif(operation==3):
  print(f"Result:{num1/num2}")