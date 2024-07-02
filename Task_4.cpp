#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added: " << description << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[Completed] " : "[Pending] ") << tasks[i].description << endl;
    }
}

void markTaskCompleted(vector<Task>& tasks, int index) {
    if (index < 0 || index >= tasks.size()) {
        cout << "Invalid task index." << endl;
        return;
    }
    tasks[index].completed = true;
    cout << "Task marked as completed: " << tasks[index].description << endl;
}

void removeTask(vector<Task>& tasks, int index) {
    if (index < 0 || index >= tasks.size()) {
        cout << "Invalid task index." << endl;
        return;
    }
    cout << "Task removed: " << tasks[index].description << endl;
    tasks.erase(tasks.begin() + index);
}

int main() {
    vector<Task> tasks;
    int choice;
    string description;
    int index;

    while (true) {
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(tasks, description);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                markTaskCompleted(tasks, index - 1);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> index;
                removeTask(tasks, index - 1);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
