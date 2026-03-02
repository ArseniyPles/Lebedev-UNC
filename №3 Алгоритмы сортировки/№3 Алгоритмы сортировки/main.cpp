#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <cassert>

using namespace std;
using namespace std::chrono;

void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    quickSort(arr, low, i);
    quickSort(arr, i + 2, high);
}

int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {};

    for (int i = 0; i < n; ++i)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    arr = output;
}

void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

void gnomeSort(vector<int>& arr) {
    int index = 0;
    int n = arr.size();
    while (index < n) {
        if (index == 0)
            ++index;
        if (arr[index] >= arr[index - 1])
            ++index;
        else {
            swap(arr[index], arr[index - 1]);
            --index;
        }
    }
}

vector<int> generateRandom(int n, int seed = 0) {
    vector<int> arr(n);
    mt19937 rng(seed);
    uniform_int_distribution<int> dist(0, 100000);
    for (int i = 0; i < n; ++i)
        arr[i] = dist(rng);
    return arr;
}

void runUnitTests() {
    vector<int> original = { 5, 3, 1, 4, 2 };
    vector<int> expected = { 1, 2, 3, 4, 5 };

    vector<int> a = original;
    quickSort(a, 0, a.size() - 1);
    assert(a == expected);

    vector<int> b = original;
    radixSort(b);
    assert(b == expected);

    vector<int> c = original;
    gnomeSort(c);
    assert(c == expected);

    cout << "unit-test yspeshno\n";
}

void measureTime(int n) {
    auto test = [&](const string& name, auto sortFunc) {
        vector<int> arr = generateRandom(n, 42);
        auto start = high_resolution_clock::now();
        sortFunc(arr);
        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        cout << name << " (" << n << " elementov): " << diff.count() << " sec\n";
        };

    test("QuickSort", [](auto& a) { quickSort(a, 0, a.size() - 1); });
    test("RadixSort", radixSort);
    test("GnomeSort", gnomeSort);
}

int main() {
    runUnitTests();

    vector<int> sizes = { 1000, 5000, 10000, 100000 };
    for (int n : sizes) {
        measureTime(n);
        cout << "--------------------------\n";
    }

    return 0;
}