#pragma once
#include <iostream>
template<typename T>
class Stack{
public:    
    Stack();
    Stack(const Stack<T>& other);
    int getSize();
    void push(T elem);
    T pop();
    bool isEmpty();
    ~Stack(){
        delete[]data;
    }
    void operator<<(const T elem);
    T operator>>(T& a);
    Stack& operator=(const Stack& other);
    bool operator<(Stack& other);
    bool operator>(Stack& other);
    bool operator==(Stack& other);
    T operator[](int i);
    T lastElement();
private:
    unsigned int capacity;
    unsigned int size;
    T* data = new T[capacity];
};

template<typename T>
Stack<T>::Stack() : size(0), capacity(15){};

template<typename T>
Stack<T>::Stack(const Stack<T>& other) {
    this->capacity = other.capacity;
    this->size = other.size;
    T* tmp = data;
    data = new T[capacity];
    delete[]tmp;
    for (int i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}


template<typename T>
int Stack<T>::getSize(){
    return this->size;
}

template<typename T>
void Stack<T>::push(T elem) {
    if(size == capacity){
        T* tmp = data;
        capacity += 10;
        data = new T[capacity];
        for(int i = 0; i < size; i++){
            data[i] = tmp[i];
        }
        delete[]tmp;
    }
    data[size] = elem;
    size++;
}

template<typename T>
T Stack<T>::pop(){
    if(size == 0){
        std::cerr << "there are no elements in the stack\n";
        throw;
    }
    size--;
    return data[size];
}

template<typename T>
bool Stack<T>::isEmpty() {
    if (!size) {
        return true;
    }
    return false;
}

template<typename T>
void Stack<T>::operator<<(const T elem){
    if(size == capacity){
        T* tmp = data;
        capacity += 10;
        data = new T[capacity];
        for(int i = 0; i < size; i++){
            data[i] = tmp[i];
        }
        delete[]tmp;
    }
    data[size] = elem;
    size++;
}

template<typename T>
T Stack<T>::operator>>(T& a){
    if (size == 0) {
        std::cerr << "there are no elements in the stack\n";
        throw;
    }
    size--;
    a = data[size];
    return a;
}

template<typename T> 
Stack<T>& Stack<T>::operator=(const Stack<T>& other){
    if(&other != this){
        this->capacity = other.capacity;
        this->size = other.size;
        T* tmp = data;
        data = new T[capacity];
        delete[]tmp;
        for (int i = 0; i < this->size; i++) {
            this->data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
bool Stack<T>::operator<(Stack<T>& other){
    if(this->size < other.size){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
bool Stack<T>::operator>(Stack<T>& other){
    if(this->size > other.size){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
bool Stack<T>::operator==(Stack<T>& other){
    if(this->size == other.size){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
T Stack<T>::operator[](int i){
    if (i >= 0 && i < this->size) { 
    T element = this->data[i]; 
    return element;
    }
    else {
        throw;
    }
}

template<typename T>
T Stack<T>::lastElement(){
    if(this->size != 0) {
        T element = this->data[size - 1];
        return element;
    }
    else{
        throw;
    }
 
}
