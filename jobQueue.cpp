#include "jobQueue.h"

jobQueue::jobQueue()
{
    front = nullptr;
}

bool jobQueue::isempty()
{
    return (front == nullptr ? true : false);
}

// Checks if there are any more jobs to perform
bool jobQueue::isHoursRemaining()
{
    node *current = front;
    while (current != nullptr)
    {
        if (current->remainingTime != 0)
            return true;
        current = current->next;
    }
    return false;
}

void jobQueue::add(int v)
{
    node *n = new node;
    n->burstTime = v;
    n->remainingTime = v;
    n->waitingTime = 0;
    n->next = nullptr;
    if (front == nullptr)
        front = n;
    else
    {
        node *current = front;
        while (current->next != nullptr)
            current = current->next;
        current->next = n;
    }
    cout << "Added " << v << " to the job jobQueue." << endl;
}

void jobQueue::serve()
{
    node *current = front;
    node *firstNode = nullptr;
    int firstTime = 0;
    while (current != nullptr)
    {
        if (current->remainingTime != 0)
        {
            int wait = 0;
            //current->waitingTime += wait;
            if (current->remainingTime > 1)
            {
                current->remainingTime -= 2;
                wait += 2;
                /*
                if (firstNode == nullptr)
                {
                    firstNode = current;
                    firstTime += 2;
                }
                */
            }
            else if (current->remainingTime == 1)
            {
                current->remainingTime--;
                wait++;
                /*
                if (firstNode == nullptr)
                {
                    firstNode = current;
                    firstTime += 1;
                }
                */
            }

            // Add waiting time to each job
            node *temp = front;
            int count = 1;
            while (temp != nullptr)
            {
                if (temp != current && temp->remainingTime != 0)
                {
                    temp->waitingTime += wait;
                    cout << "Added " << wait << " time to Job " << count << endl;
                }
                count++;
                temp = temp->next;
            }
        }
        current = current->next;
    }

    // Find the first non-zero job with time remaining
    //if (firstNode->remainingTime != 0)
    //    firstNode->waitingTime += (wait - firstTime);
}

void jobQueue::print()
{
    node *current = front;
    int count = 1;
    while (current != nullptr)
    {
        cout << "Job " << count << ", burst time: " << current->burstTime << ", remaining time: " << current->remainingTime << ", waiting time: " << current->waitingTime << endl;
        current = current->next;
        count++;
    }
    cout << endl;
}

void jobQueue::writeToFile(string outName)
{
    ofstream outFile;
    outFile.open(outName);
    node *current = front;
    int count = 1;
    while (current != nullptr)
    {
        outFile << "Job " << count << ", burst time: " << current->burstTime << ", waiting time: " << current->waitingTime << endl;
        current = current->next;
        count++;
    }
    outFile.close();
}
