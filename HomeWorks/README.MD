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
Let's start to iterate for first part. We start check if sum of j to N is equal to apart sum. And we create a new array and save the points which sum of the elements from this point to N is equal to S/3.
```
cnt = aray(N)   // is a new array for saving points - default is 0
psum = sum/3    // part sum
csum = 0        // current sum, default is 0
for i from N to 1
    csum += arr[i]
    if csum == psum
        cnt[i] = 1
``` 
Now we use cnt array for shows how much time we get same sum with S/3 between current index and N. 
```
for i from N - 1 to 1
    cnt[i] += cnt[i+1]
```
In final part of the solution, for each prefix [1..i] of the initial array we just add cnt[i+2] to answer if sum[1..i] equals to S/3
```
csum = 0        // current sum, default is 0
for i from 1 to N - 2
    csum += arr[i]
    if csum == psum
        result += cnt[i+2]
```
_____
### PB - Fox And Names
* Problem link 		: [codeforces - 510C](http://codeforces.com/contest/510/problem/C)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/510C.cpp)
* Solution method	: Graph, DFS
* Compexity			: O(N^2)

#### Explanation
Firstly, in my solution I need a some changes as 'charaters to numbers' and 'numbers to characters'. So that I create two methods.

Assume the alphabet [ A to Z ] as an array [ 1 to N ]
```
int chartoint(char c)
    return int(c - 'a' + 1)

char inttochar(int i)
    return char(i + 'a' - 1)
``` 
After that start from first string and check each string with next one. And find the first different characters for this two string and save this characters in list. if there is not any different characher for these two string and next string is a substring of current string then it is impossible to create new alphabet.
```
MAIN()
    for i from 1 to N - 1
        CHECK(i)

CHECK(int x)
    string A = str[x]           // current string
    string B = str[x + 1]       // next string

    int min_size = min(A.size, B.size)  // minimum size for two strings
    for i from 0 to min_size - 1        // for each index
        if A[i] != B[i]                 // we check if charachers are different
            change_list[B[i]].add(A[i]) // add this character to list
            return
    
    // it means that A[0..min_size] == B[0..min_size]
    if A.size > B.size          // it means B is a substring of A
        print "Impossible"      // so it is impossible
        exit
```
Now, we have an alphabet and we have a change list for characters. So we start from a to z and do dfs.. In dfs, we will change characters with new one from the change list. But we check if we change the same character before it means that we will get a cycle in dfs and it means that it is impossible to create a new alphabet.
```
MAIN()
    for i from 1 to 26 
        if not visited[i]
            DFS(i)

DFS(int x)          // x is a curent character
    visited(x)
    used(x)
    for i from 0 to change_list[x]  // get all characters from list to change
        new_x = change_list[x][i]   // it is new charachter 
        if used(new_x)              // we use this new character before
            print "Impossible"
            exit
        if not visited(new_x)
            DFS(new_x)
    not used(x)
    new_alphabet.add(x)
```
_____
### PB -  