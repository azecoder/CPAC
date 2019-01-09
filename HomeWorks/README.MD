# EXPLANATIONS OF SOLUTIONS

### PB - Fox And Names
* Problem link 		: [codeforces - 510C](http://codeforces.com/contest/510/problem/C)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/510C.cpp)
* Solution method	: Graph, DFS
* Compexity			: `O(N^2)`

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
Now, we have an alphabet and we have a change list for characters. So we start from `a` to `z` and do dfs.. In dfs, we will change characters with new one from the change list. But we check if we change the same character before it means that we will get a cycle in dfs and it means that it is impossible to create a new alphabet.
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
* Compexity			: `O(N^2)`

#### Explanation
Let `X` be the input sequence of length `N` and `LPS(X, 0, N-1)` be the length of the longest palindromic subsequence of `X`.

Let A be a subsequence of X. 
```
    A = X[left, right]
```
if `A` is a single character then it is a palindrome, and length of this palindrome is one.
```
    if left == right
        return 1
```
if length of `A` is `2` and `A[0]` is equal to `A[1]` then it is a palindrome.
```
    if left + 1 == right and X[left] = X[right]
        return 2
```
If there are more than two characters in subsequence `A`, and first and last characters are same, then
```
    if X[left] == X[right]
        return 2 + LPS( left + 1 , right - 1 )
```
if first and last characters of the subsequence are different, then
if last and first characters of the subsequence are same, then check `A[first, last-1]` and `A[first+1, last]` recursively.
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

In the above partial recursion tree, `LPS(1, 4)` is being solved twice. If we draw the complete recursion tree, then we can see that there are many subproblems which are solved again and again. But we can use `DP` to save the results of the solved subsequences.
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
* Compexity			: `O(N)`

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
* Compexity			: `O(N)`

#### Explanation
First of all we must check if we can divide this array in three part or not. So that, we get sum of all elements in array.
```
for i from 1 to N
    read arr[i]
    sum += arr[i]
```
if sum of the all elements is equal to `S`, then sum of each of the `3` part must be equal to `S/3`. Therefore if `S` is not divided by `3` then answer is `0`.
```
if S mod 3 > 0
    print 0
    exit
```
Let's start to iterate for first part. We start check if sum of `j` to `N` is equal to apart sum. And we create a new array and save the points which sum of the elements from this point to `N` is equal to `S/3`.
```
cnt = aray(N)   // is a new array for saving points - default is 0
psum = sum/3    // part sum
csum = 0        // current sum, default is 0
for i from N to 1
    csum += arr[i]
    if csum == psum
        cnt[i] = 1
``` 
Now we use cnt array for shows how much time we get same sum with `S/3` between current index and N. 
```
for i from N - 1 to 1
    cnt[i] += cnt[i+1]
```
In final part of the solution, for each prefix `[1..i]` of the initial array we just add `cnt[i+2]` to answer if `sum[1..i]` equals to `S/3`
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
* Compexity			: `O(N*M)`

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
### PB - Longest Bitonic Subsequence
* Problem link 		: [geeksforgeeks - LBS](https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_LBS.cpp)
* Solution method	: longest increasing and decreasing subsequence
* Compexity			: `O(N^2)`

#### Explanation
* Let `LIS` to be an array which `LIS[i]` is longest increasing subsequence ending with `arr[i]`
* Let `LDS` to be an array which `LDS[i]` longest decreasing subsequence starting with `arr[i]`
* Allocate memory for `LIS` and `LDS`, then initialize values as `1` for all indexes
```
    int lis = array
    int lds = array
    for i from 1 to N
        lis[i] = lds[i] = 1
```
* Compute `LIS` values from `left` to `right`
```
    for i from 2 to N
        for j from 1 to i - 1
            if arr[i] > arr[j]
                lis[i] = max(lis[i], lis[j] + 1)
```
* Compute `LDS` values from `left` to `right`
```
    for i from N - 1 to 1
        for j from N to i + 1
            if arr[i] > arr[j]
                lds[i] = max(lds[i], lds[j] + 1)
```
* Return the maximum value of `LIS[i] + LDS[i] - 1` `# -1 is for current index`
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
* Compexity			: `O(2*N)`

#### Explanation
Create two heaps, and a counter for each heap. After that count the numbers.
```
    read N
    int M = 2 * N
    for i from 1 to M
        read arr[i]
        cnt[ arr[i] ]++
```
Check if the number appear more than once, and put one of them in the first pile, one of them in the second pile and the other put aside. After that, divide the numbers, that appears once, in two equal part and put the first part in the first pile and second part in the second pile.
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
### PB - Leaders in an Array
* Problem link 		: [geeksforgeeks - Leaders in an Array](https://practice.geeksforgeeks.org/problems/next-larger-element/0)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Leader-in-Array.cpp)
* Solution method	: Linear Search
* Compexity			: `O(N)`

#### Explanation
Start searching from last element of the array, and for each index
 we check and set a `max` as maximum element of the right side. if current element of array is bigger than the maximum element of the right side elements then we can said that this element is leader in this array.
```
    MAX = -INF // minus infinity number
    for i from N to 1
        if arr[i] > MAX
            MAX = arr[i]
            ADD(arr[i], leaders)

```
_____
### PB - Kadane's Algorithm
* Problem link 		: [geeksforgeeks - Kadane's Algorithm](https://practice.geeksforgeeks.org/problems/next-larger-element/0)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Kadane-Algorithm.cpp)
* Solution method	: Linear Search
* Compexity			: `O(N)`

#### Explanation
Start searching from first element of array, and sum each element 
if sum is bigger than `0`, otherwise set sum as a current element. Get maximum sum as a result.
```
    for i form 1 to N
        if sum >= 0
            sum += arr[i]
        else
            sum = arr[i]    // initialize the sum
        result = max(result, sum)   // get max sum of the subarrays
```
_____
### PB - Missing number in array
* Problem link 		: [geeksforgeeks - Missing Number](https://practice.geeksforgeeks.org/problems/next-larger-element/0)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Missing-Number.cpp)
* Solution method	: Linear Search, Math
* Compexity			: `O(N)`

#### Explanation
Find the sum of elements `1` to `N`, and subtract each element in the 
given array. Answer is the lost number in the array.
```
    sum = N * (N + 1) / 2   // sum of elements  from 1 to N
    for each elem in array
        sum -= elem
    print sum
```
_____
### PB - Trapping Rain Water
* Problem link 		: [geeksforgeeks - Trapping Rain Water](https://practice.geeksforgeeks.org/problems/next-larger-element/0)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Trapping-Rain-Water.cpp)
* Solution method	: Linear Search, DP
* Compexity			: O(N)

#### Explanation
Find left maximum and right maximum for each element of the given 
array. Then answer is equal to sum of the `min(left[i], right[i]) - arr[i]` 
```
    arr   = [ 7, 4, 0, 9, 2, 4, 6 ]
    left  = [ 7, 7, 7, 9, 9, 9, 9 ] // contains height of tallest bar to the left
    right = [ 9, 9, 9, 9, 6, 6, 6 ] // contains height of tallest bar to the right
```
_____
### PB - Maximum of all subarrays of size k
* Problem link 		: [geeksforgeeks - Maximum of all subarrays](https://practice.geeksforgeeks.ohttps://practice.geeksforgeeks.org/problems/next-larger-element/0)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Maximum-of-Subarrays.cpp)
* Solution method	: Linear Search, Multiset
* Compexity			: `O(N)`

#### Explanation
Create a multiset. Initially, insert first `K` elements of the array to our set. After that, start searching from `K'th` element to `N'th` element. For each index, 
* remove `arr[i-k]` from set
* insert `arr[i]` to set
* get max element of the multiset
```
    for i from 1 to K
        INSERT(arr[i], S)   // insert an element to set
    GETMAX(S)   // print max element for first k element

    for i from K+1 to N
        REMOVE(arr[i-K])    // remove (i-k)'th element from set
        INSERT(arr[i])      // insert i'th element to the set
        GETMAX(S)           // print the max element of the set
```
_____
### PB - Next larger element
* Problem link 		: [geeksforgeeks - Next larger element](https://practice.geeksforgeeks.org/problems/next-larger-element/0)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Next-Larger-Element.cpp)
* Solution method	: Linear Search, Stack
* Compexity			: `O(N)`

#### Explanation
Initially push the first element of the array to the stack. 
```
    INSERT(arr[1], S)  // insert first element to the stack
```
Start searching from second element to the end, while the next element is bigger than the top element of the stack then pop from stack contiguously and print this element as a next larger element. 
```
    for i from 2 to N
        X = LAST(S) //  last element of the stack
        while S not empty and arr[i] > X
            print arr[i]    // it means arr[i] is next larger element for X
            REMOVE(X, S)    // remove x from the Stack
```
Then, then push the next element to stack. 
```
        INSERT(arr[i], S)
```
At the end, if there is not any other larger element for elements of the stack, just pop and print `-1` for this elements. it means that stack is decreasing order, so there is not any greater element.
```
    while S not empty
        X = LAST(S)
        print -1
        REMOVE(X, S)
```
_____
### PB - Largest Even Number
* Problem link 		: [geeksforgeeks - Largest Even Number](https://practice.geeksforgeeks.org/problems/largest-even-number/0)
* Solution code 	: [cpp1](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Largest-Even-Number.cpp), [cpp2](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Largest-Even-Number2.cpp)
* Solution method	: Counting Sort / Linear Search, MultiSet
* Compexity			: `O(N)`

#### Explanation
Firstly, read string, then convert each character of string to integer, and count each integer.
```
    read str
    for each ch in str
        int x = (int)(ch - '0') // convert char to int
        count[x]++              // count each number in string
```
then, find the minimum even number from the count array.
```
    ind = 0         // we will have maximum 10 different digits in string
    while ind < 10  // so we check between 0 and 9.. only these numbers [0,2,4,6,8]
        if count[ind] > 0   // if we have 
            min_even = ind  // then it menas we find the min even number
            break
        ind += 2            // we search in the range of only even numbers
```
At the end, start from 9 to 0 and print each `x` `count[x]` times, but if digit is eaqual to minimum even number, then print it `count[x]-1` time.
```
    if have min_even        // if we have minimum even number
        count[min_even]--   // decrease count, we will show this minimum even number at the end
    for i from 9 to 0
        for j from 1 to count[i] // print each digit count[digit] times
            print i
    if have min_even    // if we have minimum even number 
        print min_even  // then print it
```
_____
### PB - Inversion Count
* Problem link 		: [geeksforgeeks - Inversion Count](https://www.spoj.com/problems/INVCNT/)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/spoj_INVCNT.cpp)
* Solution method	: Merge Sort, Divide and Conquer
* Compexity			: `O(N*logN)`

#### Explanation
Use MergeSort Algorithm. Firstly, write a recursive function that sorts the input array. Divide the array into two parts recursively. 
```
    MERGE_SORT(left, right)
        if left == right
            return
        
        mid = (left + right) / 2    // calculate middle index
        MERGE_SORT(left, mid)       // divide left to middle
        MERGE_SORT(mid+1, right)    // divide middle to right

        result += MERGE(left, right)    // merge (left,middle) and (middle,right), and sum inversion count

```
Then merge two sorted arrays and calculate inversion count during merge process.
```
    MERGE(left, right)
        inv_count = 0               // default value
        mid = (left + right) / 2
        l = left
        r = mid + 1
        while(l <= mid and r <= right)
            if(arr[l] > arr[r])             // temp will be sorted array in these range
                temp[x++] = arr[l++]        // insert from left subarray to temp array
                inv_count += (right - r + 1)    // counting the inversion count
            else
                temp[x++] = arr[r++]        // insert from right subarray to array
        
        for i from l to mid
            temp[x++] = arr[i++]    // Copy the remaining elements of left subarray
        for i from r to right
            temp[x++] = arr[i++]    // Copy the remaining elements of left subarray
        for i from left to right
            arr[i] = temp[i - left] // Copy back the merged elements to original array

        return inv_count
```
_____
### PB - Preorder Traversal and BST
* Problem link 		: [geeksforgeeks - Preorder Traversal and BST](https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Preorder-Traversal.cpp)
* Solution method	: Linear, Stack
* Compexity			: `O(N)`

#### Explanation
We check all numbers from begin to end. Set root as minimum integer number as default. Check if right side node is smaller than the root node value, then this array can not be preorder.
```
    for i from 2 to N
        if arr[i] < root    
            print 0         // it not preorder presentation
        .....               // code below
```
if `arr[i]` is bigger than top element of the stack, then it means it is in right subtree, so remove smaller elements from the stack, and get last element as a new root. After that add `arr[i]` to the stack.
```
    ADD(S, arr[1])
    for i from 2 to N
        .....               // code above
        while S not empty and TOP(S) < arr[i]   // if arr[i] is in right subtree
            root = TOP(S)   // set new root
            POP(S)
        ADD(S, arr[i])
```
_____
### PB - Check for BST
* Problem link 		: [geeksforgeeks - Check for BST](https://practice.geeksforgeeks.org/problems/check-for-bst/1)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Check-for-BST.cpp)
* Solution method	: BST
* Compexity			: `O(N)`

#### Explanation
Start from root node, and then check all nodes. All left children datas must be smaller than their parent's data. And all right children datas must be bigger than the their parent's data
```
    left_node.key < parent.key
    right_node.key >= parent.key
```
_____
### PB - Maximum path sum
* Problem link 		: [geeksforgeeks - Maximum path sum](https://practice.geeksforgeeks.org/problems/maximum-path-sum/1)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/geeks_Maximum-path-sum.cpp)
* Solution method	: BST
* Compexity			: `O(N)`

#### Explanation
Firstly, store maximum path sum going through left and right child of root. Set max_single as maximum path sum from root node to child.
```
    left_max_sum = maxSum(node.left)
    right_max_sum = maxSum(node.right)

    max_single = MAX(MAX(left_max_sum, right_max_sum) + node.data, node.data)
```
And assume we connect two maximum path in one node. so that we set ` max_top = MAX(max_single, left_max_sum + right_max_sum + node.data) `
_____
### PB -  Ilya and Queries
* Problem link 		: [codeforces - 313B](http://codeforces.com/contest/313/problem/B)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/313B.cpp)
* Solution method	: DP
* Compexity			: `O(N)`

#### Explanation
Check from second character of the string to the end. If current character is equal to previous one, then count for this index is equal to `1 + count` of the previous index.
```
    for i from 1 to len
        if s[i] = s[i-1]
            dp[i] = dp[i-1] + 1
        else
            dp[i] = dp[i-1]
```
whit this method we find the result for from first index to another one. For range `(left,right)`, we will use `(left,right) = (1,right) - (1,left)`
_____
### PB -  Little Girl and Maximum Sum
* Problem link 		: [codeforces - 276C](http://codeforces.com/contest/276/problem/C)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/276C.cpp)
* Solution method	: DP
* Compexity			: `O(N)`

#### Explanation
Firstly, we must calculate how much time we use each index in queries.
```
    for i from 1 to Q   //  number of queries
        read (left, right)
        count[left]++
        count[right+1]--
    for i from to N     // number of the elements in the array
        count[i] += count[i-1]
```
Then sort this count array and input array, try to show maximum element of the array maximum time, so that result is
```
    sort(arr)   //  initial array
    sort(count)
    for i from 1 to N
        result += arr[i] * count[i]
```
_____
### PB -  Update the Array
* Problem link 		: [spoj - UPDATEIT](https://www.spoj.com/problems/UPDATEIT/)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/UPDATEIT.cpp)
* Solution method	: BIT, Fenwick
* Compexity			: `O(logN)`

#### Explanation
```
    while index <= length
        arr[ind] += value
        index += index & (-index)
```
_____
### PB -  Megacity
* Problem link 		: [codeforces - 424B](http://codeforces.com/contest/424/problem/B)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/424B.cpp)
* Solution method	: Priority Queue
* Compexity			: `O(N)`

#### Explanation
Firstly, find the distance from each city to `(0,0)`. Then sort all cities for their distances.
```
    read (x, y, people)
    dist = distance(0, 0, x, y)     // find distance from 0,0 to x,y
    ADD({dist, people}, PQ)         //  add distance and people count to priority queue
```
Then start from the nearest city, and add population of the city to the people count of the Tomsk city. If we reach to the 1 million population then it means that we find the minimum radius of the megacity
```
    while PQ not empty
        data = TOP(PQ)
        population += data.people
        if population == 1000000
            print data.distance
            exit
```
_____
### PB -  Find Pair
* Problem link 		: [codeforces - 160C](http://codeforces.com/contest/160/problem/C)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/160C.cpp)
* Solution method	: Map
* Compexity			: `O(N*N)`

#### Explanation
Firstly sort elements of array and find the count of each element. Use the map to sort elements and counts them efficiently.
```
    map <int, int> arr      // first for element, second for count
    for i from  1 to N
        read x
        arr[x]++            // insert element, and count it
```
After that, start solving from the smaller to biggest element of the map. Firsly, we are trying to find first element of the couples.
```
    for each elem in arr
        count = elem.second * N     //  how many times we use this element in couples
        if count >= K                       
            result.first = element.first    // it means that, it is first number of the K'th couple
            ......          // code below
            break
        else                // Otherwise, we skip to the next element
            K -= count      // It means that, answer is not in these couples, so we subtract the count
```
After find the first element of the couple, we will search for the second element. To find the first element of the couple, we compare `elem.count * N` with `K` for each element of the map. But for second element of the couple, we found the first element, so that we will compare `elem1.count * elem2.count` with `K`
```
    for each elem2 in arr
        count2 = elem.second * elem2.second
        if count2 >= K
            result.second = elem2.first // in this case, we found the second elemet of the couple
            break
        else
            K -= count2     // Otherwise, we do same thing as first
```
_____
### PB -  Circular RMQ
* Problem link 		: [codeforces - 52C](http://codeforces.com/contest/52/problem/C)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/52C.cpp)
* Solution method	: Segment Tree
* Compexity			: `O(N)`

#### Explanation
Use segment tree, update range and get the minimum value of the given range. But to calculate the `minRange(left, right)` where `left > right` statements, just get minimum value of the `minRange(right, length)` and `minRange(1, left)`.
```
    if left <= right
        tree->minRange(left, right)
    else
        min(
            tree->minRange(right, N),
            tree->minRange(1, left)
        )
```

<!--
_____
### PB -  https://www.spoj.com/problems/UPDATEIT/
* Problem link 		: [spoj - UPDATEIT](https://www.spoj.com/problems/UPDATEIT/)
* Solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/UPDATEIT.cpp)
* Solution method	: BIT, Fenwick
* Compexity			: O(log<sup>N</sup>)

#### Explanation
```
    while index <= length
        arr[ind] += value
        index += index & (-index)
```
-->