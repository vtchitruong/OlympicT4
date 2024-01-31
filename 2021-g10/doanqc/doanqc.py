import os
import sys

input_file = os.path.join(sys.path[0], 'doanqc.inp')
output_file = os.path.join(sys.path[0], 'doanqc.out')

n = 0 # number of customers
customers = [] # Each element is a tuple of (checkIn, checkOut)
ad_schedule = [] # output


def input_data():
    with open(input_file) as f:
        global n, customers

        n = int(f.readline())

        for i in range(n):
            check_in, check_out = map(int, f.readline().split())
            customers.append((check_in, check_out))


def process():
    # The first customer, i.e. the first check-in point
    first_check_in = min(customers, key=lambda t: t[0])[0]

    # Store this point
    ad_schedule.append(first_check_in)

    # Sort by check-in of customers in ascending order
    customers.sort(key=lambda t: t[1])

    # The last ad broadcast
    # Init by getting the minimum value of int data type
    last_broadcast = float('-inf')

    for customer in customers:    
        # Get the check-out point of each customer
        check_in, check_out = customer

        # If the check-out point happens after the latest ad broadcast
        # then store this check-out point as the new-latest ad broadcast
        if check_out <= last_broadcast:
            continue

        ad_schedule.append(check_out)
        last_broadcast = check_out


def output():
    global ad_schedule
    with open(output_file, 'w') as f:
        f.write(str(len(ad_schedule)))
        f.write('\n')
        f.write(' '.join(map(str, ad_schedule)))


if __name__ == '__main__':
    input_data()
    process()
    output()