#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to simulate sending a frame
void sendFrame(int frame) {
    cout << "Sender: Sending frame " << frame << endl;
}

// Function to simulate receiving a frame
bool receiveFrame(int frame) {
    // Simulate frame loss or corruption randomly
    int random_value = rand() % 10;
    if (random_value < 2) {  // Simulate 20% chance of frame loss or corruption
        cout << "Receiver: Frame " << frame << " lost or corrupted!" << endl;
        return false;
    }
    cout << "Receiver: Frame " << frame << " received successfully." << endl;
    return true;
}

// Function to simulate sending an acknowledgment
void sendACK(int ack) {
    cout << "Receiver: Sending ACK " << ack << endl;
}

// Function to simulate receiving an acknowledgment
bool receiveACK(int ack) {
    // Simulate ACK loss randomly
    int random_value = rand() % 10;
    if (random_value < 2) {  // Simulate 20% chance of ACK loss
        cout << "Sender: ACK " << ack << " lost!" << endl;
        return false;
    }
    cout << "Sender: ACK " << ack << " received successfully." << endl;
    return true;
}

int main() {
    srand(time(0));  // Seed the random number generator

    int frame = 0;  // Start with frame 0

    while (frame < 5) {  // Simulate sending 5 frames
        sendFrame(frame);

        // Simulate waiting for receiver's response
        if (receiveFrame(frame)) {
            sendACK(frame);
            if (receiveACK(frame)) {
                frame++;  // Move to the next frame only if ACK is received
            } else {
                cout << "Sender: Resending frame " << frame << endl;
            }
        } else {
            cout << "Sender: Resending frame " << frame << endl;
        }

        cout << endl;
    }

    cout << "All frames sent and acknowledged successfully!" << endl;
    return 0;
}
