#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

#define inputFile "doanqc.inp"
#define outputFile "doanqc.out"

using namespace std;

int n; // number of customers
vector<pair<int, int>> customers; // Each element is a pair of {checkIn, checkOut}
vector<int> adSchedule; // output


void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n;

    for (int i = 0; i < n; ++i)
    {
        int checkIn, checkOut;
        f >> checkIn >> checkOut;
        customers.push_back({checkIn, checkOut});
    }

    f.close();
}


// Used for sorting the customers array by the check-outs
bool Compare(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}


void Process()
{
    // Find the minimum value of check-in points
    vector<pair<int, int>>::iterator firstCheckInCustomer = min_element(customers.begin(), customers.end(),
                                    [](const pair<int, int>& a, const pair<int, int>& b) {return a.first < b.first; });

    // The first customer, i.e. the first check-in point
    int firstCheckIn = (*firstCheckInCustomer).first;

    // Store this point
    adSchedule.push_back(firstCheckIn);

    // Sort by check-in of customers in ascending order
    sort(customers.begin(), customers.end(), Compare);

    // The last ad broadcast
    // Init by getting the minimum value of int data type
    int lastBroadcast = numeric_limits<int>::min();

    for (pair<int, int> customer : customers)
    {
        // Get the check-out point of each customer
        int checkOut = customer.second;

        // If the check-out point happens after the latest ad broadcast
        // then store this check-out point as the new-latest ad broadcast
        if (checkOut <= lastBroadcast) continue;

        adSchedule.push_back(checkOut);
        lastBroadcast = checkOut;
    }
}

void Output()
{
    ofstream f;
    f.open(outputFile);

    int s = adSchedule.size();
    f << s << '\n';

    for (int i = 0; i < s; ++i)
    {
        f << adSchedule[i];
        if (i < s - 1) f << ' ';
    }

    f.close();
}


int main()
{
    Input();
    Process();
    Output();

    return 0;
}