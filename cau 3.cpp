#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hàm kiểm tra padding của khối dữ liệu
bool checkPadding(vector<unsigned char>& data) {
    int padding = data.back(); // Giá trị padding là byte cuối cùng của khối
    int dataSize = data.size();

    // Kiểm tra byte padding có giá trị hợp lệ
    for (int i = dataSize - padding; i < dataSize; i++) {
        if (data[i] != padding) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<unsigned char> encryptedData = /* Dữ liệu đã được mã hóa CBC cùng padding */;
    string decryptedData = "";

    // Giả sử kẻ tấn công đã biết được giá trị của các khối mã hóa

    int numBlocks = encryptedData.size() / 16; // Số lượng khối
    for (int i = numBlocks - 1; i >= 0; i--) { // Bắt đầu từ khối cuối cùng

        vector<unsigned char> modifiedData = encryptedData; // Tạo một bản sao của dữ liệu đã mã hóa
        int padding = numBlocks - i; // Giá trị padding cần kiểm tra
        for (int j = 15; j >= 0; j--) { // Thử giá trị của byte cuối cùng
            modifiedData[i * 16 + j] ^= padding; // Đảo bit của byte cuối cùng để thay đổi giá trị của padding

            if (checkPadding(modifiedData)) { // Kiểm tra padding
                decryptedData = (char) (encryptedData[i * 16 + j] ^ padding ^ encryptedData[i * 16 + j - 1]) + decryptedData; // Giải mã byte cuối cùng của khối
                break;
            }

            modifiedData[i * 16 + j] ^= padding; // Đảo lại bit của byte cuối cùng để phục hồi giá trị ban đầu
        }
    }

    cout << "Dữ liệu đã được giải mã: " << decryptedData << endl;

    return 0;
}
