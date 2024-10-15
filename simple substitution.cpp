#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class SubstitutionCipher {
private:
    unordered_map<char, char> encryptMap;
    unordered_map<char, char> decryptMap;

    void buildMaps(const string& key) {
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (size_t i = 0; i < alphabet.length(); ++i) {
            encryptMap[alphabet[i]] = key[i];
            decryptMap[key[i]] = alphabet[i];
        }
    }

public:
    SubstitutionCipher(const string& key) {
        buildMaps(key);
    }

    string encrypt(const string& plainText) {
        string encryptedText;
        for (char ch : plainText) {
            char upperCh = toupper(ch);
            if (encryptMap.find(upperCh) != encryptMap.end()) {
                encryptedText += encryptMap[upperCh];
            }
            else {
                encryptedText += ch;
            }
        }
        return encryptedText;
    }

    string decrypt(const string& cipherText) {
        string decryptedText;
        for (char ch : cipherText) {
            char upperCh = toupper(ch);
            if (decryptMap.find(upperCh) != decryptMap.end()) {
                decryptedText += decryptMap[upperCh];
            }
            else {
                decryptedText += ch;
            }
        }
        return decryptedText;
    }
};

int main() {
    string key = "QWERTYUIOPLKJHGFDSAZXCVBNM";
    SubstitutionCipher cipher(key);

    string message = "HELLO WORLD";
    string encrypted = cipher.encrypt(message);
    string decrypted = cipher.decrypt(encrypted);

    cout << "Original: " << message << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}