//#include <iostream>
//#include <cstdlib>  
//#include <ctime>
//
//
//void findPairs(int* arr, int size, int targetDifference) {
//    std::cout << "Pairs with difference " << targetDifference << ": " << std::endl;
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = i + 1; j < size; ++j) {
//            if (std::abs(arr[i] - arr[j]) == targetDifference) {
//                std::cout << "(" << arr[i] << ", " << arr[j] << ")" << std::endl;
//            }
//        }
//    }
//
//}
//
//void printArray(int* arr, int size) {
//    std::cout << "Array: ";
//    for (int i = 0; i < size; ++i) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//}
//
//int main() {
//
//    int size;
//    std::cout << "Enter the number of items: ";
//    std::cin >> size;
//
//    int* dynamicArray = new int[size];
//
//    std::srand(std::time(0));
//    for (int i = 0; i < size; ++i) {
//        dynamicArray[i] = std::rand() % 50 + 1;
//    }
//    printArray(dynamicArray, size);
//
//    int targetDifference;
//    std::cout << "Enter the number to search for pairs: ";
//    std::cin >> targetDifference;
//
//    findPairs(dynamicArray, size, targetDifference);
//
//
//
//    delete[] dynamicArray;
//    return 0;
//}


#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string name;
    std::string description;
};

void addTask(std::vector<Task>& tasks) {
    Task newTask;
    std::cout << "Enter the name of the task: ";
    std::cin >> newTask.name;
    std::cout << "Enter a description of the task: ";
    std::cin >> newTask.description;
    tasks.push_back(newTask);
    std::cout << "The task added" << std::endl;
}
void deleteTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "The task list is empty" << std::endl;
        return;
    }



    int taskIndex;
    std::cout << "Enter the number of the task to delete (from 1 to " << tasks.size() << "): ";
    std::cin >> taskIndex;

    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        std::cout << "The task deleted" << std::endl;
    }
    else {
        std::cout << "Incorrect issue number." << std::endl;
    }
}

void displayTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "The task list is empty." << std::endl;
    }
    else {
        std::cout << "Task List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].name << " - " << tasks[i].description << std::endl;
        }
    }
}



int main() {
    std::vector<Task> taskList;

    while (true) {
        std::cout << "Choose task:" << std::endl;
        std::cout << "1. Enter task" << std::endl;
        std::cout << "2 Delete task" << std::endl;
        std::cout << "3. Display the task list" << std::endl;
        std::cout << "0. Exit " << std::endl;

        int choice;
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addTask(taskList);
            break;
        case 2:
            deleteTask(taskList);
            break;
        case 3:
            displayTasks(taskList);
            break;
        case 0:
            std::cout << "Exit." << std::endl;
            return 0;
        default:
            std::cout << "Incorrect choice, try again." << std::endl;
        }
    }

    return 0;
}
//не работает и я не знаю как исправить ;(