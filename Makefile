# Sarah Yao
# smy5pc

CXX=clang++ $(CXXFLAGS) $(CXXLIBS)
CXXFLAGS=-Wall -O2 # Enable all warnings
CXXLIBS=-static
DEBUG=-g

a.out: MinHeapNode.o huffmanHeap.o fileio.o 
	      $(CXX) $(DEBUG) MinHeapNode.o huffmanHeap.o fileio.o
	@echo "Huffman Coding is ready!"

fileio.o: fileio.cpp huffmanHeap.h MinHeapNode.h

huffmanHeap.o: huffmanHeap.cpp huffmanHeap.h MinHeapNode.h

MinHeapNode.o: MinHeapNode.cpp MinHeapNode.h

.PHONY: clean
clean:
	-rm -f *.o a.out
