#include "include/cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;
using CryptoPP::byte;
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
using CryptoPP::DES_EDE2;

#include "include/cryptopp/modes.h"
using CryptoPP::CBC_Mode;

#include "include/cryptopp/secblock.h"
using CryptoPP::SecByteBlock;
 
#include "include/cryptopp/cryptlib.h"
using namespace CryptoPP;

bool check_decrypted_data(const std::string& decrypted_data) {
    
}
int main()
{
    byte iv[DES_EDE2::BLOCKSIZE];
    // giả sử đã biết iv là C345AD4B8F1B238D
   const char* iv_str="C345AD4B8F1B238D";
   memcpy(iv,iv_str,DES_EDE2::BLOCKSIZE);
    std::ifstream file_in("text_des.txt", std::ios::binary);
    std::streampos file_size = 0;
    // kiểm tra kích thước của file
    if (file_in) {
        file_in.seekg(0, std::ios::end);
        file_size = file_in.tellg();
        file_in.seekg(0, std::ios::beg);
    }
    char* encrypted_data = new char[file_size];
    file_in.read(encrypted_data, file_size);

    //
   AutoSeededRandomPool rng;

    // Tạo danh sách 1000 khóa ngẫu nhiên
    const int num_keys = 1000;
    byte keys[num_keys][16];
    for (int i = 0; i < num_keys; i++) {
        rng.GenerateBlock(keys[i], sizeof(keys[i]));
    }

    // In ra danh sách các khóa dưới dạng hex
    for (int i = 0; i < num_keys; i++) {
        std::cout << "Key " << i << ": ";
        StringSource(keys[i], sizeof(keys[i]), true,
                     new HexEncoder(new FileSink(std::cout)));
        std::cout << std::endl;
    // giải mã với dữ liệu hiện tại
    std::string decrypted_data;
    try {
        CBC_Mode<DES_EDE2>::Decryption d;
        d.SetKeyWithIV(key, sizeof(key), iv);
        CryptoPP::StringSource ss((const byte*)encrypted_data, file_size, true,
            new CryptoPP::StreamTransformationFilter(d,
                new CryptoPP::StringSink(decrypted_data)));
    }
    catch (CryptoPP::Exception& e) {
        continue; // Nếu không giải mã được thì thử khóa tiếp theo
    }

    // Kiểm tra xem dữ liệu giải mã có hợp lệ hay không
    if (check_decrypted_data(decrypted_data)) {
        std::cout << "Found key: ";
        for (int k = 0; k < DES_EDE2::DEFAULT_KEYLENGTH; k++) {
            std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)key[k];
        }
        std::cout << std::endl;
        break; // Thoát vòng lặp nếu tìm thấy khóa đúng
    }
}
      system("Pause");
    return 0;
}
