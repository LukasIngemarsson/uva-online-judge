#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int C_MAX = 30 + 1;
    char seq[C_MAX];
    char out[C_MAX];

    while (cin.getline(seq, C_MAX)) {
        size_t seq_len = strlen(seq);
        
        for (int i = 0; i < seq_len; i++) {
            int asciiVal = static_cast<int>(seq[i]) - 65;

            if (asciiVal < 0 || asciiVal > 25) {
                out[i] = seq[i];
            }
            else if (asciiVal <= 2) {
                out[i] = '2';
            }
            else if (asciiVal <= 5) {
                out[i] = '3';
            }
            else if (asciiVal <= 8) {
                out[i] = '4';
            }
            else if (asciiVal <= 11) {
                out[i] = '5';
            }
            else if (asciiVal <= 14) {
                out[i] = '6';
            }
            else if (asciiVal <= 18) {
                out[i] = '7';
            }
            else if (asciiVal <= 21) {
                out[i] = '8';
            }
            else if (asciiVal <= 25) {
                out[i] = '9';
            }
        }
        out[seq_len] = 0;
        cout << out << endl;
    }
    return 0;
}