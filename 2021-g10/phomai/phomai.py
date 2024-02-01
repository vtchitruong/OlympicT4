import os
import sys

input_file = os.path.join(sys.path[0], 'phomai.inp')
output_file = os.path.join(sys.path[0], 'phomai.out')

a = b = 0 # khối lượng 2 miếng phô mai


def input_data():
    with open(input_file) as f:
        global a, b
        a, b = map(int, f.readline().split())


# Tìm ước chung lớn nhất
def gcd(m, n):
    while n != 0:
        m, n = n, m % n

    return m


def process():
    global a, b
    if a == b:
        return 0

    c = 0 # count: số lần ăn phô mai của cáo
  
    # Tìm ước chung lớn nhất của a và b
    g = gcd(a, b)

    # Lần lượt chia a cho 2, 3 và 5 để đếm số lần cắn phô mai của cáo
    for i in [2, 3, 5]:
        while a % i == 0:
            # Nếu đã bằng UCLN thì không cần cắn miếng phô mai a nữa
            if a == g:
                break
            a = a / i
            c += 1

    # Nếu a vẫn chưa chạm được tới UCLN thì không thể chia phô mai được
    if a != g:
        return -1 

    # Lần lượt chia b cho 2, 3 và 5 để đếm số lần cắn phô mai của cáo
    for i in [2, 3, 5]:
        while b % i == 0:
            # Nếu đã bằng UCLN thì không cần cắn miếng phô mai a nữa
            if b == g:
                break
            b = b / i
            c += 1 

    # Nếu b vẫn chưa chạm được tới UCLN thì không thể chia phô mai được
    if b == g:
        return c
    else:
        return -1


def output():
    res = str(process())

    with open(output_file, 'w') as f:
        f.write(res)


if __name__ == '__main__':
    input_data()
    output()