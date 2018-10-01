def is_valid(number) :
    num_list = [(number // 1000) % 10, (number // 100) % 10, (number // 10) % 10, number % 10]
    return number > 1000 and len(num_list) == len(set(num_list))

list = []
for n0 in range(1000, 9999) :
    if is_valid(n0) :
        list += [n0]

with open('numbers.dat', 'w') as file :
    file.write(','.join(str(item) for item in list))


