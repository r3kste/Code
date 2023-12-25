#include <bits/stdc++.h>
using namespace std;
using PId = int;

string o = ""; // Final Output

struct Process
{
    Process *previousProcess;
    Process *nextProcess;
    PId id; // Data
};

struct Process *start = new Process; // Placeholder Process: used for traversing the Process List

class Scheduler
{
public:
    Process *add_Process (PId pid)
    {
        start->id = -1;
        struct Process *ptr = start;     // Pointer

        while (ptr->nextProcess != NULL) // Traversing the Process List
        {
            ptr = ptr->nextProcess;
        }

        struct Process *new_Process = new Process; // New Process

        new_Process->id = pid;                     // Store the given pid in the new process
        ptr->nextProcess = new_Process;            // Make the necessary changes to the links
        new_Process->nextProcess = NULL;
        new_Process->previousProcess = ptr;
        return start;
    }

    void delete_Process (PId pid)
    {
        start->id = -1;
        struct Process *ptr = start;          // Pointer

        while (ptr != NULL && ptr->id != pid) // Traversing the Process List
        {
            ptr = ptr->nextProcess;
        }

        if (ptr != NULL)
        {
            struct Process *temp1 = ptr->previousProcess; // Process just before the process to be deleted
            struct Process *temp2 = ptr->nextProcess;     // Process just after the process to be deleted

            if (temp1 != NULL)                            // Join temp1 and temp2
            {
                temp1->nextProcess = temp2;
            }

            if (temp2 != NULL)
            {
                temp2->previousProcess = temp1;
            }

            ptr = NULL; // Delete the required process
        }
    }

    Process *fork (PId pid0, PId pid1)
    {
        start->id = -1;
        struct Process *ptr = start;           // Pointer

        while (ptr != NULL && ptr->id != pid0) // Traversing the Process List
        {
            ptr = ptr->nextProcess;
        }

        if (ptr != NULL)
        {
            struct Process *temp = ptr->nextProcess; // Process just after the process to be forked
            struct Process *new_Fork = new Process;  // New Process
            new_Fork->id = pid1;                     // Store the required pid in new fork
            ptr->nextProcess = new_Fork;             // Make the necessary changes to the links
            new_Fork->previousProcess = ptr;
            new_Fork->nextProcess = temp;

            if (temp != NULL)
            {
                temp->previousProcess = new_Fork;
            }
        }

        return start;
    }

    void print_schedule()
    {
        start->id = -1;
        struct Process *ptr = start->nextProcess; // Pointer

        while (ptr != NULL)
        {
            o.append (to_string (ptr->id) + " ");
            ptr = ptr->nextProcess;
        }

        if (ptr != start->nextProcess)
        {
            o.append ("\n");
        }
    }
};

int main()
{
    int n = 0;
    cin >> n;    // Number of Operations
    Scheduler s; // Object to manage processes

    for (int i = 0; i < n; i++)
    {
        int ptype = 0;
        cin >> ptype;
        int arr[4] = {1, 1, 2, 0};
        vector<int> pids;

        for (int j = 0; j < arr[ptype]; j++)
        {
            int temp = 0;
            cin >> temp;
            pids.push_back (temp);
        }

        switch (ptype)
        {
        case 0:
        {
            s.add_Process (pids[0]);
            pids.clear();
            break;
        }

        case 1:
        {
            s.delete_Process (pids[0]);
            pids.clear();
            break;
        }

        case 2:
        {
            s.fork (pids[0], pids[1]);
            pids.clear();
            break;
        }

        case 3:
        {
            s.print_schedule();
            pids.clear();
            break;
        }

        default:
            break;
        }
    }

    cout << o;
    return 0;
}
