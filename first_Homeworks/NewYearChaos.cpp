#include <iostream>
#include <vector>

bool swapWith_right(std::vector<int>&, size_t, size_t&);
void swapWith_left(std::vector<int>&, size_t, size_t&);

int main() {
    std::vector<int> myVec{2, 5, 1, 3, 6};
    size_t count{0};
    bool check{true};
    for (size_t i{0}; i < myVec.size(); ++i) {
        check = swapWith_right(myVec, i, count);
        if (!check) {
            break;
        }
        swapWith_left(myVec, i, count);
    }

    if (!check) {
        std::cout << count << "\n";
        std::cout << "Too chaotic\n";
    } else {
        std::cout << count << "\n";
    }
    std::cout << "\n";

    return 0;
}

bool swapWith_right(std::vector<int>& vec, size_t start, size_t& count) {
    size_t localCount{0};
    size_t startNext{start + 1};

    while (localCount < 3 && startNext < vec.size()) {
        if (vec[start] > vec[startNext]) {
            std::swap(vec[start], vec[startNext]);
            ++start;
            startNext = (start + 1);
            ++localCount;
        } else {
            break;
        }
    }

    if (localCount >= 3) {
        count += localCount;
        return false;
    }
     count += localCount;
     return true;
}

void swapWith_left(std::vector<int>& vec, size_t start, size_t& count) {
    size_t localCount{0};

    while(start > 0) {
        if (vec[start] < vec[start - 1]) {
            std::swap(vec[start], vec[start - 1]);
            --start;
            ++localCount;
        } else {
            break;
        }
    }
    count += localCount;
}

