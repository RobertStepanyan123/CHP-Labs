#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class RLE {
public:

    string encode(const std::string& input) {
        ostringstream encoded;
        int count = 1;

        for (size_t i = 0; i < input.length(); ++i) {
            if (i == input.length() - 1 || input[i] != input[i + 1]) {
                encoded << input[i] << static_cast<char>(count);
                count = 1;
            }
            else {
                ++count;
            }
        }

        return encoded.str();
    }

    string decode(const string& input) {
        ostringstream decoded;
        for (size_t i = 0; i < input.length(); ++i) {
            char ch = input[i];
            ++i;


            int count = static_cast<int>(input[i]);
            decoded << string(count, ch);
        }

        return decoded.str();
    }
};

int main() {
    RLE rle;
    string input;

    cout << "Enter a string to encode: ";
    getline(cin, input);

    string encoded = rle.encode(input);
    cout << "Encoded string: " << encoded << endl;

    string decoded = rle.decode(encoded);
    cout << "Decoded string: " << decoded << endl;

    return 0;
}