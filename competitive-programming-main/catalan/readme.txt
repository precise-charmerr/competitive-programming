This code is a implementation of Catalan Numbers.
Problem statement is: https://www.oi.edu.pl/static/attachment/20110731/oi7/kod.html

Here we need to find nth binary tree where there size is k (k <= 19)

We are finding place of any string in ck and then recursively going in cx cy parts.

Also we are updating new place in cx and cy.

We are maintaining an array called fac(factor) which will tell how much a part of string will be updated i.e.
how many times we will add +1 to the string and remaining one.