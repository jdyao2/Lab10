#include "MinHeapNode.h"
#include <string>
using namespace std;


MinHeapNode::MinHeapNode() {
    data = '$';
    freq = 0;
    left = NULL;
    right = NULL;
}

MinHeapNode::MinHeapNode(unsigned f) {
    data = '$';
    freq = f;
    left = NULL;
    right = NULL;
}

MinHeapNode::MinHeapNode(char d, unsigned f) {
    data = d;
    freq = f;
    left = NULL;
    right = NULL;
}

MinHeapNode::~MinHeapNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}

char MinHeapNode::getData()
{
	return data;
}

unsigned MinHeapNode::getFreq()
{
	return freq;
}

void MinHeapNode::setData( char d)
{
	data = d;
}

void MinHeapNode::setFreq( unsigned f)
{
	freq = f;
}

void MinHeapNode::setLeft( MinHeapNode* l)
{
	left = l;
}

void MinHeapNode::setRight( MinHeapNode* r)
{
	right = r;
}

MinHeapNode* MinHeapNode::getLeft()
{
	return left;
}

MinHeapNode* MinHeapNode::getRight()
{
	return right;
}

string MinHeapNode::getPrefix()
{
	return prefix;
}

void MinHeapNode::setPrefix(string s)
{
	prefix = s;
}
