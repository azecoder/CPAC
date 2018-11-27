## EXPLANATIONS OF SOLUTIONS

# P: Alice, Bob and Chocolate
* problem link 		: [6C](http://codeforces.com/contest/6/problem/C)
* solution code 	: [cpp](https://github.com/azecoder/CPAC/blob/master/HomeWorks/6C.cpp)
* solution method	: two pointers

Define two pointers
	1. for Alice.. it starts from first chocolate
	2. for Bob.. it starts from last chocolate
while the position of the Alice is less than the position of the Bob
	check if ate time of Alice is smaller than Bob's
		increase position of the Alice
		and add chocolate bar time to Alice's eating time
	else
		decrease position of the Bob
		and add chocolate bar time to Bob's eating time
check if they stay in the same position and there is one chocolate bar is left
	give the chocolate bar to the player who eats in less time.