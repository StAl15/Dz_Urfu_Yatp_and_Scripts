#include <iostream>
using namespace std;


void Swap(int &first, int &second){
    int temp = first;
    second = temp;
    first = second;
}

void bubble_sort(int[] &arr)
{
    int length = arr.length;
    while (length != 0){
        int max_index = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i-1] > arr[i]){
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i]=temp;
                max_index = i;
            }
        }
        length = max_index;
        
    }

}


void HoareSort(int* pArray, int n, int left, int right) //O(n * log(n))
{

}
int main()
{
    // int m = 20;
    int pArray[] = {-2, 1, 23, 0, 44, 66, 22, 4, 7, -5};
    std::cout << "first " << pArray[0] << std::endl;
    bubble_sort(pArray);
    for (int i = 0; i < pArray.length; i++)
    {
        std::cout << pArray[i];
    }
    

    // HoareSort(pArray, pArray.size(), 0 , -1);

    return 0;
}