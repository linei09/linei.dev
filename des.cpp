#include <iostream>
#include <fstream>
#include <cstring>
#include <openssl/des.h>

int main(int argc, char* argv[]) {
    // Đọc file bitmap đã mã hóa bằng DES-CBC
    std::ifstream file_in("pic_original.bmp", std::ios::binary);
    std::streampos file_size = 0;
    if (file_in) {
        file_in.seekg(0, std::ios::end);
        file_size = file_in.tellg();
        file_in.seekg(0, std::ios::beg);
    }
    char* encrypted_data = new char[file_size];
    file_in.read(encrypted_data, file_size);

    // Khởi tạo DES với IV đã biết
    unsigned char iv[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    DES_cblock key;
    DES_key_schedule key_schedule;
    memset(&key, 0, sizeof(key));
    DES_set_odd_parity(&key);
    DES_set_key_checked(&key, &key_schedule);

    // Danh sách các khóa có thể
    unsigned char keys[256][8];
    for (int i = 0; i < 256; ++i) {
        memset(keys[i], i, 8);
    }

    // Thử giải mã với các khóa trong danh sách
    for (int i = 0; i < 256; ++i) {
        DES_key_schedule cur_key_schedule;
        DES_set_key_checked(&keys[i], &cur_key_schedule);
        unsigned char decrypted_data[file_size];
        memset(decrypted_data, 0, file_size);
        DES_cbc_encrypt((unsigned char*)encrypted_data, decrypted_data, file_size, &cur_key_schedule, &iv, DES_DECRYPT);

        // Nếu dữ liệu giải mã giống với file bitmap ban đầu, in khóa và lưu trữ kết quả
        if (decrypted_data[54] == encrypted_data[54]) {
            std::cout << "Key found: ";
            for (int j = 0; j < 8; ++j) {
                std::cout << std::hex << (int)keys[i][j];
            }
            std::cout << std::endl;
            std::ofstream file_out("decrypted_bitmap.bmp", std::ios::binary);
            file_out.write((char*)decrypted_data, file_size);
            file_out.close();
            break;
        }
    }

    delete[] encrypted_data;
    return 0;
}
