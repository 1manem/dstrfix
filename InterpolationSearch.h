template <typename T>
T* InterpolationSearch(T* head, string target, int type) {
    T* start = head;
    T* end = nullptr;

    switch (type) {
    case 1:
    case 5:
    case 6:
        while (start != end) {
            T* mid = InterpolationMidPoint(start, end, stoi(target), type);
            if (mid->rank == stoi(target)) {
                return mid;
            }
            else if (mid->rank > stoi(target)) {
                end = mid;
            }
            else {
                start = mid->nextAdd;
            }
        }
        break;

    case 2:
    case 3:
    case 4:
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

    default:
        return nullptr;
    }

    return nullptr;
}

template <typename T>
T* InterpolationMidPoint(T* start, T* end, const string& target, int type) {
    double valueRange = 0.0;
    double fraction = 0.0;

    switch (type) {
        case 1:
        case 5:
        case 6:
            valueRange = static_cast<double>(end->rank - start->rank);
            fraction = (stod(target) - start->rank) / valueRange;
            break;

        default:
            return nullptr;
    }

    T* current = start;
    while (current != end) {
        double currentFraction = 0.0;
        switch (type) {
            case 1:
            case 5:
            case 6:
                currentFraction = static_cast<double>(current->rank - start->rank) / valueRange;
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