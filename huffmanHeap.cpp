// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>

#include "huffmanHeap.h"

using namespace std;

// default constructor
huffmanHeap::huffmanHeap() {
    heap_size = 0;
    huffmanVector.push_back(huffmanVector[0]);
}

huffmanHeap::huffmanHeap(int size) {
    heap_size = size;
    huffmanVector.push_back(huffmanVector[0]);
}

// builds a heap from an unsorted vector
 huffmanHeap::huffmanHeap(std::vector<MinHeapNode*> vec) : heap_size(vec.size()) {
     huffmanVector = vec;
     huffmanVector.push_back(huffmanVector[0]);
     //huffmanHeap[0] = NULL;
     for ( int i = heap_size/2; i > 0; i-- )
         percolateDown(i);
 }

// the destructor doesn't need to do much
huffmanHeap::~huffmanHeap() {
}

void huffmanHeap::insert(MinHeapNode* n) {
    // a vector push_back will resize as necessary
    huffmanVector.push_back(n);
    // move it up into the right position
    percolateUp(++heap_size);
}

vector<MinHeapNode*> huffmanHeap::getHuffmanVector()
{
    return huffmanVector;
}

void huffmanHeap::percolateUp(int hole) {
    // get the value just inserted
    MinHeapNode* x = huffmanVector[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->getFreq() < huffmanVector[hole/2]->getFreq() ); hole /= 2 )
        huffmanVector[hole] = huffmanVector[hole/2]; // move the parent down
    // correct position found!  insert at that spot
    huffmanVector[hole] = x;
}

MinHeapNode* huffmanHeap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    MinHeapNode* ret = huffmanVector[1];
    // move the last inserted position into the root
    huffmanVector[1] = huffmanVector[heap_size--];
    // make sure the vector knows that there is one less element
    huffmanVector.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void huffmanHeap::percolateDown(int hole) {
    // get the value to percolate down
    MinHeapNode* x = huffmanVector[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && (huffmanVector[child+1]->getFreq() < huffmanVector[child]->getFreq() ))
            child++;
        // if the child is greater than the node...
        if ( x->getFreq() > huffmanVector[child]->getFreq() ) {
            huffmanVector[hole] = huffmanVector[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    huffmanVector[hole] = x;
}

MinHeapNode* huffmanHeap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return huffmanVector[1];
}

unsigned int huffmanHeap::size() {
    return heap_size;
}

void huffmanHeap::makeEmpty() {
    heap_size = 0;
    huffmanVector.resize(1);
}

bool huffmanHeap::isEmpty() {
    return heap_size == 0;
}

void huffmanHeap::print() {
    // cout << "(" << heap[0] << ") ";
    // for ( int i = 1; i <= heap_size; i++ ) {
    //     cout << heap[i] << " ";
    //     // next line from http://tinyurl.com/mf9tbgm
    //     bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
    //     if ( isPow2 )
    //         cout << endl << "\t";
    // }
    // cout << endl;
}
