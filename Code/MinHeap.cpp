//
// Created by Jaime on 30/12/2022.
//

#include "MinHeap.h"

MinHeap::MinHeap() {}

MinHeap::MinHeap(int maxSize) { this->maxSize = maxSize;}

int MinHeap::getSize() {return currentSize;}

void MinHeap::swap(int pos1, int pos2) {
    heapElement tmp = heapElements[pos1];
    heapElements[pos1] = heapElements[pos2];
    heapElements[pos2] = tmp;
    pos[heapElements[pos1].key] = pos1;
    pos[heapElements[pos2].key] = pos2;

}

void MinHeap::insert(const int &key, const int &value) {
    heapElements.push_back(heapElement{key, value});
    currentSize++;
    pos[currentSize] = key; //criamos a nossa associaçao entre a posicao no nosso array heapElements e a key no array dos nodes do grafo
    upHeap(currentSize);
}

void MinHeap::decreaseKey(const int &key, const int &value) {
    heapElements[pos[key]].value = value;
    upHeap(pos[key]);
}

void MinHeap::upHeap(int pos) {
    while(pos > 0 && heapElements[pos].value < heapElements[PARENT(pos)].value){
        swap(pos, PARENT(pos));
        pos = PARENT(pos);
    }
}

void MinHeap::downHeap(int pos) {
    while(LEFT(pos) <= currentSize){
        int j = LEFT(pos);
        if(RIGHT(pos) <= currentSize && heapElements[RIGHT(pos)].value < heapElements[j].value)
            j = RIGHT(pos);
        if(heapElements[pos].value < heapElements[j].value) break;
        swap(pos, j);
        pos = j;
    }
}

int MinHeap::removeMin() {
    if(currentSize != 0){
        int min = heapElements[0].key;
        pos.erase(min);
        currentSize--;
        downHeap(0);
    }
}
