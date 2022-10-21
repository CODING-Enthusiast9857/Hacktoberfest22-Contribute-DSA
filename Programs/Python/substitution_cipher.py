
# you know more about this cipher on this http://en.wikipedia.org/wiki/Substitution_ciphe

'''
Substitution cipher is a method of encrypting in which units of plaintext are replaced with the ciphertext, in a well defined manner.
Substitution can be done using a key.
The encrypted message (ciphertext) can be read by the receiver after performing the inverse substitution process
'''
def encrypt (plaintext, key= "dddddddddddddddd"):
  list1 = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
  
  key_1 = key*390
  k = len(key)
  p = len(plaintext)
  w = 0
  e = 0
  if (key.isalpha() == False):
      raise ValueError("Key cannot be empty.")
  else :
    i = 0
    list_plaintext=[]
    list_plaintext[:0]=plaintext
    encrypted_text = ""
  
    while (i < p):
      x = list1.index(key_1[i])
      y = list1.index(plaintext[i])
      list_plaintext[i] = list1[(x+y)%26]
      i= i+1
    return (encrypted_text.join(list_plaintext))     


def decrypt (ciphertext, key= "dddddddddddddddddddd"):
  list1 = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
  key_1 = key*100
  k = len(key)
  c = len(ciphertext)
  e=0
  w = 0
  if (key.isalpha() == False):
      raise ValueError("Key cannot be empty.")
  else :
      i = 0
      list_ciphertext=[]
      list_ciphertext[:0]=ciphertext
      decrypted_text = ""
  
      while (i < c):
        x = list1.index(key_1[i])
        y = list1.index(ciphertext[i])
        if ((y-x)<0):
          list_ciphertext[i] = list1[(y-x)+26]
        else :
          list_ciphertext[i] = list1[(y-x)]
     
        i= i+1
  return (decrypted_text.join(list_ciphertext))