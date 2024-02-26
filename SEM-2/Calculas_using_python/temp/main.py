
a=int(input("Enter a number:"))
b=int(input("Enter a number:"))
c=int(input("Enter a number:"))
if a>b and a>c:
    print(a,"is greatest")
elif b>a and b>c:
    print(b,"is greatest")
elif c>a and c>b:
    print(c,"is greatest")
else:
    print("All are equal.")
a=3+4j
print(a.real)
print(a.imag)
