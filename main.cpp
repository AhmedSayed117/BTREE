#include <iostream>
using namespace std;

struct Node{
    int *keys;
    Node **Childs;
    int position = -1;
    int NumbersOfKeys;
    bool IsLeaf;
public:
    Node(int NKeys){
        NumbersOfKeys = NKeys;

        keys = new int [NKeys];
        Childs = new Node * [NKeys+1];
        IsLeaf = true;
    }

};

class BTree{
    Node *Root = NULL;
    int NKeys;
    public:

    BTree(int Order);
    void insert(int value);
};

BTree::BTree(int Order) {
    NKeys = Order-1;
}
void BTree::insert(int value) {
    Node* Current = Root;
    if (Current == NULL){
        Node *newNode = new Node(NKeys);
        newNode->keys[++newNode->position] = value;
        Root = newNode;
    }else{
        if(Current->IsLeaf){
            if (Current->position+1 == Current->NumbersOfKeys)
            {
                //split
                int arr[Current->NumbersOfKeys+1];
                for(int i=0;i<Current->NumbersOfKeys;i++){
                    arr[i] = Current->keys[i];
                }
                arr[Current->NumbersOfKeys] = value;
                for(int i=Current->NumbersOfKeys; i>0 ;i--)
                {
                    if (arr[i] < arr[i-1]) swap(arr[i],arr[i-1]);
                }
                int parentValue =  arr[(Current->NumbersOfKeys)/2];


            }
            else
            {
                Current->keys[++Current->position] = value;
//                    for(int i=0;i<=Current->position;i++){
//                        cout<<Current->keys[i]<<" ";
//                    }
//                    cout<<"\nOrder\n";
                for(int i=Current->position; i>0 ;i--)
                {
                    if (Current->keys[i] < Current->keys[i-1]) swap(Current->keys[i],Current->keys[i-1]);
                }
//                    for(int i=0;i<=Current->position;i++){
//                        cout<<Current->keys[i]<<" ";
//                    }
//                    cout<<"\nNot\n";
            }
        }
        else
        {

        }



        }
    }


int main() {
    BTree B(10);
    B.insert(50);
    B.insert(20);
    B.insert(5);
    B.insert(100);
    B.insert(70);
    B.insert(2);
    B.insert(1);
    B.insert(0);
    B.insert(30);
    B.insert(30);

    return 0;
}