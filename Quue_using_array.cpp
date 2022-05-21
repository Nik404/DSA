#include <iostream>
using namespace std;

class queue{
public:
  int *arr;
  int start, end, currentSize, maxSize;

  queue(int maxSize){
    this->maxSize = maxSize;
    start = -1;
    end = -1;
    currentSize = 0;
    arr = new int[maxSize];
  }

  void push(int x){
    if(currentSize == maxSize){
      cout << "Queue is full" << endl;
      exit(1);
    }
    if(end == -1){
      start = 0;
      end = 0;
    }
    else{
      end = (end+1)%maxSize;
    }
    arr[end] = x;
    currentSize++;
  }

  int pop(){
    if(start == -1){
      exit(1);
    }
    int popped = arr[start];
    if(currentSize == 1){
      start = -1;
      end = -1;
    }
    else{
      start = (start+1)%maxSize;
    }
    currentSize--;
    return popped;
  }

  int front(){
    if(start == -1){
      exit(1);
    }
    return arr[start];
  }

  int size(){
    return currentSize;
  }

};

int main() {
    

}
