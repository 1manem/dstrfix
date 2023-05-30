#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool interpolationSearch(const string& filename, const string& searchItem)
{
    ifstream file(filename);
    if (!file) {
        cout << "Failed to open file: " << filename << endl;
        return false;
    }

    string line;
    int left = 0;
    int right = 0;
    bool found = false;
    bool firstFound = true; // Variable to track the first occurrence

    // Determine the range of the file
    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    if (fileSize > 0) {
        right = (fileSize - 1) / sizeof(char);
    } else {
        file.close();
        return false;
    }

    while (left <= right) {
        int mid = left + ((right - left) * (searchItem.length())) / fileSize;

        file.seekg(mid, ios::beg);

        // Skip until the next newline character
        char c;
        while (file.get(c) && c != '\n') {
        }

        getline(file, line);
        stringstream ss(line);
        string value;

        getline(ss, value, ',');

        if (value == searchItem) {
            if (firstFound) {
                cout << "Item found in the CSV file:" << endl;
                firstFound = false;
            }
            cout << line << endl;
            found = true;
        } else if (value < searchItem) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    file.close();
    return found;
}