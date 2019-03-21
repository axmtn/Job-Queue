#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct node
{
    int burstTime;
    int remainingTime;
    int waitingTime;
    node* next;
};

class jobQueue
{
    private:
        node* front;
    public:
        jobQueue();
        bool isempty();
        bool isHoursRemaining();
        void add(int v);
        void serve();
        void print();
        void writeToFile(string outName);
};
