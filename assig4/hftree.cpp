#include "hftree.h"



HuffmanTree::HuffmanTree() : hfTree(NULL) {}

void HuffmanTree::loadMap(map<char, int> frequency_table)
{
    // create an minimum priority queue in STL
    // insert your code here ...

    struct cmp {
        bool operator()(const HuffmanTreeNode *a, const HuffmanTreeNode *b) {
            if (a->weight == b->weight)
                return int(a->key) > int(b->key);
                // correct
            else
                return a->weight > b->weight;
        }
    };

    // create the priority queue
    priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>, cmp> tree;
    for(map<char, int>::const_iterator it = frequency_table.begin(); it != frequency_table.end(); ++it)
    {
        HuffmanTreeNode* node = new HuffmanTreeNode;
        node->key = it->first;
        node->weight = it->second;
        tree.push(node);
    }

    // while(!tree.empty())
    // {
    //     cout << tree.top()->key << "-" << tree.top()->weight <<endl;
    //     tree.pop();
    // }

    while(tree.size() > 1)
    {
        
        //pop two elements from priority queue to construct a binary tree
        HuffmanTreeNode* leftChild = tree.top();  
        tree.pop();

        HuffmanTreeNode* rightChild = tree.top();   
        tree.pop();

        // cout<<leftChild->weight<<"  "<<rightChild->weight<<endl;

        HuffmanTreeNode* newNode = new HuffmanTreeNode;
        mergeTree(leftChild, rightChild, newNode);
        tree.push(newNode);
        
    }

    hfTree = tree.top(); // root of the tree
    tree.pop();


}

void HuffmanTree::mergeTree(HuffmanTreeNode *bt1, HuffmanTreeNode *bt2,
                       HuffmanTreeNode *pt)
{
    // insert your code here ...
    
    pt->weight = bt1->weight + bt2->weight;
    pt->leftChild = bt1;
    pt->rightChild = bt2;
    pt->key = char(min(int(bt1->key),int(bt2->key)));   // choose the key as min ascii of two nodes, for ordering in priority queue


}


void HuffmanTree::encode(map<char, string>& encoded_table)
{
    // go through every path from root to leaf, then get the encoding of each character(leaf node)
    // you are NOT allowed to use any recursive method here, otherwise you'll get no marks for this function
    // try level-order traversal on this Huffman Tree
    // result encoded_table: char -- character set, string -- encoding of leaf node, like "00", "1001"...

    // insert your code here ...
    

    if(hfTree == NULL) return;
    queue<HuffmanTreeNode *> Q;
    Q.push(hfTree);
    
    while(!Q.empty())
    {
        HuffmanTreeNode *curr = Q.front();

        // cout << curr->huffman_code << " ";
        if(curr->leftChild == NULL || curr->rightChild == NULL)
        {
            if (curr->huffman_code == "") curr->huffman_code = "0";
            encoded_table[curr->key] = curr->huffman_code;
        }
        if(curr->leftChild != NULL) 
        {
            curr->leftChild->huffman_code = curr->huffman_code + "0";
            Q.push(curr->leftChild);
        }
        if(curr->rightChild != NULL) 
        {
            curr->rightChild->huffman_code = curr->huffman_code + "1";
            Q.push(curr->rightChild);
        }
        Q.pop();
    }
    
  // for(map<char, string>::const_iterator it = encoded_table.begin(); it != encoded_table.end(); ++it)
  //       cout << "<" << it->first << "," << it->second << ">" << endl;




}

string HuffmanTree::decode(const string& bin_str)
{
    // decode a binary string to plaintext
    // insert your code here ...
    HuffmanTreeNode* curr = hfTree;
    string plaintext;

    for (int i =0; i < bin_str.size(); i++)
    {
        if(bin_str[i] == '0') 
        {
            curr = curr->leftChild;
            
        }
        if(bin_str[i] == '1')
        {
            curr = curr->rightChild;
        } 

        if(curr->leftChild == NULL && curr->rightChild == NULL)
        {
            plaintext += curr->key;
            curr = hfTree;
        }

    }
    return plaintext;
  
        
    
    





}

void HuffmanTree::release()
{
    // release all tree nodes in post-order
    // you must use non-recursive traversal to release the tree
    // you need to print out the weight of nodes with post-order when you delete the node
    // hint: try to use stack
    // if you use recursive deletion, you will lose partial marks of this PA

    cout << "[start releasing the huffman tree...]" << endl;
    if (hfTree == NULL)
        return;

    // store the nodes in vector path with post-order first
    vector<HuffmanTreeNode*> path;

    // insert your code here ...
    

    stack<HuffmanTreeNode *> s1; 
    s1.push(hfTree); 
    HuffmanTreeNode* node; 
  
    while (!s1.empty()) 
    { 
        node = s1.top(); 
        s1.pop(); 
        path.push_back(node); 
  
        if (node->leftChild) 
            s1.push(node->leftChild); 
        if (node->rightChild) 
            s1.push(node->rightChild); 
    } 
    // reverse order in path
    reverse(path.begin(), path.end()); 



    for (int i = 0; i < path.size(); i++) {
        if (i != path.size() - 1)
            cout << dec << path[i]->weight << " ";
        else
            cout << dec << path[i]->weight << endl;

        // delete the node
        delete path[i];
    }
    cout << "[successfully released.]" << endl;
}

