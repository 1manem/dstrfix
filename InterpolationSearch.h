#include <iostream>
using namespace std;

template <typename T>
T* IntSearch(T* head, string target, int type) {
    T* start = head;
    T* end = tail;

    switch (type) {
    case 1:
        cout << "masuk";
        cout << start << endl << end << endl; target << endl << type << endl;
        while (start != end) {
            T* mid = InterpolationMidPoint(start, end, target, type);
            cout << start << end << target << type;
            if (mid->rank == stoi(target)) {
                return mid;
                cout << mid;
            }
            else if (mid->rank > stoi(target)) {
                end = mid;
            }
            else {
                start = mid->nextAdd;
            }
        }
        cout << "error";
        break;
    case 5:
        while (start != end) {
            T* mid = InterpolationMidPoint(start, end, target, type);
            if (mid->ArRank == stoi(target)) {
                return mid;
            }
            else if (mid->ArRank > stoi(target)) {
                end = mid;
            }
            else {
                start = mid->nextAdd;
            }
        }
        break;
    case 6:
        while (start != end) {
            T* mid = InterpolationMidPoint(start, end, target, type);
            if (mid->ErRank == stoi(target)) {
                return mid;
            }
            else if (mid->ErRank > stoi(target)) {
                end = mid;
            }
            else {
                start = mid->nextAdd;
            }
        }
        break;

    case 2:
        while (start != end) {
            T* mid = InterpolationMidPoint(start, end, target, type);
            if (mid->institution == target) {
                return mid;
            }
            else if (mid->institution > target) {
                end = mid;
            }
            else {
                start = mid->nextAdd;
            }
        }
        break;
    case 3:
        while (start != end) {
            T* mid = InterpolationMidPoint(start, end, target, type);
            if (mid->LocationCode == target) {
                return mid;
            }
            else if (mid->LocationCode > target) {
                end = mid;
            }
            else {
                start = mid->nextAdd;
            }
        }
        break;
    case 4:
        while (start != end) {
            T* mid = InterpolationMidPoint(start, end, target, type);
            if (mid->Location == target) {
                return mid;
            }
            else if (mid->Location > target) {
                end = mid;
            }
            else {
                start = mid->nextAdd;
            }
        }
        break;

    default:
        return nullptr;
    }

    return nullptr;
}

template <typename T>
T* InterpolationMidPoint(T* start, T* end, string target, int type) {
    double valueRange = 0.0;
    double fraction = 0.0;

    switch (type) {
    case 1:
        valueRange = static_cast<double>(end->rank - start->rank);
        fraction = (stod(target) - start->rank) / valueRange;
        break;
    case 5:
        valueRange = static_cast<double>(end->ArRank - start->ArRank);
        fraction = (stod(target) - start->ArRank) / valueRange;
        break;
    case 6:
        valueRange = static_cast<double>(end->ErRank - start->ErRank);
        fraction = (stod(target) - start->ErRank) / valueRange;
        break;

    default:
        return nullptr;
    }

    T* current = start;
    while (current != end) {
        double currentFraction = 0.0;
        switch (type) {
        case 1:
            currentFraction = static_cast<double>(current->rank - start->rank) / valueRange;
            break;
        case 5:
            currentFraction = static_cast<double>(current->ArRank - start->ArRank) / valueRange;
            break;
        case 6:
            currentFraction = static_cast<double>(current->ErRank - start->ErRank) / valueRange;
            break;

        default:
            return nullptr;
        }

        if (currentFraction >= fraction) {
            return current;
        }

        current = current->nextAdd;
    }

    return current;
}