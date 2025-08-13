#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to display all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\n--- TO-DO LIST ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    cin.ignore();
    Task newTask;
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully.\n";
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index > 0 && index <= (int)tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;

    if (index > 0 && index <= (int)tasks.size()) {
        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n--- TO-DO LIST MENU ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
