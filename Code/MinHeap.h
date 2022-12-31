//
// Created by Jaime on 30/12/2022.
//

#ifndef UNTITLED_MINHEAP_H
#define UNTITLED_MINHEAP_H
#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)
#define PARENT(i) ((i)/2)
#include <vector>
#include <unordered_map>
#include <iostream>

class MinHeap {

    struct heapElement{
        int key; // index of the node in the graph
        int value; // distance to source norde
        //int prev;  // index of the previous node in the graph
    };

    std::vector<heapElement> heapElements;
    int currentSize;
    int maxSize;
    void swap(int pos1, int pos2);

    public:
        MinHeap();
        MinHeap(int maxSize);
        int getSize();
        int removeMin();
        void insert(const int &key, const int &value);
        void decreaseKey(const int &key, const int &value);
        void upHeap(int pos);
        void downHeap(int pos);
        std::unordered_map<int, int> pos;

};


#endif //UNTITLED_MINHEAP_H
