//Write a program to implement Huffman Encoding using a greedy strategy.


#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode{
	char data;//This member represents the character associated with the node
	int freq;//This member represents the frequency of the character.
	MinHeapNode* left, *right;// These members are pointers to the left and right child nodes of the current node
	MinHeapNode(char data, int freq){
		left=right=nullptr; //This is the constructor for the MinHeapNode struct. It initializes the data and freq members with the                     
		this->data = data;  //provided arguments and sets the left and right pointers to nullptr.
		this->freq = freq;
	}
};


void printCodes(struct MinHeapNode* root, string str){
	if(root == nullptr){
		return;
	}
	//The character '$' is used as a special marker in the implementation to indicate internal nodes. If the data is not '$', it means the 
	//current node is a leaf node representing a character. In this case, it prints the character along with the binary code generated so far
	if(root->data != '$'){
		cout << root->data << ": " << str << endl;
	}
	//printCodes(root->left, str + "0"): This call is made with the left child of the current node, appending "0" to the existing binary code.
	//printCodes(root->right, str + "1"): This call is made with the right child of the current node, appending "1" to the existing binary code.
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

struct compare{
	bool operator()(MinHeapNode* a, MinHeapNode* b){
		return (a->freq > b->freq);
	}
};

void HuffmanCode(char data[], int freq[], int size){


	struct 	MinHeapNode *left, *right, *temp;
	
	//MinHeapNode*: This specifies the type of elements stored in the priority queue. Here, it is a pointer to a MinHeapNode object.
	//vector<MinHeapNode*>: This specifies the underlying container used by the priority queue to store its elements. In this case, it is a vector that holds 
	//pointers to MinHeapNode objects.compare: This is the comparison function object that determines the ordering of elements in the priority queue. In this context, 
	//the compare struct, which overloads the () operator to compare MinHeapNode pointers based on their frequencies, is used as the comparison function.

	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	
	for(int i = 0; i < size; i++){
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	}
	
	while(minHeap.size() != 1){ //If there is only one element left, it means that the Huffman tree has been fully constructed.
		//The node with the lowest frequency is assigned to the variable left, and then it is removed from the queue using minHeap.pop().
		left = minHeap.top();
		minHeap.pop();
		//The next node with the lowest frequency is assigned to the variable right, and it is also removed from the queue using minHeap.pop().
		right = minHeap.top();
		minHeap.pop();
		//temp is created with the character '$' (a special marker used to indicate internal nodes) and the sum of the frequencies of the left and right nodes. 
		//This temp node becomes the parent node of the left and right nodes in the Huffman tree.
		temp = new MinHeapNode('$', left->freq + right->freq);

		//The left and right nodes are assigned as the left and right children of the temp node, respectively, using the temp->left and temp->right pointers.
		temp->left = left;
		temp->right = right;
		minHeap.push(temp);
	}
	printCodes(minHeap.top(), "");
}


int main(){ //input values
	char data[] = {'A', 'B', 'C', 'D'};
	int freq[] = {23,12,34,10};
	HuffmanCode(data, freq, 4);
	return 0;
}

/*
Huffman Coding :
Time complexity: O(nlogn) where n is the number of unique characters.
If there are n nodes, extractMin() is called 2*(n – 1) times. extractMin() takes O(logn) time as it calls minHeapify(). So, overall complexity is O(nlogn).
*/