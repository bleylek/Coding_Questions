/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/


#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* currentNode = head;

        // Counting the number of nodes
        while(currentNode != nullptr) {
            count++;
            currentNode = currentNode->next;
        }

        currentNode = head;
        for(int i = 0; i < count / 2; i++) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }
};


// Function to add a new node at the end of the list
void appendNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val); // Creating the New Node
    if (head == nullptr) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    int n, value;
    ListNode* head = nullptr;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        appendNode(head, value);
    }

    Solution solution;
    ListNode* result = solution.middleNode(head);

    cout << "Middle node onwards: ";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
