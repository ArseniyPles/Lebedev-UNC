#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {

    // 1 номер
    int A[10] = { -5, -1, -4, -7, 1, 9, -5, -2, -9, -1 };
    std::vector<int> B;

    for (int i = 0; i < 10; ++i) {
        if (A[i] > 0) {
            B.push_back(A[i]);
        }
    }
    std::cout << "Massiv B: ";
    for (int num : B) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 2 номер
    std::set<int> setA = { 11, 14, 21, -19, -12 };
    std::set<int> setB = { 77, 21, 12, 6, -19 };
    std::set<int> intersection;

    int sum = 0;

    std::set_intersection(setA.begin(), setA.end(),
        setB.begin(), setB.end(),
        std::inserter(intersection, intersection.begin()));

    for (int num : intersection) {
        sum += num;
    }

    std::cout << "Peresechenie: ";
    for (int num : intersection) {
        std::cout << num << " ";
    }

    std::cout << "\nSumma elementov peresecheniya: " << sum << std::endl;
    return 0;
}