# Milestone 3 Reflection - Peter Boster - 11/17/2019

For me, this milestone was the most challenging, yet most fun and rewarding of all of the previous milestones and projects. This project challenged me because it required me to restructure my code to use a Pixel class and a two-dimensional vector of pixels to represnt the rgb data of a ppm image. This took me a while to figure out and implement and required me to essentially start from scratch, but wasn't that hard because I was able to reference the lecture code for the PpmDocument and Pixel Classes. After the code was restructured, for four out of the five image effects, I had to use many drawings and psuedocode snippets on paper before I felt like I could attempt to code the program. For the hoizontal flip however, I had an assumption that there might be a pre-built function that could reverse the order of a vector. As it turns out, after a couple of searches, I found a [C++ Reference Source](http://www.cplusplus.com/reference/algorithm/reverse/) that discusses a function called reverse() in the algorithms library that takes the beginning value and ending value of a vector as arguments, and returns that vector reversed. This allowed me to easily flip the image across the y-axis. 

The hardest image effect for me was the blur effect. This challenged me because I spaced out when coding the if checks for all the possible locations of pixels (corners, edges, center, etc...), I forgot to include every possible case that a pixel could be located. Because I forgot to include checks for values where the pixel was on the border, but not a corner, I kept recieving a *vector subscript out of range error* and it took me a couple hundred clicks and five breakpoints to figure out that I forgot a case which made [j - 1] out of range. After solving that issue however, my code ran perfectly and I got the correct output.

All in all, this milestone was my favorite part of the entire project so far, however I do really look forward to making a gui that can use buttons for the effects, and that redraws to show the image with the effect applied. I have been practicing a fair amount with the FLTK library by making small programs like a simple factorial, combination and permutaion calculator that is in a [FLTK Practice Repository](https://github.com/pab15/Gui-Practice-FLTK/tree/master/Factorial-Calculator) on my [Github Page](https://github.com/pab15).