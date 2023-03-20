#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    int i = 0, j = 0;
    int num = 1;
    vector<vector<int>> res(n, vector<int>(n, 0));
    int k = 1;
    res[0][0] = k;
    k++;
    i++;
    while (k <= n * n)
    {
        switch (num % 4)
        {
        case 1:
            for (; i < n - num / 4; i++)
            {
                res[j][i] = k;
                k++;
            }
            i--;
            j++;
            num++;
            break;
        case 2:
            for (; j < n - num / 4; j++)
            {
                res[j][i] = k;
                k++;
            }
            j--;
            i--;
            num++;
            break;
        case 3:
            for (; i >= num / 4; i--)
            {
                res[j][i] = k;
                k++;
            }
            i++;
            j--;
            num++;
            break;
        case 0:
            for (; j >= num / 4; j--)
            {
                res[j][i] = k;
                k++;
            }
            j++;
            i++;
            num++;
            break;
        }
    }
    return res;
}

int main(){
    generateMatrix(3);
}