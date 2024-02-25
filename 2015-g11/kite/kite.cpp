#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

#define inputFile "kite.inp"
#define outputFile "kite.out"

using namespace std;

int n;
vector<int> heights;

void input()
{
    ifstream f;
    f.open(inputFile);

    f >> n;

    int h;
    for (int i = 0; i < n; ++i)
    {
        f >> h;
        heights.push_back(h);
    }

    f.close();
}


vector<int> process()
{
    // Mảng độ cao giảm dần. Mỗi phần tử là một cặp gồm độ cao và thứ hạng
    vector<pair<int, int>> heightsDesc;
    heightsDesc.push_back(make_pair(heights[0], 1));

    // Mảng thứ hạng dành cho output
    vector<int> ranks;    
    ranks.push_back(1);

    for (int i = 1; i < n; ++i)
    {
        // Xét con diều vừa thả, tạm cho thứ hạng là 0
        // Thêm vào cuối mảng heightsDesc
        int tmpHeight = heights[i];
        int tmpRank = 0;

        heightsDesc.push_back(make_pair(tmpHeight, tmpRank));

        // Tìm vị trí j của con diều có độ cao lớn hơn con diều vừa thả
        int j = heightsDesc.size() - 2;

        while (j >= 0 && tmpHeight > heightsDesc[j].first)
        {
            heightsDesc[j + 1] = heightsDesc[j];
            j = j - 1;
        }

        // Lấy thứ hạng của con diều cao hơn một thêm 1
        tmpRank = heightsDesc[j].second + 1;

        // Chèn diều vừa thả vào trị ví j + 1
        heightsDesc[j + 1] = make_pair(tmpHeight, tmpRank);

        // Ghi nhận thứ hạng của con diều này để output
        ranks.push_back(tmpRank);
    }

    return ranks;
}


void output()
{
    vector<int> res = process();

    ofstream f;
    f.open(outputFile);

    for (int i = 0; i < res.size(); ++i)
    {
        f << res[i] << endl;
    }

    f.close();
}


int main()
{
    input();
    process();
    output();

    return 0;
}



