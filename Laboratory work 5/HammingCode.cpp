#include <string>
#include <bitset>
#include <vector>

std::string encode(std::string text) {
   
    std::string result;

    for (size_t i = 0; i < text.length(); ++i) {
        //ASCII
        int asciiValue = static_cast<int>(text[i]);
        
        //ASCII в 8-бітовий
        std::string binary = std::bitset<8>(asciiValue).to_string();

        //Подвоюємо кожен біт три рази і додаємо до результату
        for (char bit : binary) {
            result += std::string(3, bit);
        }
    }

    return result;
}

std::string decode(std::string bits) {
   
    std::string correctedBits;

    for (size_t i = 0; i < bits.length(); i += 3) {
        int ones = 0;
        for (size_t j = i; j < i + 3; ++j) {
            if (bits[j] == '1') {
                ++ones;
            }
        }
        //Перевірка та виправлення бітів на основі їхньої кількості одиниць
        correctedBits += (ones >= 2) ? '1' : '0';
    }

    std::string text;  

    for (size_t i = 0; i < correctedBits.length(); i += 8) {
        // Розбивка виправлених бітів на 8-бітові групи
        std::string byte = correctedBits.substr(i, 8);
        
        //Конвертування в символ
        char c = static_cast<char>(std::bitset<8>(byte).to_ulong());
        text += c;
    }

    return text;
}
