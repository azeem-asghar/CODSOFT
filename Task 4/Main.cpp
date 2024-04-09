#include <iostream>
#include "Task.h"

using namespace std;

int main()
{
    task t;
    while (true)
    {
        cout << "\n1.ADD TASKS\n2.VIEW TASKS\n3.DELETE TASKS\n4.CHANGE STATUS\n5.EXIT\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            t.add_task();
            break;
        case 2:
            t.view_task();
            break;
        case 3:
            t.delete_task();
            break;
        case 4:
            t.set_status();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}