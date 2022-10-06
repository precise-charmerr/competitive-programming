First code is of Problem statement: https://projecteuler.net/problem=24

First problem describes how can we find xth permutation : Basic idea is we keep on removing t! t-1! t-2! and so on from x...
Then we find which number comes in that position like 1234, 2134 have a difference of 3! -> 6 because 2 is at a place of 1..
Similarly we will find numbers with difference of whats expected and whats is there and finally we will maintain a vector{1, 2, 3, ...t}
and lets say we got vector {a, b, c,d...} which shows difference of actual position and expected position ...
Finally we will find numbers from vectors and after finding them we will keep on removing them as their work is done....

------------------------------

Second Code is of problem statement: https://codeforces.com/contest/501/problem/D

Good explaination of this question, permutation and factoradic is: https://blatherstrike.blogspot.com/2020/03/treesbinary-lifting-501-d-misha-and.html

In this question we are given two permutations and we have to add their order and find the new order
steps are:
1. find id of both permutations (Note that id can can be of two forms one as (1 or 2 or 3..) other is factoradic which tells expected positions of number)
2. Add both ids, let it be s.
3. now we have to find s % n! , in case of factoradic we can remove extra from each number as explanied in the blog.
4. again find permutation from id
5. we can find that permutation with two ways 1. ordered set 2. using segment tree(Code is using both ways refer there).

more about step 5:
in ordered set : we can use 
1. find_by_order(k) . and it will return iterator at kth position 
2. order_of_key(x): it will return count of values which are strictly less than x.

in seg_tree , 
for order_of_key function we can normally use seg tree.
for find_by_order function(k) we can check if the number we are finding is residing on left or right ... if its left just search with k ... if its right search with (k - value_on_left)... and finally return when its base condition..

