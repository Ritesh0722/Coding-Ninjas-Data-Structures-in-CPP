#include<bits/stdc++.h>
using namespace std;

class DynamicArray {
    int *data;
    int nextIndex;
    int capacity;
    
    public:
        DynamicArray() {
            data = new int[5];
            nextIndex = 0;
            capacity = 5;
        }

        DynamicArray (DynamicArray const &d) {
            //this -> data = d.data;                // Shallow copy

            // Deep copy
            this -> data = new int[d.capacity];
            for(int i = 0; i < d.nextIndex; i++){
            this -> data[i] = d.data[i];
            }
            this -> nextIndex = d.nextIndex;
            this -> capacity = d.capacity;
        }

        void operator=(DynamicArray const &d) {
            this -> data = new int[d.capacity];
            for(int i = 0; i < d.nextIndex; i++){
            this -> data[i] = d.data[i];
            }
            this -> nextIndex = d.nextIndex;
            this -> capacity = d.capacity;                
        }

        void add(int element) {
            if(nextIndex == capacity) {
                int *newData = new int[2 * capacity];
                for (int i = 0; i < capacity; i++){
                    newData[i] = data[i];
                }
                capacity = 2 * capacity;
                delete [] data;
                data = newData;
                // delete newData;
            }
            data[nextIndex] = element;
            nextIndex++;
        }

        void display() {
            for (int i = 0; i < nextIndex; i++){
                    cout<<data[i]<<" ";
            }
            cout<<endl;
        }

        int get(int i) {
            if(i < nextIndex) {
                return data[i];
            }
            else
                return -1;
        }

        void add(int i, int element) {
            if(i < nextIndex) {
                data[i] = element;
            }
            else if(i == nextIndex) {
                add(element);
            }
            else {
                return;
            }
        }

        ~DynamicArray() {
            delete [] data;
        }
};

int main(){
    DynamicArray d;
    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for(int i = 0; i < 12; i++) {
        d.add(arr[i]);
    }

    d.display();

    DynamicArray d1(d);
    DynamicArray d2;
    d2 = d1;

    d.add(1, 20);

    d.display();
    d1.display();
    d2.display();    
}