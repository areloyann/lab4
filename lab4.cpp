#include <iostream>
#include <string>
using namespace std;
class CaesarCipher {
public:
    CaesarCipher(int shift) : shiftValue(shift) {}

    string encrypt(const string &text) {
        string encryptedText = "";
        for (char ch : text) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                encryptedText += (ch - base + shiftValue) % 26 + base;
            } else {
                encryptedText += ch;
            }
        }
        return encryptedText;
    }

    string decrypt(const string &text) {
        string decryptedText = "";
        for (char ch : text) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                decryptedText += (ch - base - shiftValue + 26) % 26 + base;
            } else {
                decryptedText += ch;
            }
        }
        return decryptedText;
    }

private:
    int shiftValue;
};

int main() {
    string word = "Hello, World!";
    int shiftValue = 3;

    CaesarCipher cipher(shiftValue);

    string encrypted = cipher.encrypt(word);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = cipher.decrypt(encrypted);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
