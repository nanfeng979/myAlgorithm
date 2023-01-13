#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

// 得到下标位置并将该位置的元素设置为1
void setARandom(vector<int>& have, vector<int>& noHave)
{
    if(noHave.empty()) return; // 如果副数组为空，表示主数组已经全部填充完毕

    int n = rand() % noHave.size(); // 生成一个副数组长度的n，用来寻找副数组的元素
    have[noHave[n]] = 1; // 主数组找到拿到的副数组元素作为下标，并填充该位置的值
    noHave.erase(noHave.begin() + n); // 将副数组对应的元素的下标删掉
}

void delARandom(vector<int>& have, vector<int>& noHave, int n)
{
    if(noHave.size() >= have.size()) return; // 如果副数组大于等于主数组，表示主数组现在没有有效数据
    if(have[n] == 0) return; // 如果主数组对应位置的值为0，则不必要删除

    have[n] = 0; // 将主数组对应的位置清理成无效数据
    noHave.push_back(n); // 在副数组尾部补上对应的下标值
}

// 打印两个数组
void echo(vector<int> have, vector<int> noHave)
{
    for(int i = 0; i < have.size(); i++)
    {
        cout << have[i] << " ";
    }
    cout << endl;
    cout << "----------------" << endl;
    for(int i = 0; i < noHave.size(); i++)
    {
        cout << noHave[i] << " ";
    }
    cout << endl;
    cout << "----------------" << endl;
}

int main()
{
    // 为rand函数使用的随机数生成器生成种子
    srand((int)time(0));
    // 初始化 2个数组，一个全0，一个有要求(默认按下标赋值)
    int n = 100000; // 两个数组初始长度一定要一样
    vector<int> arr(n, 0); // 主数组arr默认全部赋值0，非必须
    vector<int> noArr(n); // 副数组标记还没赋值(当前默认值为0，赋值后即非0)的元素的下标
    // 副数组一定要有主数组所有下标值的元素，顺序无所谓，例如(3,1,0,2)，每个元素对应主数组的下标
    for(int i = 0; i < noArr.size(); i++)
    {
        noArr[i] = i; // !important
    }

    // 修改n个元素
    for(int i = 0; i < n; i++)
    {
        setARandom(arr, noArr);
    }

    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // bool flag = true;
    // // 检查
    // for(int i = 0; i < n; i++)
    // {
    //     if(arr[i] == 0)
    //     {
    //         flag = false;
    //         cout << "error" << endl;
    //         break;
    //     }
    // }
    // if(flag) {
    //     cout << "success" << endl;
    // }
    
    // cout << "1:  " << endl;
    // echo(arr, noArr);

    // delARandom(arr, noArr, 5);
    // delARandom(arr, noArr, 2);
    // delARandom(arr, noArr, 2);
    // delARandom(arr, noArr, 4);

    // cout << "2:  " << endl;
    // echo(arr, noArr);


    // setARandom(arr, noArr);
    // setARandom(arr, noArr);
    // setARandom(arr, noArr);
    // // setARandom(arr, noArr);

    // cout << "3:  " << endl;
    // echo(arr, noArr);


    return 0;
}
