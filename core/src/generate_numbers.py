import os.path


def number_to_list(number):
    return [(number // 1000) % 10, (number // 100) % 10, (number // 10) % 10, number % 10]


def is_valid(number):
    num_list = number_to_list(number)
    return number > 1000 and len(num_list) == len(set(num_list))


def valid_numbers():
    num_list = []
    for n0 in range(1000, 9999):
        if is_valid(n0):
            num_list += [n0]
    return num_list


def get_first_numbers():
    tn = [val for val in valid_numbers() if 0 not in number_to_list(val)]
    return tn


if __name__ == '__main__':
    if not os.path.isfile('../include/numbers.dat'):
        with open('../include/numbers.dat', 'w') as file:
            file.write(','.join(str(item) for item in valid_numbers()))
    if not os.path.isfile('../include/first_numbers.dat'):
        with open('../include/first_numbers.dat', 'w') as file:
            file.write(','.join(str(item) for item in get_first_numbers()))
