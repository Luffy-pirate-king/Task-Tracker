#include <iostream>
#include <map>
using namespace std;

bool quit = false;
string task, id;
string choice;
int main()
{
    map<string, string> tasks;
    cout << "------TASK MANAGER------\n";
    while(!quit){
        cout << "Choose your options:\n";
        cout << "1. Add a new task\n";
        cout << "2. Delete a task\n";
        cout << "3. View the tasks\n";
        cout << "4. Quit the program\n";
        cout << "Your option: ";
        getline(cin, choice);
        if(choice == "1"){
            cout << "Enter your task: ";
            getline(cin, task);
            cout << endl << "Enter the Task's ID: ";
            getline(cin, id);
            tasks.insert(make_pair(id, task));
            cout << endl << "Task added successfully!\n";
            cout << "------------------------\n";
        } else if(choice == "2"){
            cout << "Enter the Task's ID: ";
            getline(cin, id);
            try{
                if(tasks.erase(id)){
                    cout << "Task with ID " << id << " is deleted successfully!\n";
                    cout << "------------------------\n";
                } else {
                    throw id;
                }
            } catch(string id){
                cout << "Task with ID " << id << " is not existed!\n";
                cout << "------------------------\n";
            }
        } else if(choice == "3"){
            cout << "Here is the list of tasks:\n";
            for(auto &p : tasks){
                cout << "ID " << p.first << ": " << p.second << endl;
            }
            cout << "------------------------\n";
        } else if(choice == "4"){
            quit = true;
        } else {
            cout << "Invalid option! Please try again\n";
            cout << "------------------------\n";
        }
    }
    cout << "Thanks for using my service!";
    return 0;
}