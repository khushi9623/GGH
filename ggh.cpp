#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> outputport_av(5); // Index 0 is not used
    vector<int> cache(8);
    vector<int> bufferE(8);
    vector<int> bufferN(8);
    vector<int> bufferW(8);
    vector<int> bufferS(8);
    vector<int> addr(5); // Index 0 is not used

    // Initialize your vectors here if needed

    for (int i = 1; i <= 4; i++) {
        if (outputport_av[i] == 1) {
            for (int j = 0; j < 8; j++) { // check cache
                if (cache[j] == addr[i]) {
                    // forward cache[j] packet to the output port
                    cout << "Forwarding packet from cache to output port " << i << endl;
                    break;
                }
            }

            if (bufferE[0] == addr[i]) { // check bufferE
                // forward the packet to output port i
                cout << "Forwarding packet from bufferE to output port " << i << endl;
                // shift the bufferE
                for (int k = 0; k < 7; k++) {
                    bufferE[k] = bufferE[k+1];
                }
                bufferE[7] = 0; // Assuming bufferE is shifted by moving the elements and the last element is set to 0
                break;
            }
            else if (bufferE[1] == addr[i] || bufferE[2] == addr[i]) {
                // forward the packet to output port i
                cout << "Forwarding packet from bufferE to output port " << i << endl;
                // shift the bufferE
                for (int k = 0; k < 7; k++) {
                    bufferE[k] = bufferE[k+1];
                }
                bufferE[7] = 0; // Assuming bufferE is shifted by moving the elements and the last element is set to 0
                break;
            }
            // Check bufferN, bufferW, bufferS similarly and implement the forwarding logic
        }
    }

    return 0;
}
