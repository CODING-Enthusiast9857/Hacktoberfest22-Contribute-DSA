n=int(input("Enter no. of elements to add in list : "))
l1=[]
for i in range(n):
    x=input("Enter {} element to add : ".format(i))
    l1.append(x)
print("List elements are :")
for j in l1:
    print(j)