#include <bits/stdc++.h> 
using namespace std; 
  
// A class to represent array of bits using 
// array of integers 
class BitArray 
{ 
    int *arr; 
  
    public: 
    BitArray() {} 
  
    // Constructor 
    BitArray(int n) 
    { 
        // Devide by 32. To store n bits, we need 
        // n/32 + 1 integers (Assuming int is stored 
        // using 32 bits) 
        arr = new int[(n >> 5) + 1]; 
    } 
  
    // Get value of a bit at given position 
    bool get(int pos) 
    { 
        // Divide by 32 to find position of 
        // integer. 
        int index = (pos >> 5); 
  
        // Now find bit number in arr[index] 
        int bitNo = (pos & 0x1F); 
  
        // Find value of given bit number in 
        // arr[index] 
        return (arr[index] & (1 << bitNo)) != 0; 
    } 
  
    // Sets a bit at given position 
    void set(int pos) 
    { 
        // Find index of bit position 
        int index = (pos >> 5); 
  
        // Set bit number in arr[index] 
        int bitNo = (pos & 0x1F); 
        arr[index] |= (1 << bitNo); 
    } 
  
    // Main function to print all Duplicates 
    void checkDuplicates(int arr[], int n) 
    { 
        // create a bit with 32000 bits 
        BitArray ba = BitArray(320000); 
  
        // Traverse array elements 
        for (int i = 0; i < n; i++) 
        { 
            // Index in bit array 
            int num = arr[i]; 
  
            // If num is already present in bit array 
            if (ba.get(num)) 
                cout << num << " "; 
  
            // Else insert num 
            else
                ba.set(num); 
        } 
    } 
}; 
  
// Driver code 
int main() 
{ 
    int arr[] = {1, 5, 1, 10, 12, 10}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    BitArray obj = BitArray(); 
    obj.checkDuplicates(arr, n); 
    return 0; 
} 
