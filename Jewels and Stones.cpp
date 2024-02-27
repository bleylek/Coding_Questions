/*
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0
 

Constraints:

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for(int i = 0; i < jewels.length(); i++)
            for(int j = 0; j < stones.length(); j++)
                if(jewels[i] == stones[j])
                    count++;
        return count;
    }
};

int main() {
    string jewels, stones;
    cout << "Enter the types of stones that are jewels: ";
    cin >> jewels;
    cout << "Enter the stones you have: ";
    cin >> stones;

    Solution solution;
    int result = solution.numJewelsInStones(jewels, stones);
    cout << "The number of stones you have that are also jewels: " << result << endl;

    return 0;
}
