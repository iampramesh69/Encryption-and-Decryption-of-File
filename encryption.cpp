#include "encryption.h"
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

// Caesar cipher function
bool performCaesarCipher(string& content, bool encrypt) {
    int shift = encrypt ? 3 : -3;

    for (char& ch : content) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
    }
    return true;
}

// Correct function name + spelling + logic
bool encryptFile(const string& filename, bool encrypt) {

    // Open input file
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }

    // Read entire file
    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    // Apply cipher
    performCaesarCipher(content, encrypt);

    // Output file name
    string outFileName = (encrypt ? "encrypted_" : "decrypted_") + filename;

    ofstream outFile(outFileName);
    if (!outFile) {
        return false;
    }

    outFile << content;
    outFile.close();

    return true;
}
