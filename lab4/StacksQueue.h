#include "ADTQueue.h"
#include "Iterador.h"
#include <vector>

using namespace std;

class StacksQueue : public ADTQueue {
    private:
        vector<int> st1, st2;
    public:
        StacksQueue();
        ~StacksQueue();
        void push(int x);
        void pop();
        int front();
        int size();
        bool empty();
        Iterador begin();

};