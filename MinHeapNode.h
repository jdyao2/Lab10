#ifndef MINHEAPNODE_H
#define MINHEAPNODE_H

#include <string>
using namespace std;

class MinHeapNode {
  
  public:

    MinHeapNode();
    MinHeapNode(unsigned f);
    MinHeapNode(char d, unsigned f);
    ~MinHeapNode();
    char getData();
    unsigned getFreq();
    MinHeapNode* getLeft();
    MinHeapNode* getRight();
    string getPrefix();
    void setData( char d);
    void setFreq( unsigned f);
    void setLeft( MinHeapNode* l);
    void setRight( MinHeapNode* r);
    void setPrefix( string s);

  private:
    char data;
    unsigned freq; 
    MinHeapNode* left;
    MinHeapNode* right;
    std::string prefix;

    friend class huffmanHeap;
};

#endif
