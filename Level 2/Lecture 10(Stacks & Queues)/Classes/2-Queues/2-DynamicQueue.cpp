#include<bits/stdc++.h>
using namespace std;

template<typename T>

class QueueUsingArray {
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
    T *data;

    public:
    QueueUsingArray(int totalSize) {
        data = new T[totalSize];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = totalSize;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    T front() {
        if(isEmpty()) {
            cout<<"Queue is empty!"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

    void enqueue(T element) {
        if(size == capacity) {
            T *newData = new T[2 * capacity];
            int j = 0;
            for(int i = firstIndex; i < capacity; i++) {
                newData[j] = data[i];
                j++;
            }
            for(int i = 0; i < firstIndex; i++) {
                newData[j] = data[i];
                j++;
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
            // cout<<"Queue is full!"<<endl;
            // return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1) {
            firstIndex = 0;
        }
        size++;
    }

    T dequeue() {
        if(isEmpty()) {
            cout<<"Queue is empty!"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex++;
        size--;
        if(size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};

int main() {
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;

    cout<<q.getSize()<<endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.getSize()<<endl;

    q.enqueue(70);
    
    cout<<q.getSize()<<endl;

    cout<<q.isEmpty()<<endl;
}