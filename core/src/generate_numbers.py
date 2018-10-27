import os.path


def number_to_list(number):
    return [(number // 1000) % 10, (number // 100) % 10, (number // 10) % 10, number % 10]


def is_valid(number):
    num_list = number_to_list(number)
    return number > 1000 and len(num_list) == len(set(num_list))


def valid_numbers():
    return [val for val in range(1000, 9999) if is_valid(val)]


def get_first_numbers():
    return [val for val in valid_numbers() if 0 not in number_to_list(val)]


if __name__ == '__main__':
    if not os.path.isfile('../include/numbers.dat'):
        with open('../include/numbers.dat', 'w') as file:
            file.write(','.join(str(item) for item in valid_numbers()))
    if not os.path.isfile('../include/first_numbers.dat'):
        with open('../include/first_numbers.dat', 'w') as file:
            file.write(','.join(str(item) for item in get_first_numbers()))
