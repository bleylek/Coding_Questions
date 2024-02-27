/*
Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.

 

Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
Example 2:

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
 

Constraints:

n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 1000
*/

#include <iostream>
#include <vector>
using namespace std;

// Solution 1
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int k = nums.size();
        for(int i = 0; i < k; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};

/* Solution 2
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++){
            ans.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++){
            ans.push_back(nums[i]);
        }

        return ans;
    }
};
*/

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements:";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = sol.getConcatenation(nums);
    
    cout << "Concatenated array: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
