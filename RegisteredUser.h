// #include <iostream>
// #include <fstream>
// #include <sstream>
// using namespace std;


// class MainMenu {
// public:
//     void displayMenu() {
//         int choice;
//         do {
//             std::cout << "=== Main Menu ===" << std::endl;
//             std::cout << "1. Display University Academic Ranking" << std::endl;
//             std::cout << "2. Display University Faculty and Student Ratio Score" << std::endl;
//             std::cout << "3. Display University Employee Reputation Score" << std::endl;
//             std::cout << "4. Search University" << std::endl;
//             std::cout << "5. Logout" << std::endl;
//             std::cout << "6. Exit" << std::endl;
//             std::cout << "Enter your choice: ";
//             std::cin >> choice;
//             User user;
//             switch (choice) {
//             case 1:
//                 SortUniversities();
//                 break;
//             case 2:
//                 SortUniversities();
//                 break;
//             case 3:
//                 SortUniversities();
//                 break;
//             case 4:
//                 SearchUniversities();
//                 break;
//             case 5:
//                 user.UserMainMenu();
//                 break;
//             case 7:
//                 std::cout << "Exiting..." << std::endl;
//                 break;
//             default:
//                 std::cout << "Invalid choice. Please try again." << std::endl;
//             }
//         } while (choice != 5);
//     }

// private:
//     void static SortUniversities() {

//         int sort;
//         std::cout << "\n Hello, welcome to the sort menu!" << std::endl;
//         std::cout << "\n Please choose which sort algorithm you wanted to use!" << std::endl;
//         std::cout << "\n 1. Merge Sort Algorithm" << std::endl;
//         std::cout << "\n 2. Quick Sort Algorithm" << std::endl;
//         std::cin >> sort;

//         if (sort == 1) {
//             void MergeSort();
//         }

//         else if (sort == 2) {
//             void QuickSort();
//         }

//         else {
//             std::cout << "\n The number you inserted is invalid!" << std::endl;
//             std::cout << "\n please re - enter your choice!" << std::endl;

//             void SortUniversities();
//         }


//     }

//     void static MergeSort() {



//     }

//     void static QuickSort() {



//     }

//     void static SearchUniversities() {

//         int search;
//         std::cout << "\n Hello, welcome to the search menu!" << std::endl;
//         std::cout << "\n Please choose which search algorithm you wanted to use!" << std::endl;
//         std::cout << "\n 1. Binary Search Algorithm" << std::endl;
//         std::cout << "\n 2. Interpolation Search Algorithm" << std::endl;
//         std::cin >> search;

//         if (search == 1) {
//             void BinarySearch();
//         }

//         else if (search == 2) {
//             void InterpolationSearch();
//         }

//         else {
//             std::cout << "\n The number you inserted is invalid!" << std::endl;
//             std::cout << "\n please re - enter your choice!" << std::endl;
//             void SearchUniversities();
//         }

//     }

//     void static BinarySearch() {
//         int Choice;
//         std::cout << "\n " << std::endl;


//     }

//     void static InterpolationSearch() {
//         int choice;
//         std::cout << "\n" << std::endl;

//     }

// };