#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void parallelQuickSort(vector<int>& arr, int low, int high, int depth) {
    if (low < high) {
        int pi = partition(arr, low, high);

        if (depth > 0) {
            thread leftThread(parallelQuickSort, ref(arr), low, pi - 1, depth - 1);
            parallelQuickSort(arr, pi + 1, high, depth - 1);
            leftThread.join();
        }
        else {
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
}

vector<int> generateArray(int size) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1000000);

    for (int i = 0; i < size; i++)
        arr[i] = dis(gen);

    return arr;
}

double measureSequential(vector<int> arr) {
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    return chrono::duration<double>(end - start).count();
}

double measureParallel(vector<int> arr, int threads) {
    int depth = 0;

    while ((1 << depth) < threads)
        depth++;

    auto start = chrono::high_resolution_clock::now();
    parallelQuickSort(arr, 0, arr.size() - 1, depth);
    auto end = chrono::high_resolution_clock::now();

    return chrono::duration<double>(end - start).count();
}

int main() {

    vector<int> sizes = { 100, 1000, 10000, 20000, 30000, 40000, 50000 };

    cout << left << setw(15) << "Размер"
        << setw(15) << "БС(сек)"
        << setw(20) << "БС_П 2 потока"
        << setw(20) << "БС_П 4 потока"
        << setw(20) << "БС_П 8 потока"
        << endl;

    cout << string(90, '-') << endl;

    for (int size : sizes) {

        vector<int> baseArray = generateArray(size);

        double t_seq = measureSequential(baseArray);
        double t_par2 = measureParallel(baseArray, 2);
        double t_par4 = measureParallel(baseArray, 4);
        double t_par8 = measureParallel(baseArray, 8);

        cout << left << setw(15) << size
            << setw(15) << fixed << setprecision(6) << t_seq
            << setw(20) << t_par2
            << setw(20) << t_par4
            << setw(20) << t_par8
            << endl;
    }

    return 0;
}