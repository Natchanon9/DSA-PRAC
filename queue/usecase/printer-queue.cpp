#include <iostream>
#include <queue>
#include <string>

using namespace std;

class PrintJob
{
public:
    string documentName;
    int numberOfPages;
    PrintJob(string docName, int pages) : documentName(docName), numberOfPages(pages)
    {
    }
};
class PrinterQueue
{
private:
    queue<PrintJob> printQueue;

public:
    void addJob(const PrintJob &job)
    {
        printQueue.push(job);
        cout << "Added to queue: " << job.documentName << "(" << job.numberOfPages << " pages)" << endl;
    }
    void processJobs()
    {
        while (!printQueue.empty())
        {
            PrintJob currentJob = printQueue.front();
            cout << "Printing: " << currentJob.documentName << " (" << currentJob.numberOfPages << " pages)" << endl;
            printQueue.pop();
        }
        cout << "All print jobs completed. " << endl;
    }
};
int main()
{

    PrinterQueue printQ;
    printQ.addJob(PrintJob("Document1.pdf", 10));
    printQ.addJob(PrintJob("Document2.pdf", 20));
    printQ.addJob(PrintJob("Document3.pdf", 10));

    printQ.processJobs();
    return 0;
}