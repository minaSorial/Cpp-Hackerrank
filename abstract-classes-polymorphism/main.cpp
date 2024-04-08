#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};




class LRUCache :public Cache {

public:

    LRUCache(int cap) {
        cp = cap;
    }
    virtual ~LRUCache() {}

    void set(int k, int v) override {
        if (mp.find(k) != mp.end()) {
            mp[k]->value = v;
        }
        else {
            Node* item = new Node(k, v);
            if (head == nullptr) {
                head = item;
                tail = item;
                cp--;
            }
            else {
                tail->next = item;
                tail = item;
            }
            mp[k] = tail;
            cp--;
            if (cp == 0) {
                mp.erase(head->key);
                head = head->next;
                cp++;
                
            }


        }


    }
    int get(int key) override {

        if (mp.find(key) != mp.end()) {
            return mp.at(key)->value;
        }
        else {
            return -1;
        }

    }

};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
