#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the parity bits and encode data
vector<int> encodeHammingCode(vector<int> data) {
    vector<int> encodedData(7);
    
    // Place the data bits in the encodedData array
    encodedData[2] = data[0]; // D1
    encodedData[4] = data[1]; // D2
    encodedData[5] = data[2]; // D3
    encodedData[6] = data[3]; // D4
    
    // Calculate the parity bits
    encodedData[0] = encodedData[2] ^ encodedData[4] ^ encodedData[6]; // P1
    encodedData[1] = encodedData[2] ^ encodedData[5] ^ encodedData[6]; // P2
    encodedData[3] = encodedData[4] ^ encodedData[5] ^ encodedData[6]; // P4
    
    return encodedData;
}

// Function to detect and correct errors in the Hamming code
void detectAndCorrectError(vector<int>& encodedData) {
    // Calculate the syndrome bits
    int s1 = encodedData[0] ^ encodedData[2] ^ encodedData[4] ^ encodedData[6];
    int s2 = encodedData[1] ^ encodedData[2] ^ encodedData[5] ^ encodedData[6];
    int s4 = encodedData[3] ^ encodedData[4] ^ encodedData[5] ^ encodedData[6];
    
    // Calculate the error position
    int errorPosition = s1 * 1 + s2 * 2 + s4 * 4;
    
    // If errorPosition is not 0, there is an error in the encoded data
    if (errorPosition != 0) {
        cout << "Error detected at position: " << errorPosition << endl;
        // Correct the error by flipping the bit at errorPosition
        encodedData[errorPosition - 1] ^= 1;
        cout << "Error corrected!" << endl;
    } else {
        cout << "No error detected." << endl;
    }
}

int main() {
    vector<int> data(4);
    cout << "Enter 4-bit data (space-separated): ";
    for (int i = 0; i < 4; ++i) {
        cin >> data[i];
    }

    vector<int> encodedData = encodeHammingCode(data);

    cout << "Encoded data: ";
    for (int bit : encodedData) {
        cout << bit << " ";
    }
    cout << endl;

    // Introduce an error for testing
    encodedData[4] ^= 1; // Flip a bit to introduce an error

    cout << "Encoded data with error: ";
    for (int bit : encodedData) {
        cout << bit << " ";
    }
    cout << endl;

    // Detect and correct the error
    detectAndCorrectError(encodedData);

    cout << "Corrected data: ";
    for (int bit : encodedData) {
        cout << bit << " ";
    }
    cout << endl;

    return 0;
}