#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void setARandom(vector<int>& have)
{
    vector<int> temp(0);
    for(int i = 0; i < have.size(); i++)
    {
        if(have[i] == 0)
        {
            temp.push_back(i);
        }
    }

    int n = rand() % temp.size();
    have[temp[n]] = 1; 
}

int main()
{
    srand((int)time(0));
    int n = 10000;
    vector<int> arr(n, 0);

    // 修改n个元素
    for(int i = 0; i < n; i++)
    {
        setARandom(arr);
    }

    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    


    return 0;
}