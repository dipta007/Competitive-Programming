// ============================================================================
// Algorithm   :: Finds the longest palindromic sub-string of a given string.
// Proposed by :: Manacher (1975)
// Order       :: Linear O(n)
// ============================================================================
//
// Short description
//
// At first the given string is processed by inserting a special character '#'
// after every letter. For example...
//
// Given string     :    a b b a
// Processed string : ^# a#b#b#a #$
//
// Another two special characters '^' and '$' are added to the begining and the
// end. The purpose of processing the main string will be cleared soon.
//
// Lets introduce the palindrome array pal[i]. It saves the longest palindrome's
// length centered at i. For example...
//
// Given string     : # a # b # a # a # b # a #
// palindrome array : 0 1 0 3 0 1 6 1 0 3 0 1 0
//
// Looking at te palindrome array, the longest palindrome's length can easily be
// determined (pal[6] = 6).
//
// It is clearly seen from the palindrome array that the special character '#' is
// solving the case of palindrome with even length. They becomes the center of the
// even palindromes.
// 
// Lets see the symmetric property of palindrome array. The mirror of i is i'.
// 
// 				          L             i'  C   i             R
//                        |.................*.................| 
// Given string     : # b # a # b # c # b # a # b # c # b # a # c # c # b # a #
// palindrome array : 0 1 0 3 0 1 0 7 0 1 0 9 0 ?
// 
// What is the value of '?'
// The answer is same as i' = 1.
// (Find out yourself why)
// 
// <-- Crutial Part -->
// 
// 				          L         i'      C       i         R
//                    ____|.................*_____
//                                    ______*.................|____
// Given string     : # b # a # b # c # b # a # b # c # b # a # c # c # b # a #
// palindrome array : 0 1 0 3 0 1 0 7 0 1 0 9 0 1 0 ?
// 
// What is the value of '?'
// The answer is same as i' = 7.
// 
// Wrong! It is 5. Why?
// 
// We are setting semmitricity according to the palindrome centered at C. Palindrome
// centered at i' crosses the range [L...R] of C centered palindrome. In range [L...R],
// it has semmitricity of 5. The dotted (..) line of i' shows its part in range [L...R].
// The underscored lines (__) of i' shows how much part of i' leaves the range. So, we
// can be sure that i has semmitricity of 5 atleast. It hase to be checked further
// that can i centered palindrome be extended.
// 
// Pseudo code for <-- Crutial Part -->:
// 
// if 'i' is greater than 'Right'
// 	    then no precomputed semmitricity for it as it leaves the range [L...R]
// else
//      i is in the range [L...R], if we take the minimum of the
//      Right - i and pal[i'] then we are done!
//      
// If i leaves Right, then the new center becomes i, that is C = i and R = i + pal[i].
// This process is continued further.
// 
// Iterate through the palindrome array and find the maximum value. Starting
// position of a palindrome centered at i is Given_string[(i - pal[i] -1)/2].
//
// ============================================================================

using namespace std;

#include <iostream>
#include <algorithm>
#include <cstring>

const int MAX = 1000000;

char temp [MAX + 7];     // main string.
char str [2 * MAX + 7];  // processed string.
int pal [2 * MAX + 7];   // palindrome array mentioned at line 18.

// Processes the "temp" string mentioned at line 9.
int preProcess () {
    int len = 2;
    strcpy (str, "^#");

    for (int i = 0; temp[i]; i++) {
        str [len++] = temp [i];
        str [len++] = '#';
    }
    str [len++] = '$';
    str [len++] = 0;

    return len;
}

void slowLongestPalindromes () {
    int n = preProcess ();
    int C = 0, R = 0;

    for (int i = 1; i < n - 1; ++i) {
        int i_mirror = 2 * C - i; // equals to i' = C - (i-C)

        // solves the <-- Crutial Part --> mentioned at line 42.
        pal[i] = (R > i) ? min (R - i, pal[i_mirror]) : 0;

        // Attempt to expand palindrome Centered at i.
        while (str[i + 1 + pal[i]] == str[i - 1 - pal[i]]) pal[i]++;

        // If palindrome centered at i expand past Right,
        // then adjust center based on expanded palindrome.
        if (i + pal[i] > R) {
            C = i;
            R = i + pal[i];
        }
    }
}

int main () {
    cin >> temp;
    slowLongestPalindromes ();
    return 0;
}