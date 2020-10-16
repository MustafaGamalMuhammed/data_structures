#include<iostream>

using namespace std;

template <typename T>
class Array {
    private:
        T *arr;
        int len = 0;
        int cap;

    public:
        Array() {
            Array(16);
        }

        Array(int capacity) {
            cap = capacity;
            arr = new T[cap];
        }

        int size() {
            return len;
        }

        bool isEmpty() {
            return len == 0;
        }

        T get(int index) {
            return arr[index];
        }

        void set(int index, T value) {
            if(index >= cap) {
                resize();
            }

            arr[index] = value;
            len++;
        }

        void clear() {
            for(int i = 0; i < cap; i++) {
                arr[i] = NULL;
            }
        }

        void resize() {
            T * new_arr = new T[cap * 2];
            
            for(int i = 0; i < cap; i++) {
                new_arr[i] = arr[i];
            }
            
            arr = new_arr; 
        }
};

int main() {
    Array<int> arr = Array<int>();
    arr.set(0, 0);
    arr.set(1, 1);

    cout << "arr.size() = " << arr.size() << endl;
    cout << "arr[0]     = " << arr.get(0) << endl;
    cout << "arr[1]     = " << arr.get(1) << endl;

    return 0;
}