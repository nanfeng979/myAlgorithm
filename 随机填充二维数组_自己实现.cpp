#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
#define row 120
#define col 120

void setARandom(vector<vector<int>> & have, vector<vector<int>> & noHave)
{
    if(noHave.empty()) return;

    int n = rand() % noHave.size();
    int x = noHave[n][0];
    int y = noHave[n][1];
    have[x][y] = 1;
    noHave.erase(noHave.begin() + n);
}

int main()
{
    srand((int)time(0));

    vector<vector<int>> arr(row, vector<int>(col));
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            arr[i][j] = 0;

    vector<vector<int>> noArr(row * col, vector<int>(2));
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            noArr[i*row + j] = vector<int>{i, j};

    for(int i = 0; i < row * col; i++)
        setARandom(arr, noArr);

    return 0;
}
