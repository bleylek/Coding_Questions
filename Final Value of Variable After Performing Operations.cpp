/*
There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

 

Example 1:

Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
Example 2:

Input: operations = ["++X","++X","X++"]
Output: 3
Explanation: The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
Example 3:

Input: operations = ["X++","++X","--X","X--"]
Output: 0
Explanation: The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
 

Constraints:

1 <= operations.length <= 100
operations[i] will be either "++X", "X++", "--X", or "X--".
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Solution 1
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int answer = 0;
        for(int i =0; i<operations.size();i++)
        {
            if(operations[i][1] == '+')
            {
                answer+=1;
            }
            else
            {
                answer-=1;
            }
        }
        return answer;
    }
};


//Solution 2
/*
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int answer = 0;
        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i] == "X--" || operations[i] == "--X")
            {
                answer-=1;
            }
            else
            {
                answer+=1;
            }
            //if(operations[i] =="X++" || operations[i] == "++X")
            //{
            //    answer+=1;
            //}
        }
        return answer;
    }
};
*/

int main() {
    Solution solution;
    vector<string> operations;

    cout << "Enter the number of operations: ";
    int n;
    cin >> n;
    
    cout << "Enter n operations (e.g., X++, X--): ";
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        operations.push_back(op);
    }

    int result = solution.finalValueAfterOperations(operations);
    cout << "Final value after operations: " << result << endl;

    return 0;
}