//
//  HashTable.h
//  Lab9
//
//  Created by kareem ahmed shawky on 5/3/23.
//

#ifndef HashTable_h
#define HashTable_h
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable
{
private:
    int TableSize;
    vector <list<int>> Hash_Table;
public:
    HashTable(int size)
    {
        TableSize = size;
        Hash_Table.resize(size);
    }
    
    int HashFunc(int value)
    {
        return value % TableSize;
    }
    
    void insert(int val)
    {
        int i = HashFunc(val);
        Hash_Table[i].push_back(val);
    }
    
    void PrintTable()
    {
        for(int i = 0; i < TableSize; i++)
        {
            cout << "Index " << i << ": ";
            for(int j : Hash_Table[i])
            {
                cout << j << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

#endif /* HashTable_h */
