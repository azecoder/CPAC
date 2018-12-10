# EXPLANATIONS OF SOLUTIONS

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
### PB -  Longest Palindromic Subsequence
* Problem link 		: [geeksforgeeks - LPS](https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_LPS.cpp)
* Solution method	: Recursion & DP
* Compexity			: O(N^2)

#### Explanation
Let X be the input sequence of length N and LPS(X, 0, N-1) be the length of the longest palindromic subsequence of X.

Let A be a subsequence of X. 
```
    A = X[left, right]
```
if A is a single character then it is a palindrome, and length of this palindrome is one.
```
    if left == right
        return 1
```
if length of A is 2 and A[0] is equal to A[1] then it is a palindrome.
```
    if left + 1 == right and X[left] = X[right]
        return 2
```
If there are more than two characters in subsequence A, and first and last characters are same, then
```
    if X[left] == X[right]
        return 2 + LPS( left + 1 , right - 1 )
```
if first and last characters of the subsequence are different, then
if last and first characters of the subsequence are same, then check A[first, last-1] and A[first+1, last] recursively.
```
    if X[left] != X[right]
        return MAX( 
            LPS(left, right - 1), 
            LPS(left + 1, right) 
        )
```

Considering the above implementation, following is a partial recursion tree for a sequence of length 6 with all different characters.

                [0..5]
               /      \ 
          [0..4]      [1..5]
          /   \        /   \
     [0..3] [1..4]  [1..4] [2..5]

In the above partial recursion tree, LPS(1, 4) is being solved twice. If we draw the complete recursion tree, then we can see that there are many subproblems which are solved again and again. But we can use DP to save the results of the solved subsequences.
```
    // with this method, we will not solve subproblems again and again
    // if we solve it once, we save the result into DP, 
    // and then when we need it, we get result from DP
    int getLength(int l, int r)
        if not DP[l][r]
            DP[l][r] = LPS(l,r) // we save result to DP
        return DP[l][r] // and we get result from DP
    
    void setLength(int l, int r, int len)
        DP[l][r] = len

    // if first and last characters are different
    if X[left] != X[right]
        int _L = getLength(left + 1, right)
        int _R = getLength(left, right + 1)
        int _C = MAX( _L, _R )
        setLength(left, right, _C)
        return _C
```
_____
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
### PB - Edit distance
* Problem link 		: [geeksforgeeks - Edit-Distance](https://practice.geeksforgeeks.org/problems/edit-distance/0)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Edit-Distance.cpp)
* Solution method	: Recursion
* Compexity			: O(N*M)

#### Explanation
If first string is empty, the only option is to insert all characters of second string into first or If second string is empty, the only option is to remove all characters of first string.
```
    if A.length == 0    // A - first string, length N
        return B.length

    if B.length == 0    // B - second string, length M
        return A.length
```
If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. 
```
    if A[N] == B[M]
        return editDistance(N-1, M-1)
```
If last characters are not same, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values.
```
    return 1 + MIN(
            editDistance(N, M - 1),     // Insert
            editDistance(N - 1, M),     // Remove
            editDistance(N - 1, M - 1)  // Replace
        )
``` 
_____
### PB - Edit distance
* Problem link 		: [geeksforgeeks - LBS](https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_LBS.cpp)
* Solution method	: longest increasing and decreasing subsequence
* Compexity			: O(N^2)

#### Explanation
* Let LIS to be an array which LIS[i] is longest increasing subsequence ending with arr[i]
* Let LDS to be an array which LDS[i] longest decreasing subsequence starting with arr[i]
* Allocate memory for LIS and LDS, then initialize values as 1 for all indexes
```
    int lis = array
    int lds = array
    for i from 1 to N
        lis[i] = lds[i] = 1
```
* Compute LIS values from left to right
```
    for i from 2 to N
        for j from 1 to i - 1
            if arr[i] > arr[j]
                lis[i] = max(lis[i], lis[j] + 1)
```
* Compute LDS values from left to right
```
    for i from N - 1 to 1
        for j from N to i + 1
            if arr[i] > arr[j]
                lds[i] = max(lds[i], lds[j] + 1)
```
* Return the maximum value of lis[i] + lds[i] - 1 // -1 is for current index
```
    int result = 0
    for i from 1 to N
        result = max(result, lis[i] + lds[i] - 1)
    return result
```
_____
### PB - Two Heaps
* Problem link 		: [codeforces - 353B](http://codeforces.com/contest/353/problem/B)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/353B.cpp)
* Solution method	: Math
* Compexity			: O(2*N)

#### Explanation
Create two heaps, and a counter for each heap. After that count the numbers.
```
    read N
    int M = 2 * N;
    for i from 1 to M
        read arr[i]
        cnt[ arr[i] ]++
```
check if the number appear more than once, and put one of them in the first pile, one of them in the second pile and the other put aside. After that, divide the numbers, that appears once, in two equal part and put the first part in the first pile and second part in the second pile.
```
    for number from 10 to 99
        if count[number] > 1
            insert(heap1, number)   // insert number to first pile
            insert(heap2, number)   // insert number to second pile
            pile1++                 // count numbers in heap 1
            pile2++                 // count numbers in heap 2
            count[number] -= 2      // we get two numbers and insert them to heaps
        else if count[number] == 1 
            if pile1 < pile2            // if there are less numbers in heap 1
                insert(heap1, number)   // insert number two heap 1
                pile1++                 // increase count for heap 1
                count[number]--         // we get one number and insert to heap 1
            else
                insert(heap2, number)   // insert number two heap 2
                pile2++                 // increase count for heap 2
                count[number]--         // we get one number and insert to heap 2
```
Finally, take the numbers, that we put aside, and separate them in two pile in any kind
```
    for number from 10 to 99
        while pile1 < N and count[number] > 0
            heap1[number]++
            count[number]--
            pile1++
        while pile2 < N and count[number] > 0
            heap2[number]++
            count[number]--
            pile2++
```
_____