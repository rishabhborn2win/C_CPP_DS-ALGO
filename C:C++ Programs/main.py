num = int(input("Enter a number: "))
while(num<100):
    print("Please enter a Number which is more then three digits")
    num = int(input("Enter a number: "))
else:
    print(num%10)