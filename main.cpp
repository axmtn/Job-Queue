#include "jobQueue.h"
#include "ArgumentManager.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: ./EvalExpr \"input=<file>;output=<file>\"" << endl;
        return -1;
    }

    ArgumentManager am(argc, argv);
    string inFileName = am.get("input");
    string outFileName = am.get("output");

    ifstream inFile;
    inFile.open(inFileName);

    //Initialize the job queue
    jobQueue q;
    while (!inFile.eof())
    {
        int in;
        inFile >> in;
        q.add(in);
    }
    inFile.close();

    while (q.isHoursRemaining())
    {
        q.serve();
        q.print();
    }
    q.writeToFile(outFileName);

    return 0;
}
