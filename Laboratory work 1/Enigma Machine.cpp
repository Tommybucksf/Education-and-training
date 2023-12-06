#include <iostream>
#include <vector>
#include <algorithm>

std::string operation, rotor_x, rotor_y, rotor_z, message;
int N;

// Функція для кодування повідомлення
void encode() {
    // Застосовуємо шифр Цезаря до кожного символу повідомлення
    for (char& c : message)
        c = 'A' + (c - 'A' + N++) % 26;

    // Застосовуємо перестановку (ротори) до кожного символу повідомлення
    for (const auto& rotor : {rotor_x, rotor_y, rotor_z})
        for (char& c : message)
            c = rotor[c - 'A'];
}

// Функція для декодування повідомлення
void decode() {
    // Застосовуємо зворотню перестановку (ротори) до кожного символу повідомлення
    for (const auto& rotor : {rotor_z, rotor_y, rotor_x})
        for (char& c : message)
            c = 'A' + std::distance(rotor.begin(), std::find(rotor.begin(), rotor.end(), c));

    // Застосовуємо зворотній шифр Цезаря до кожного символу повідомлення
    for (char& c : message)
        c = 'A' + (26 + (c - 'A' - N++) % 26) % 26;
}

int main() {
    // Зчитуємо вхідні дані: операцію, зсув, ротори та повідомлення
    std::cin >> operation >> N >> rotor_x >> rotor_y >> rotor_z >> message;

    // Викликаємо відповідну функцію в залежності від обраної операції
    if (operation == "ENCODE") {
        encode();
    } else if (operation == "DECODE") {
        decode();
    }

    // Виводимо результат
    std::cout << message << std::endl;

    return 0;
}
