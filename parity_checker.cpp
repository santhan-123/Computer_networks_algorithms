//basic logic is when we do and operation on a number with its number-1 we always make the next bit which is 1 to zero

//for example let a=6
//its binary representation is 0000 0110
//bit-1= 0000 0101
//doing bitwise and(&) operation we make the 1st 1 to 0 i.e the output is 0000 0100
//again doing bit-1 = 0000 0011
//doing bitwise and(&) operation will make the next and the last one to 0 i.e output is 0000 0000
//hence we give false at begining  and next made true and made again false which will conclude no bits are outof parity

#include<iostream>
using namespace std;

bool evenParity(unsigned char n){
    bool parity = false;

    while(n){
        parity = !parity;
        n = n &( n-1);
    }
    return parity;
}

int main()
{
    unsigned char n;//8-bit number
    cin>>n;

    bool even = evenParity( n);
    cout<<even;




}


// #include <iostream>

// // Function to calculate even parity
// bool evenParity(unsigned char byte) {
//     bool parity = false; // Start with even parity
//     while (byte) {
//         parity = !parity; // Toggle parity with each 1 bit
//         byte = byte & (byte - 1); // Clear the lowest set bit
//     }
//     return parity; // Return true if parity is odd, false if even
// }

// // Function to calculate odd parity
// bool oddParity(unsigned char byte) {
//     return !evenParity(byte); // Odd parity is the opposite of even parity
// }

// int main() {
//     unsigned char byte;

//     // Get input from user
//     std::cout << "Enter an 8-bit number (0-255): ";
//     std::cin >> byte;

//     // Calculate parity
//     bool even = evenParity(byte);
//     bool odd = oddParity(byte);

//     // Display results
//     std::cout << "Even parity: " << (even ? "1 (odd)" : "0 (even)") << std::endl;
//     std::cout << "Odd parity: " << (odd ? "1 (odd)" : "0 (even)") << std::endl;

//     return 0;
// }