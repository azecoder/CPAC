# EXPLANATIONS OF SOLUTIONS

### PB - Alice, Bob and Chocolate 
* Problem link 		: [codeforces - 6C](http://codeforces.com/contest/6/problem/C)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/6C.cpp)
* Solution method	: Two pointers 
* Compexity			: O(N)

#### Explanation
First of all you need to define two pointers. 
1. First one is for Alice and it starts from first index ``` a_ind = 1 ```
2. Second one is for Bob and it starts from last index ``` b_ind = N ```

While the position of the Alice is less than the position of the Bob ``` while Alice.pos < Bob.pos ```
1. check if ate time of Alice is smaller than Bob's ``` if Alice.ate_time < Bob.ate_time ```
    - increase position of the Alice ``` Alice.pos++ ```
    - and add chocolate bar time to Alice's eating time ``` Alice.ate_time += ctime ```
2. else
    - decrease position of the Bob ``` Bob.pos-- ```
    - and add chocolate bar time to Bob's eating time ``` Bob.ate_time += ctime ```

At the end, check if Alice and Bob stay in the same position and there is only one chocolate bar, then give the chocolate bar to the player who eats in less time.
```
if Alice.pos == Bob.pos and not_ated[chocolate]
    if Alice.ate_time <= Bob.ate_time
        Alice.ate_time += ctime 
    else
        Bob.ate_time += ctime
```
_____
### PB - Number of Ways
* Problem link 		: [codeforces - 466C](http://codeforces.com/contest/466/problem/C)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/466C.cpp)
* Solution method	: Dynamic programming
* Compexity			: O(N)

#### Explanation
First of all we must check if we can divide this array in three part or not. So that, we get sum of all elements in array.
```
for i from 1 to N
    read arr[i]
    sum += arr[i]
```
if sum of the all elements is equal to S, then sum of each of the 3 part must be equal to S/3. Therefore if S is not divided by 3 then answer is 0.
```
if S mod 3 > 0
    print 0
    exit
```
Let's start to iterate for first part. We start check if sum of j to N is equal to apart sum. And we create a new array and save the points which sum of the elements from this point to N is equal to S/3
```
cnt = aray(N)   // is a new array for saving points - default is 0
psum = sum/3    // part sum
csum = 0        // current sum
for i from N to 1
    csum += arr[i]
    if csum == psum
        cnt[i] = 1
``` 
_____
### PB -  
_____
### PB -  