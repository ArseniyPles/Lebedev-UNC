#include <iostream>
#include <chrono>
#include <vector>
#include <cassert>

using namespace std;

// ��������� ��� ���� ���������� ������
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// ����� ��� ���������� ������
class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    // ������� ��� ���������� �������� � ����� ������
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // ������� ��� ���������� ������� ������
    int size() const {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

private:
    Node* head;
};

// ������� ��� ��������� ������� ���������� ���������� ���������
void measureTime() {
    vector<int> sizes = { 10, 100, 1000, 10000, 100000, 1000000, 10000000 }; // ������� ������ ��������
    for (int size : sizes) {
        LinkedList list;

        // �������� ����� ���������� ���������
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < size; ++i) {
            list.append(i);
        }
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        cout << "Size: " << size << " Time taken: " << duration.count() << " seconds" << endl;
    }
}

int main() {
    // ������������ ���������� ���������
    measureTime();

    return 0;
}
