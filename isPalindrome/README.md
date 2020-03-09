# isPalindrome

Palindrome means that we can get the same string no matter from left or right side.

## Lintcode627

> Description: Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

> I find that there are only two ways of palindromes. The first one is the oddPalindrome, which is composed of one element in the center and evenPalindrome on the both side. e.g. cbabc. The second one is evenPalindrome, which is composed of two elements in the center and evenPalindrome on the both side.

* [First version](https://github.com/shinmao/algorithm/blob/master/isPalindrome/lintcode627-1.java): In my initial version of program, I decide to get the length of palindrome with counter. I put the number of occurances into the hashmap. Next, when I iterate through the map, there are only two possibile roles for each characters: center or evenPalindrome on side. If the character wants to be center, it should show up for only one time or odd time, otherwise, it should show up for even time to be evenPalindrome. At the end, I am able to get the length of longest palindrome easily.

## Lintcode200
> Description: Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

> Different from the problem of lintcode627, this problem wants to find the substring.


* [Dynamic programming](https://github.com/shinmao/algorithm/blob/master/isPalindrome/lintcode200-1.java): Dynamic programming is kind of bottom-up approach. Palindrome should be `(a) + sub-palindrome + (a)`, which means that palindrome should be consist of sub-palindrome. Therefore, we can start from the base cases such like `isPalindrome[i][i]` and `isPalindrome[i][i+1]`, and use the base cases to solve the bigger problem.
