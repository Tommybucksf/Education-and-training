#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

// Функція
std::string xorHexStrings(const std::string& str1, const std::string& str2) {
    std::string result;
    for (std::size_t i = 0; i < str1.size(); i += 2) {
        // Конвертація шістнадцяткових символів в цілі числа
        std::istringstream iss1(str1.substr(i, 2));
        std::istringstream iss2(str2.substr(i, 2));
        int num1, num2;
        
        // Конвертація шістнадцяткових символів з рядка str в цілі числа
        iss1 >> std::hex >> num1;
        iss2 >> std::hex >> num2;
        
        // XOR цілих чисел та конвертація результату назад у шістнадцятковий вигляд
        int xorResult = num1 ^ num2;
        std::stringstream ss;
        ss << std::hex << std::setw(2) << std::setfill('0') << xorResult;
        result += ss.str();
    }
    return result;
}

int main() {
    std::string message_1;
    std::getline(std::cin, message_1);
    std::string message_2;
    std::getline(std::cin, message_2);
    std::string message_3;
    std::getline(std::cin, message_3);

    // Виклик функції для операції XOR над введеними рядками
    std::string result = xorHexStrings(message_1, message_2); 

    // Виклик функції для додаткової операції XOR з третім рядком
    std::string xorResult2 = xorHexStrings(result, message_3);

    // Виведення результату у вигляді ASCII-символів
    for (size_t i = 0; i < xorResult2.length(); i += 2) {
        std::string byteStr = xorResult2.substr(i, 2);
        int decimalValue = std::stoi(byteStr, 0, 16);
        // Виведення ASCII-символу
        std::cout << static_cast<char>(decimalValue);
    }

    return 0;
} 