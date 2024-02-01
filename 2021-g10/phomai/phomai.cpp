#include <iostream>
#include <fstream>
#include <vector>

#define inputFile "phomai.inp"
#define outputFile "phomai.out"

using namespace std;

int a, b; // khối lượng 2 miếng phô mai


void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> a >> b;

    f.close();
}


// Tìm ước chung lớn nhất
int GCD(int m, int n)
{
    while (n != 0)
    {
        int t = n;
        n = m % n;
        m = t;
    }

    return m;
}


int Process()
{
    if (a == b) return 0;

    int c = 0; // count: số lần ăn phô mai của cáo

    // Tìm ước chung lớn nhất của a và b
    int gcd = GCD(a, b);

    // Lần lượt chia a cho 2, 3 và 5 để đếm số lần cắn phô mai của cáo
    vector<int> v = {2, 3, 5};

    for (int i : v)
    {
        while (a % i == 0)
        {
            // Nếu đã bằng UCLN thì không cần cắn miếng phô mai a nữa
            if (a == gcd) break;
            a = a / i;
            c++;
        }
    }

    // Nếu a vẫn chưa chạm được tới UCLN thì không thể chia phô mai được
    if (a != gcd) return -1;

    // Lần lượt chia b cho 2, 3 và 5 để đếm số lần cắn phô mai của cáo
    for (int i : v)
    {
        while (b % i == 0)
        {
            // Nếu đã bằng UCLN thì không cần cắn miếng phô mai a nữa
            if (b == gcd) break;
            b = b / i;
            c++;
        }
    }

    // Nếu b vẫn chưa chạm được tới UCLN thì không thể chia phô mai được
    if (b == gcd)
        return c;
    else
        return -1;
}


void Output()
{
    int res = Process();

    ofstream f;
    f.open(outputFile);

    f << res;

    f.close();
}


int main()
{
    Input();
    Output();

    return 0;
}