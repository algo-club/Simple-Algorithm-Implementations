#include <bits/stdc++.h> 
  
using namespace std; 
  
// Returns true if the pair is valid, 
// otherwise false 
bool checkValidPair(int num1, int num2) 
{ 
    // converting integers to strings 
    string s1 = to_string(num1); 
    string s2 = to_string(num2); 
  
    // Iterate over the strings and check 
    // if a character in first string is also 
    // present in second string, return true 
    for (int i = 0; i < s1.size(); i++) 
        for (int j = 0; j < s2.size(); j++) 
            if (s1[i] == s2[j]) 
                return true; 
  
    // No common digit found 
    return false; 
} 
  
// Returns the number of valid pairs 
int countPairs(int arr[], int n) 
{ 
    int numberOfPairs = 0; 
  
    // Iterate over all possible pairs 
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) 
            if (checkValidPair(arr[i], arr[j])) 
                numberOfPairs++; 
  
    return numberOfPairs; 
} 
  
// Driver Code to test above functions 
int main() 
{ 
    int arr[] = { 10, 12, 24 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << countPairs(arr, n) << endl; 
    return 0; 
} 
