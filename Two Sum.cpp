/*
Question: Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
 
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 
Constraints:
* 2 <= nums.length <= 104
* -109 <= nums[i] <= 109
* -109 <= target <= 109
* Only one valid answer exists.
*/

#include <iostream>
#include <vector>
#include <algorithm>

//Solution 1
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> temp = nums;
        std::sort(temp.begin(),temp.end());
        std::vector<int> answer;
        int start = 0;
        int end = nums.size()-1;
        int first, second;
        while(start < end)
        {
            if(temp[start]+temp[end] == target)
            {
                first = temp[start];
                second = temp[end];
                break;
            }
            else if(temp[start] + temp[end] < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == first)
            {
                answer.push_back(i);
                break;
            }
        }
        for(int j = 0; j<nums.size(); j++)
        {
            if(second == nums[j] && j != answer[0])
            {
                answer.push_back(j);
                break;
            }
        }
        return answer;
    }
};


/* Solution 2 is a brute force approach, commented out for brevity.
   It iterates through each pair of numbers in the array to check if they add up to the target.
   This is less efficient than Solution 1, especially for large arrays. */
   
//Solution 2
/*
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for(int i =0; i<nums.size();i++)
        {
            for(int j = i+1; j<nums.size(); j++)
            {
                if(nums[i] + nums[j] == target) return {i,j};
            }
        }
        return {};
    }
};
*/

int main() {
    Solution solution;

    std::vector<int> nums;
    int target;
    
    std::cout << "Enter the number of elements: ";
    int n;
    std::cin >> n;
    
    std::cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }

    std::cout << "Enter a target number: ";
    std::cin >> target;

    std::vector<int> result = solution.twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Indices: " << result[0] << " and " << result[1] << std::endl;
        std::cout << "Elements: " << nums[result[0]] << " and " << nums[result[1]] << std::endl;
    } else {
        std::cout << "No two elements found with the target sum." << std::endl;
    }

    return 0;
}


