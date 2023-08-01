
#include<iostream>
using namespace std;




// Use adder to compute 
// Fast speed but memory usage is high

class Solution {
public:
    string addBinary(string a, string b) {
        char c_out = '0';
        char next_c_out;
        int a_val, b_val;
        string sum = "";
        char s;

        string::iterator a_it = a.end() - 1;
        string::iterator b_it = b.end() - 1;

        while(a_it >= a.begin() || b_it >= b.begin())
        {
            a_val = a_it >= a.begin() ? *a_it - '0' : 0;
            b_val = b_it >= b.begin() ? *b_it - '0' : 0;
            adder(a_val, b_val, c_out - '0', &next_c_out, &s);
            c_out = next_c_out;
            sum = s + sum;

            a_it = a_it >= a.begin() ? a_it - 1 : a_it;
            b_it = b_it >= b.begin() ? b_it - 1 : b_it;
        }
        sum = next_c_out == '0' ? sum : '1' + sum;

        return sum;
    }
private:
    void adder(int ain, int bin, int cin, char* c_out, char* s)
    {
        int a,b,c;
        a = ain;
        b = bin;
        c = cin;
        *c_out = (a & b) | (a & c) | (b & c) + '0';
        *s = a ^ b ^ c + '0';
    }
};


int main()
{
    string val = Solution().addBinary("0","0");
}

