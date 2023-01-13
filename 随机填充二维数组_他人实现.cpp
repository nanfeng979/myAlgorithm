#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
#define row 100
#define col 100

void setARandom(vector<vector<bool>>& have)
{
    vector<vector<int>> temp(0, vector<int>(2));
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if(have[i][j] == false)
                temp.push_back(vector<int>{i, j});

    if(temp.size() <= 0) return;

    int n = rand() % temp.size();
    int x = temp[n][0];
    int y = temp[n][1];
    have[x][y] = true;
}

int main()
{
    srand((bool)time(0));

    vector<vector<bool>> arr(row, vector<bool>(col));
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            arr[i][j] = false;

    for(int i = 0; i < row * col; i++)
        setARandom(arr);

    return 0;
}