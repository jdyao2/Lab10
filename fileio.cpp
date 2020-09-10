// This program shows how C++-based file I/O works.
// It will print a file to the screen two times.

// included so we can use cout
// included so we can use cout
#include <iostream>
// file I/O
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib>
#include <unordered_map>

#include "MinHeapNode.h"
#include "huffmanHeap.h"
using namespace std;

static void iterateall(MinHeapNode* foo);

unordered_map<char, string> m_rult;

// we want to use parameters
int main(int argc, char** argv) {

    unordered_map<char, unsigned> m_freq;
    huffmanHeap* hHeap = nullptr;
    //MinHeapNode* newNode;    
    MinHeapNode* leftNode = nullptr;
    MinHeapNode* rightNode = nullptr;
    vector<MinHeapNode*> v_temp;

    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    while (file.get(g)) {
        if(g!= '\n')
        {
            m_freq[g]++;
//            cout << g;
        }
    }

    //cout << "map size:: " << m_freq.size() << endl;

    unordered_map<char, unsigned>::iterator it = m_freq.begin();
    

    while( it != m_freq.end())
    {
        char x = it->first;
        unsigned y = it->second;

        v_temp.push_back(new MinHeapNode(x, y));
        

        it++;
    }

    // a nice pretty separator
    //cout << "----------------------------------------" << endl;

    hHeap = new huffmanHeap(v_temp);

    vector<MinHeapNode*> vect = hHeap->getHuffmanVector();

    //cout << "hHeap size : " << hHeap->size() << endl;


    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    while( hHeap->size() >=2)
    {
        //leftNode = hHeap->findMin();
        leftNode = hHeap->deleteMin();
        //leftNode->prefix  =  "0" +  leftNode->prefix;
 
        //rightNode =  hHeap->findMin();
        rightNode = hHeap->deleteMin();
        //rightNode->prefix  =  "1" +  rightNode->prefix;

        MinHeapNode* newNode = new MinHeapNode('$', leftNode->getFreq() + rightNode->getFreq());
        newNode->setLeft(leftNode);
        newNode->setRight(rightNode);


        hHeap->insert(newNode);

    }


    v_temp = hHeap->getHuffmanVector();

    MinHeapNode* nNode = v_temp[1];


    iterateall(nNode);

    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    // Read the file again, and print to the screen
    while (file.get(g)) {

        unordered_map<char, string>::iterator i = m_rult.begin();


        while( i != m_rult.end())
        {
            if(g == i->first)
                cout << i->second << " ";

            i++;

        }
       

    }

    cout << endl;

    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    // close the file
    file.close();
}



static void iterateall(MinHeapNode* foo) 
{


    if(foo->getLeft() == NULL)
    {
     
     m_rult.insert({foo->getData(), foo->getPrefix()});

     cout << foo->getData() << "  " << foo->getPrefix() << endl;

    }
    else
    {
       foo->getLeft()->setPrefix(foo->getPrefix() + "0");
       foo->getRight()->setPrefix(foo->getPrefix() + "1");
       iterateall(foo->getLeft());
       iterateall(foo->getRight());
    }
}
