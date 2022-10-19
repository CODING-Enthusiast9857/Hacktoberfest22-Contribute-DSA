#Importing the needed libraries
import numpy as np
import cv2 as cv

#reading the image
img_location = input("Enter the location of the image you want to blur(include file extention e.g .png): ")
image = cv.imread(img_location)

#Converting the image to a grayscale image
g_image = cv.imread(img_location, 0)

#Inverting the image
i_image = image.max() - g_image

#Blurring the image
b_image = cv.GaussianBlur(i_image, ksize = (15, 15), sigmaX = 0, sigmaY = 0)

#Pencil sketch the image
def pencil_sketch(x, y):
    return cv.divide(x, 255 - y, scale = 250)

p_image = pencil_sketch(g_image, b_image)
cv.imwrite('sketched_image.jpg', p_image) #Save a copy of the new image
cv.imshow('Pencil Sketched Image', p_image)
cv.waitKey()