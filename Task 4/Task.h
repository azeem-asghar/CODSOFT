#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class task
{
private:
    int id;
    string line;
    string status;

public:
    task();

    void add_task();
    void view_task();
    int search_task();
    void delete_task();
    void set_status();
};
task::task()
{
    id = 1;
    line = " ";
    status = " ";
}
void task::delete_task()
{
    ifstream fin;
    fin.open("task.txt");
    int search_id = search_task();
    if (search_id == -1)
    {
        cout << "Task not found!\n";
        return;
    }
    ofstream fout;
    fout.open("temp.txt", ios::app);
    while (fin >> id >> status)
    {
        getline(fin, line);
        if (search_id == id)
        {
            continue;
        }
        fout << id << " " << status << " " << line << endl;
    }
    fin.close();
    fout.close();
    if (!remove("task.txt") && !rename("temp.txt", "task.txt"))
    {
        cout << "Task deleted!\n";
    }
    else
    {
        cout << "Error deleting task!\n";
    }
}
void task::set_status()
{
    ifstream fin;
    fin.open("task.txt");
    int search_id = search_task();
    if (search_id == -1)
    {
        cout << "Task not found!\n";
        return;
    }
    ofstream fout;
    fout.open("temp.txt", ios::app);
    while (fin >> id >> status)
    {
        getline(fin, line);
        if (search_id == id)
        {
            cout << "Enter Status:";
            cin >> status;
            fout << id << " " << status << " " << line << endl;
            continue;
        }
        fout << id << " " << status << " " << line << endl;
    }
    fin.close();
    fout.close();
    if (!remove("task.txt") && !rename("temp.txt", "task.txt"))
    {
        cout << "Status updated!\n";
    }
    else
    {
        cout << "Error updating  status!\n";
    }
}
void task::view_task()
{

    ifstream fin;
    fin.open("task.txt");
    if (!fin)
    {
        cout << "Error opening file\n";
        return;
    }
    while (fin >> id >> status)
    {
        getline(fin, line);
        cout << "\nID:" << id << endl;
        cout << "Task:" << line << endl;
        cout << "Status:" << status << endl;
    }
    fin.close();
}
int task::search_task()
{
    int search_id;
    cout << "Enter ID of task:";
    cin >> search_id;
    ifstream fin;
    fin.open("task.txt");
    if (!fin)
    {
        cout << "Error opening file\n";
        return -1;
    }
    while (fin >> id)
    {
        if (search_id == id)
        {
            return id;
        }
    }
    fin.close();
    return -1;
}
void task::add_task()
{
    int search_id;
    ofstream fout;
    fout.open("task.txt", ios::app);
    do
    {

        search_id = search_task();

        if (search_id != -1)
        {
            cout << "This ID already exists.\n";
        }
    } while (id == search_id);
    cout << "Enter task:\n";
    cin.clear();
    cin.ignore();
    getline(cin, line);
    cout << "Enter status(completed/pending):";
    cin >> status;

    fout << id << " " << status << " " << line << endl;
    cout << "Task added successfully\n";
    fout.close();
}