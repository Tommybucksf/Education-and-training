import numpy as np

def scanner(qrcode):
    #Ініціалізація масиву для зберігання QR-коду після застосування маски
    masked_qr = [[0] * 21 for _ in range(21)]
    
    #Застосування маски до вхідного QR-коду
    for row_idx, row in enumerate(qrcode):
        for col_idx, value in enumerate(row):
            if (row_idx + col_idx) % 2 == 0:
                value = 1 - value
            masked_qr[row_idx][col_idx] = value

    #Конвертація списку в NumPy масив та обрізання верхньої частини
    qr_array = np.array(masked_qr)[9:]

    #Читання даних із QR-коду
    is_odd_row = False
    decoded_bits = []
    for col in [19, 17, 15, 13]:
        column_data = qr_array[:, [col, col + 1]]
        direction = 1 if is_odd_row else -1
        
        for row_data in column_data[::direction]:
            decoded_bits.extend(row_data.tolist()[::-1])
        is_odd_row = not is_odd_row

    #Об'єднання бітів у рядок та обчислення довжини повідомлення
    binary_string = ''.join(map(str, decoded_bits[4:]))
    message_length = int(binary_string[:8], 2)
    binary_string = binary_string[8:]

    #Декодування повідомлення
    message = ''
    for index in range(0, message_length * 8, 8):
        character = chr(int(binary_string[index:index + 8], 2))
        message += character

    return message
