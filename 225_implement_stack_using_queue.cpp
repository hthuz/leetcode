

#include "utils.h"

class MyStack {
private:
    queue<int> queue1;
    queue<int> queue2;

public:
    MyStack() {

    }
    
    void push(int x) {
        queue1.push(x);
    }
    
    int pop() {
        int elt;
        while(!queue1.empty())
        {
            elt = queue1.front();
            if(queue1.size() != 1)
                queue2.push(elt);
            queue1.pop();
        }
        while(!queue2.empty())
        {
            queue1.push(queue2.front());
            queue2.pop();
        }
        return elt;
    }
    
    int top() {
        int elt;
        while(!queue1.empty())
        {
            elt = queue1.front();
            queue2.push(elt);
            queue1.pop();
        }
        while(!queue2.empty())
        {
            queue1.push(queue2.front());
            queue2.pop();
        }
        return elt;
    }
    
    bool empty() {
        return queue1.empty();
    }
};


int main()
{
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << obj->top() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->empty() << endl;


}
