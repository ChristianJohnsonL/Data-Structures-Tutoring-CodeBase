#include <iostream>
using namespace std;

void bubbleSort(int list[])
{


int temp = 0;

    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < 5; j ++)
        {
            if (list[j] > list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }

    }

    for (int i = 0; i < 5; i++)
    {
        cout << list[i];
    }

}

int main()

{
    int list[5] = {5,4,3,2,1};

}