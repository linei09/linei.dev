#include "include/cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include <vector>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <iomanip>
#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include "include/cryptopp/cryptlib.h"
using CryptoPP::Exception;

#include "include/cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "include/cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;

#include "include/cryptopp/files.h"

#include "include/cryptopp/des.h"
using CryptoPP::DES;
//using namespace CryptoPP;

#include "include/cryptopp/modes.h"
using CryptoPP::CBC_Mode;

#include "include/cryptopp/secblock.h"
using CryptoPP::SecByteBlock;
 
#include "include/cryptopp/cryptlib.h"

using CryptoPP::byte;
bool checkDecryptedData(string recovered, string encoded_data)
 {
    // check decoded data length
    if(recovered.length()!=encoded_data.length()) return false;
    // check data accuracy
    if(recovered!=encoded_data) return false;
    return true;
}
int main()
{

   byte iv[DES::BLOCKSIZE];
    // assuming know iv is C345AD4B8F1B238D
   const char* iv_str="C345AD4B8F1B238D";
   memcpy(iv,iv_str,DES::BLOCKSIZE);


   // read the pre-generated random key file
   std::vector<std::vector<byte>> keys;
    std::ifstream key_file("des_key.bin", std::ios::binary);
    if (!key_file) {
        cerr << "Error: failed to open key file." << endl;
        return 1;
    }
    // declare key
    byte key[DES::DEFAULT_KEYLENGTH];
    //Use while loop to read data from key file and store it in key byte array
    while (key_file.read((char*)key, DES::DEFAULT_KEYLENGTH)) {
        // After reading each keyword, we create a new byte vector using the vector's constructor and pass in the key byte array and its length.
        //Then we add this new byte vector to the end of the keys vector using push_back() method.
        keys.push_back(std::vector<byte>(key, key + DES::DEFAULT_KEYLENGTH));
    }
    key_file.close();


     // Read encrypted file contents
    std::ifstream infile;
    infile.open("test_des.txt");
    if (!infile) {
        cerr << "Không thể mở file!" << endl;
        exit(1);   // exit if can't open file
    }
    string encoded_data;
    while (getline(infile, encoded_data)) {       
        cout << encoded_data << endl;
    }
    infile.close();

    //mark variable to find the right keyword
   bool key_found = false;
   //traverse the keys in the keys vector
    for (const auto& k : keys)
    {
        //perform decryption
        CBC_Mode<DES>::Decryption d;
        d.SetKeyWithIV(k.data(), k.size(), iv);
        string recovered;
        StringSource s(encoded_data, true, 
            new StreamTransformationFilter(d, new StringSink(recovered))
        );

        // Check the decryption results to determine the correct key
        // If the decoding result is correct, break from the loop
        if (checkDecryptedData(recovered,encoded_data)) 
        {
            cout << "Correct key found!" << endl;
            key_found = true;
            break;
        }
    }

    // If the correct key is not found
    if (!key_found) 
    {
        cout << "Correct key not found." << endl;
    }

    system("Pause");
    return 0;
}
   
