/*
Question: Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

#include <iostream>
#include <algorithm>
using namespace std;

/*
Solution 1 için Example
Let's use an example to illustrate how the isAnagram function works. We'll check if the strings s = "listen" and t = "silent" are anagrams of each other.

Step 1: Check Length Equality
s.length() = 6 and t.length() = 6, so we proceed since the lengths are equal.
Step 2: Special Case for Single-Character Strings
This step is skipped because the length of both strings is greater than 1.
Step 3: Character Frequency Count
Initialize two arrays array1 and array2 to count the frequency of each letter in s and t, respectively.
For s = "listen":

l -> array1[11]++ (l - a = 11)
i -> array1[8]++ (i - a = 8)
s -> array1[18]++ (s - a = 18)
t -> array1[19]++ (t - a = 19)
e -> array1[4]++ (e - a = 4)
n -> array1[13]++ (n - a = 13)
For t = "silent":

s -> array2[18]++
i -> array2[8]++
l -> array2[11]++
e -> array2[4]++
n -> array2[13]++
t -> array2[19]++
Step 4: Comparing Character Frequencies
We compare the frequencies stored in array1 and array2. For all characters ('a' through 'z'), the frequencies in s match the frequencies in t.
Step 5: Returning the Result
Since there was no point at which the frequencies didn't match, the function concludes that s and t are indeed anagrams and returns true.
This example illustrates the process of determining that "listen" and "silent" are anagrams by comparing the frequency of each letter in the strings. 
The method efficiently confirms that each letter appears the same number of times in both strings, fulfilling the criteria for anagrams.
*/

//Solution 1
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        {
            return false;
        }
        if(t.length() <=1)
        {
            if(s[0] == t[0])
            {
                return true;
            }
            else
            {
                return false;
            }
        } 

        int array1[26] = {0};
        int array2[26] = {0};

        for(int i = 0; i < s.length(); i++)
        {
            array1[s[i] - 'a']++;
            array2[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(array1[i] != array2[i])
            {
                return false;
            }
        }
        return true;
    }
};

//Solution 2
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};
*/

int main(){
    Solution solution;
    string s, t;
    cout << "Enter a word: ";
    cin >> s;
    cout << "Enter another word: ";
    cin >> t;
    bool result = solution.isAnagram(s, t);
    if (result) {
        cout << "The words are anagrams." << endl;
    } else {
        cout << "The words are not anagrams." << endl;
    }
    return 0;
}
