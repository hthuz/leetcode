
#include <iostream>
#include "lib.h"

using namespace std;


void print_vec(vector<int>& nums)
{
    cout << "[";
    for(int x : nums)
        cout << x << " ";
    cout << "]" << endl;
}


void print_2dvec(vector<vector<int>>& nums)
{
    cout << "[";
    for(vector<int> one_vec : nums)    
    {
        cout << "[";
        for(int x : one_vec)
            cout << x << " ";
        cout << "]";
    }
    cout << "]" << endl;
}
