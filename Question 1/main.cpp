//
//
// Karim Shawky 900221948
//
//

#include <iostream>
#include "HashTable.h"
using namespace std;

int  main()
{
    int arr[10] = {1, 4, 7, 1, 5, 2, 4, 1, 3, 5};
    HashTable HashTbl(10);
    
    for(int i = 0; i < 10; i++)
    {
        HashTbl.insert(arr[i]);
    }
    
    HashTbl.PrintTable();
    return 0;
}

