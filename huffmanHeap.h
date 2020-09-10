// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

//#ifndef HUFFMANHEAP_H
//#define HUFFMANHEAP_H

#include <vector>

#include "MinHeapNode.h"

using namespace std;


class huffmanHeap {
public:
    huffmanHeap();
    huffmanHeap(int size);
    huffmanHeap(std::vector<MinHeapNode*> vec);
    ~huffmanHeap();

    void insert(MinHeapNode* mpn);
    MinHeapNode* findMin();
    MinHeapNode*  deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    vector<MinHeapNode*> getHuffmanVector();

private:
    std::vector< MinHeapNode* > huffmanVector;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

//#endif
