#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<string> tasks;

// Load tasks from file on startup
void loadTasks() {
    ifstream file("tasks.txt");
    string task;
    while (getline(file, task)) {
        tasks.push_back(task);
    }
    file.close();
}

// Save tasks to file
void saveTasks() {
    ofstream file("tasks.txt");
    for (const string &t : tasks) {
        file << t << endl;
    }
    file.close();
}

void addTask() {
    string task;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully!\n";
}

void showTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n---- Your Tasks ----\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask() {
    int index;
    showTasks();

    if (tasks.empty()) return;

    cout << "Enter task number to delete: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks.erase(tasks.begin() + (index - 1));
    cout << "Task deleted!\n";
}

int main() {
    loadTasks();

    int choice;
    while (true) {
        cout << "\n===== Task Manager =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Save Tasks\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: showTasks(); break;
            case 3: deleteTask(); break;
            case 4: saveTasks(); cout << "Tasks saved!\n"; break;
            case 5: saveTasks(); cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}