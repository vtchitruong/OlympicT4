import os
import sys

input_file = os.path.join(sys.path[0], 'kite.inp')
output_file = os.path.join(sys.path[0], 'kite.out')

n = 0
heights = []


def input_data():
    with open(input_file) as f:
        global n, heights

        n = int(f.readline())

        for i in range(n):
            h = f.readline()
            heights.append(h)


def process():
    # Mảng độ cao giảm dần. Mỗi phần tử là một cặp số gồm độ cao và thứ hạng
    heights_desc = []
    heights_desc.append([heights[0], 1])

    # Mảng thứ hạng dành cho output
    ranks = []
    ranks.append(1)

    for i in range(1, n):
        # Xét con diều vừa thả, tạm cho thứ hạng là 0
        # Thêm vào cuối mảng heights_desc
        tmp_height = heights[i]
        tmp_rank = 0

        heights_desc.append([tmp_height, tmp_rank])

        # Tìm vị trí j của con diều có độ cao lớn hơn con diều vừa thả
        j = len(heights_desc) - 2

        while j >= 0 and tmp_height > heights_desc[j][0]:
            heights_desc[j + 1] = heights_desc[j]
            j = j - 1

        # Lấy thứ hạng của con diều cao hơn cộng thêm 1
        tmp_rank = heights_desc[j][1] + 1

        # Chèn con diều vừa thả vào vị trí j + 1
        heights_desc[j + 1] = [tmp_height, tmp_rank]

        # Ghi nhận thứ hạng của con diều này để output
        ranks.append(tmp_rank)
    
    return ranks


def output():
    res = process()

    with open(output_file, 'w') as f:
        global n
        for i in range(n):
            f.write(f'{res[i]}\n')


if __name__ == '__main__':
    input_data()
    output()

