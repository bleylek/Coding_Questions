/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
 

Constraints:

The given address is a valid IPv4 address.
*/

#include <iostream>
#include <algorithm>
using namespace std;

//Solution 1
class Solution {
public:
    string defangIPaddr(string address) {
        string defangedAddress = "";
        for(int i = 0; i < address.length(); i++)
        {
            if(address[i] == '.')
            {
                defangedAddress+= "[.]";
            }
            else
            {
                defangedAddress+=address[i];
            }
        }
        return defangedAddress;
    }
};

//Solution 2
/*
class Solution {
public:
    string defangIPaddr(string address) {
        string defangedAddress;
        for(char x:address)
        {
            if(x == '.')
            {
                defangedAddress.push_back('[');
                defangedAddress.push_back('.');
                defangedAddress.push_back(']');
            }
            else
            {
                defangedAddress.push_back(x);
            }
        }
        return defangedAddress;
    }
};
*/

int main() {
    Solution solution;
    string IPaddress;
    cout <<"Enter an IP address: ";
    cin >> IPaddress;
    string result = solution.defangIPaddr(IPaddress);
    cout << "Defanged IP address: " << result << endl;
    return 0;
}