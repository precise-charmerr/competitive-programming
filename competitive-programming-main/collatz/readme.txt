This code is a implementation of Collatz Numbers.
Problem statement is: https://projecteuler.net/problem=14

Here we need to find any number which forms longest chain(collatz series) under one million.

One code if brute force which goes for every number and since longest chain will be arnd 525 time complexity will be: 106 * 500 (approx.)

Other is kind of Dp-ish approach which stores value of a chain and also update all the numbers appearing in the chain thus taking less time
Solution is bit recursive and recursion ends where we find any value which is -1.