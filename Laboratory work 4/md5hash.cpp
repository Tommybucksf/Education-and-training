// Crack the PIN md5hash
#include <iostream>
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>

std::string crack(const std::string& hash) {
    char input[6]; // Буфер для зберігання PIN-коду у вигляді рядка

    // Цикл ітерує від 0 до 99999, генеруючи всі можливі PIN-коди
    for (int i = 0; i <= 99999; i++) {
        // Форматуємо ітераційне число у вигляді рядка PIN-коду (від '00000' до '99999')
        sprintf(input, "%05d", i); 

        unsigned char digest[MD5_DIGEST_LENGTH]; // Масив для зберігання MD5 хешу

        // Генеруємо MD5 хеш від рядка PIN-коду
        MD5((const unsigned char*)input, strlen(input), digest);

        char md5string[33]; // Рядок для зберігання MD5 хешу у вигляді шістнадцяткових чисел

        // Конвертуємо кожен байт хешу у шістнадцятковий формат та зберігаємо у md5string
        for (int j = 0; j < 16; j++) {
            sprintf(&md5string[j * 2], "%02x", (unsigned int)digest[j]);
        }

        // Порівнюємо згенерований MD5 хеш із заданим хешем
        if (hash == md5string) {
            return input; // Якщо хеші збігаються, повертаємо відповідний PIN-код
        }
    }

    return ""; // Якщо збіг не знайдено, повертаємо пустий рядок
}
