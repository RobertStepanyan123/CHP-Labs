#include <iostream>
#include <string>

using namespace std;

class CaesarCipher {
private:
    int shift;

    char shiftChar(char ch, int shift) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            return (ch - base + shift) % 26 + base;
        }
        return ch; 
    }

public:
    CaesarCipher(int s) : shift(s % 26) {}

    string encrypt(const string& plainText) {
        string encryptedText;
        for (char ch : plainText) {
            encryptedText += shiftChar(ch, shift);
        }
        return encryptedText;
    }

    string decrypt(const string& cipherText) {
        string decryptedText;
        for (char ch : cipherText) {
            decryptedText += shiftChar(ch, 26 - shift); 
        }
        return decryptedText;
    }
};

int main() {
    int shift;
    cout << "Enter the shift value: ";
    cin >> shift;

    CaesarCipher cipher(shift);

    string message = "HELLO WORLD";
    string encrypted = cipher.encrypt(message);
    string decrypted = cipher.decrypt(encrypted);

    cout << "Original: " << message << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}