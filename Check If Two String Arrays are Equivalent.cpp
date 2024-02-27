/*
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

 

Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
 

Constraints:

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a;
        string b;
        for(int i = 0; i < word1.size(); i++)
        {
            a+=word1[i];
        }
        for(int j = 0; j < word2.size(); j++)
        {
            b+=word2[j];
        }
        if(a==b)
            return true;
        else
            return false;
    }
};

int main() {
    int n1, n2;
    cout << "Enter the number of elements in word1: ";
    cin >> n1;
    vector<string> word1(n1);
    cout << "Enter elements for word1:" << endl;
    for(int i = 0; i < n1; ++i) {
        cin >> word1[i];
    }

    cout << "Enter the number of elements in word2: ";
    cin >> n2;
    vector<string> word2(n2);
    cout << "Enter elements for word2:" << endl;
    for(int i = 0; i < n2; ++i) {
        cin >> word2[i];
    }

    Solution solution;
    bool isEqual = solution.arrayStringsAreEqual(word1, word2);
    if(isEqual) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
