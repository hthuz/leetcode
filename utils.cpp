

#include "utils.h"

void print_stack(stack<char> st)
{
    cout << "Top-> ";
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

