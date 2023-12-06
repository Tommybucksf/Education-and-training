#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Функція для зсуву букв у рядку
std::string shiftLetters(const std::string& input, int shift) {
    std::string code = input;

    // Проходимо через кожен символ у рядку
    for (char& ch : code) {
        if (std::isalpha(ch)) {  // Якщо символ - буква
            char base = std::isupper(ch) ? 'A' : 'a'; // Визначаємо базовий символ для великих або малих літер
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base); // Зсуваємо букву та вираховуємо новий символ
        }
    }

    return code;
}

// Функція для знаходження оптимального зсуву для дешифрування
int findBestShift(const std::string& input) {
    std::vector<int> letterFrequency(26, 0);

    // Рахуємо кількість входжень кожної літери у рядок
    for (char ch : input) {
        if (std::isalpha(ch)) {  // Якщо символ - буква
            char base = std::isupper(ch) ? 'A' : 'a'; // Визначаємо базовий символ для великих або малих літер
            ++letterFrequency[ch - base]; // Збільшуємо лічильник для відповідної літери
        }
    }

    // Знаходимо індекс літери з найбільшою кількістю входжень
    auto maxFrequencyIter = std::max_element(letterFrequency.begin(), letterFrequency.end());
    int maxFrequencyIndex = std::distance(letterFrequency.begin(), maxFrequencyIter);

    // Розраховуємо оптимальний зсув за формулою
    int shift = maxFrequencyIndex - ('E' - 'A');

    return shift;
}

int main() {
    std::string encodedMessage;
    std::getline(std::cin, encodedMessage);

    // Знаходимо оптимальний зсув для дешифрування
    int bestShift = findBestShift(encodedMessage);

    // Дешифруємо рядок та виводимо результат
    std::string decodedMessage = shiftLetters(encodedMessage, -bestShift);
    std::cout << decodedMessage << std::endl;

    return 0;
}
