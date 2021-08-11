#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = { 5,1,3,7,-2,4 };
    cout << "Before sorting: ";
    for (int i = 0; i < 6; i++)
        cout << arr[i] << ' ';
    cout << endl;
    sort(arr, arr + 6);
    cout << "After sorting: ";
    for (int i = 0; i < 6; i++)
        cout << arr[i] << ' ';
}
