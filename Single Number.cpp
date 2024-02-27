/*
Question: Single Number
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must  implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Solution 1
/*
For the sequence [4, 1, 2, 1, 2], despite my step-by-step explanation, 
what happens is all instances of 1 and 2 XOR to 0 (since each appears twice), 
and only 4 does not find a pair, hence it remains.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for(auto x:nums)
        {
            answer = answer ^ x;
        }
        return answer;
    }
};


//Solution 2
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1; i+=2)
        {
            if(nums[i] != nums[i+1])
            {
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }
}
*/


int main() {
    Solution solution;
    int n;
    vector<int> nums;
    cout << "Enter the number of elements (odd number): ";
    cin >> n;
    if(n % 2 ==0 || n <=0)
    {
        cout << "Invalid number of elements." << endl;
        return 1;
    }
    cout << "Enter " << n << " elements, with every element but one appearing twice: ";
    for(int i = 0; i< n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    int result = solution.singleNumber(nums);
    cout << "The single element is: " << result << endl;
    return 0;
}