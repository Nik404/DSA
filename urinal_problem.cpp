#include <iostream>
using namespace std;

template <typename T>
class Queue{
    T* arr;
    int currSize, maxSize;
    int start, end;
public:
    Queue(int maxSize){
        this->maxSize = maxSize;
        start = -1;
        end = -1;
        currSize = 0;
        arr = new T[maxSize];
    }
    void push(T x){
        if(currSize == maxSize){
            exit(1);
        }
        if(end == -1){
            start = 0;
            end = 0;
        }
        else{
            end = (end + 1) % maxSize;
        }
        arr[end] = x;
        currSize++;
    }
    
    T pop(){
        if(currSize == 0){
            exit(1);
        }
        T popped = arr[start];
        if(currSize == 1){
            start = -1;
            end = -1;
        }
        else{
            start = (start+1)%maxSize;
        }
        currSize--;
        return popped;
    }
    
    int size(){
        return currSize;
    }
};

struct Pair{
    int left;
    int right;
    int level;
};


void print(bool vis[10]){
    for(int x = 0; x < 10; x++){
        if(!vis[x]){
            std::cout << "_";
        }
        else{
            cout << "X";
        }
    }
    cout << "\n";
}

void solve(int* stalls, bool vis[], int level){
    Queue<Pair> q(level);
    q.push({0,level-1,level});
    
    while(q.size() > 0){
        Pair curr = q.pop();
        int l = curr.left;
        int r = curr.right;
        int e = curr.level;
        if(e <= 0){
            break;
        }
        int mid = (l+r)/2;
        vis[mid] = true;
        print(vis);
        --e;
        if(mid+1 <= r){
            q.push({mid+1,r,e});
        }
        if(mid-1 >= l){
            q.push({l,mid-1,e});
        }

    }
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	int* stalls = new int[n];
	bool vis[n];
	for(int i = 0; i < n; i++){
	    vis[i] = false;
	}
	solve(stalls, vis,n);
	
	return 0;
}
