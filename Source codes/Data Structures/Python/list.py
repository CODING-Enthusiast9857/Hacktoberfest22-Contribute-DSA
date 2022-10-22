n=int(input("Enter no. of elements to add in list : "))
l1=[]
for i in range(n):
    x=input("Enter {} element to add : ".format(i))
    l1.append(x)
print("List elements are :")
for j in l1:
    print(j)
    
print("Accessing element from the list by using indexing")
print(l1[1]) 
print(l1[2])

#Printing the largest number in the list 
largest = l1[0]
for i in l1:
    if i > largest :
      largest = i 
print(f"{largest} is the largest number from the list.")

#Printing the list in reverse order
reverse=[]
for i in l1[::-1]:
    reverse = reverse + [i]
print(reverse)



   
