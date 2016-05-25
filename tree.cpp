/*input
1
15
1
10
1
20
1
8
1
12
1
17
1
25
1
6
1
11
1
16
1
27
0
11
2
3
4
5
12
5
26
6
25
6
99
7
8
9
12
9
15
13
14
11
10
20
11
10
99
11
20
*/
#include <iostream>
#include <queue>
using namespace std;

void printline();

struct node{
    int value;
    node *parent,*left,*right;
};

node *root;

class BST{

public:
    BST(){
        root = NULL;
    }

    void insert(node* tree,node *newNode){

        if(root == NULL){
            root = new node;
            root->value=newNode->value;
            root->parent=root->left=root->right=NULL;
            cout<<"Node Added at Root"<<endl;
            return ;
        }

        if (newNode->value == tree->value){
            cout<<"Element Already in the tree"<<endl;
            return ;
        }

        if (newNode->value<tree->value){
            if (tree->left != NULL){
                insert(tree->left,newNode);
            }
            else{
                tree->left=newNode;
                (tree->left)->left=(tree->left)->right=NULL;
                (tree->left)->parent=tree;
                cout<<"Node Added to Left"<<endl;
                return ;
            }
        }

        else if(newNode->value > tree->value){
            if (tree->right != NULL){
                insert(tree->right,newNode);
            }
            else{
                tree->right=newNode;
                (tree->right)->left=(tree->right)->right=NULL;
                (tree->right)->parent=tree;
                cout<<"Node Added to Right"<<endl;
                return ;
            }
        }

    }

    void preorder(node *tree){

        if (root == NULL) {
            cout<<"Tree is Empty"<<endl;
            return ;
        }

        if(tree != NULL){
            cout<<tree->value<<"\t";
            preorder(tree->left);
            preorder(tree->right);
        }
    }

    void inorder(node *tree){
        if (root == NULL)
        {
            cout<<"Tree is Empty"<<endl;
            return ;
        }

        if(tree!=NULL){
            inorder(tree->left);
            cout<<tree->value<<"\t";
            inorder(tree->right);
        }
    }

    void postorder(node *tree){
        if (root == NULL)
        {
            cout<<"Tree is Empty"<<endl;
            return ;
        }

        if (tree != NULL)
        {
            postorder(tree->left);
            postorder(tree->right);
            cout<<tree->value<<"\t";
        }
    }

    node* search_recursive(node* tree,int search){

        if(tree == NULL || tree->value==search ){
            return tree;
        }

        else if(search < tree->value){
            return search_recursive(tree->left,search);
        }
        else{
            return search_recursive(tree->right,search);
        }
    }

    node* search_itr(node* tree,int search){

        while(tree != NULL && search!=tree->value) {
            if(search < tree->value){
                tree=tree->left;
            }
            else{
                tree=tree->right;
            }
        }

        return tree;
    }

    node* Maximum(node *tree){

        if (root == NULL)
        {
            cout<<"Tree is Empty"<<endl;
            return 0;
        }

        while(tree->right!=NULL){
            tree=tree->right;
        }
        return tree;
    }

    node* Minimum(node *tree){
        if (root == NULL)
        {
            cout<<"Tree is Empty"<<endl;
            return 0;
        }

        while(tree->left!=NULL) {
            tree=tree->left;
        }

        return tree;
    }

    node* Successor(){

        node *temp,*ptr;
        int num;
        cout<<"Enter the Element to find its Successor"<<endl;
        cin>>num;
        temp=search_recursive(root,num);

        if (temp->right!=NULL){
            return Minimum(temp->right);
        }

        ptr=temp->parent;

        while(ptr !=NULL and temp==ptr->right){
            temp=ptr;
            ptr=ptr->parent;
        }

        return ptr;
    }


    bool isBinarySearchtree(node *tree,int minValue,int maxValue){

        if (tree == NULL)
        {
            return true;
        }

        if(tree->value > minValue && tree->value < maxValue && isBinarySearchtree(tree->left,minValue,tree->value) && isBinarySearchtree(tree->right,tree->value,maxValue)){
            return true;
        }
        else
            return false;
    }
    int max(int valA,int valB){
        if(valA>valB)
            return valA;
        else
            return valB;
    }

    int FindHeight(node *tree){

        if (tree == NULL){
            return 0;
        }

        return max(FindHeight(tree->left),FindHeight(tree->right))+1;

    }

    void LevelOrder(node *tree){

        if(root == NULL){
            return ;
        }
        queue<node *> Q;

        Q.push(tree);
        while(!Q.empty()){
            node *current = Q.front();
            cout<<current->value<<"\t";
            if (current->left!=NULL)
            {
                Q.push(current->left);
            }
            if (current->right!=NULL)
            {
                Q.push(current->right);
            }
            Q.pop();
        }
    }

    node* tree_delete(node *tree,int num){

        if(tree == NULL)
            return tree;

        if(num<tree->value)
            tree->left=tree_delete(tree->left,num);
        else if(num>tree->value)
            tree->right=tree_delete(tree->right,num);
        else{

            if(tree->left==NULL && tree->right==NULL){
                tree=NULL;
            }
            else if(tree->left==NULL){
                tree=tree->right;
            }
            else if(tree->right==NULL)
                tree=tree->left;
            else{
                node *temp=Minimum(tree->right);
                tree->value=temp->value;
                tree->right=tree_delete(tree->right,temp->value);
            }
        }

        return tree;
    }

    void display(node *ptr,int level){

        if (root == NULL){
            cout<<"Tree is Empty"<<endl;
            return ;
        }

        int i;
        if (ptr != NULL){

            display(ptr->right,level+1);
            cout<<endl;

            if (ptr==root){
                cout<<"Root: ->";
            }
            else{
                for (i = 0; i <= level; i++){
                    cout<<"\t";
                }
            }

            cout<<ptr->value;
            display(ptr->left,level+1);
        }
    }

};
int main(){

    BST bst;
    node *temp;
    int choice,Option,search,height,num;

    for (int i=1; i>0; ) {

        do {
            printline();
            cout<<"Select One Option"<<endl;
            printline();
            cout<<"1. Insert an Element in the Tree"<<endl;
            cout<<"2. PreOrder Transversal"<<endl;
            cout<<"3. InOrder Transversal"<<endl;
            cout<<"4. PostOrder Transversal"<<endl;
            cout<<"5. Search an Element (Recursive)"<<endl;
            cout<<"6. Search an Element (Non - Recursive)"<<endl;
            cout<<"7. Maximum element of the BST"<<endl;
            cout<<"8. Minimum element of the BST"<<endl;
            cout<<"9. Successor  of the BST"<<endl;
            cout<<"10. Delete a given node from the BST"<<endl;
            cout<<"11. Display the Tree"<<endl;
            cout<<"12. Check If Binary Tree"<<endl;
            cout<<"13. Find Height of Tree"<<endl;
            cout<<"14. Level Order Printing"<<endl;
            cout<<"20. Exit"<<endl;
            printline();
            cout<<"Enter the Choice"<<endl;
            cin>>choice;
        } while (choice <0 || choice >20);

        switch (choice) {

            case 1:
                Option=1;
                printline();
                cout<<"Enter 1 to Continue Inserting"<<endl<<"Enter 0 to Stop Inserting values"<<endl;
                printline();
                cout<<endl;
                while (Option == 1) {
                    if (Option == 1) {
                        temp = new node;
                        cout<<"Enter the number to be inserted : "<<endl;;
                        cin>>temp->value;
                        bst.insert(root,temp);
                        cin>>Option;
                    }

                    else if(Option == 0){
                        break;
                    }
                }
                break;

            case 2:
                cout<<"PreOrder :\t";
                bst.preorder(root);
                cout<<endl;
                break;

            case 3:
                cout<<"InOrder :\t";
                bst.inorder(root);
                cout<<endl;
                break;

            case 4:
                cout<<"PostOrder :\t";
                bst.postorder(root);
                cout<<endl;
                break;


            case 5:
                cout<<"Enter the Element to search in the tree"<<endl;
                cin>>search;
                temp = bst.search_recursive(root,search);
                if (temp == NULL) {
                    cout<<search<<" is not present in the tree"<<endl;
                    break;

                }
                if (temp->value == search) {
                    cout<<search<<" is present in the tree"<<endl;
                }
                break;

            case 6:
                cout<<"Enter the Element to search in the tree"<<endl;
                cin>>search;
                temp = bst.search_itr(root,search);
                if (temp == NULL) {
                    cout<<search<<" is not present in the tree"<<endl;
                    break;

                }
                if (temp->value == search) {
                    cout<<search<<" is present in the tree"<<endl;
                }
                break;

            case 7:
                temp = bst.Maximum(root);
                cout<<"Maximum: "<<temp->value<<endl;
                break;

            case 8:
                temp = bst.Minimum(root);
                cout<<"Minimum: "<<temp->value<<endl;
                break;

            case 9:
                temp = bst.Successor();
                cout<<"Successor: "<<temp->value<<endl;
                cout<<endl;
                break;

            case 10:
                cout<<"Enter the value to be deleted from the Tree"<<endl;
                cin>>num;
                temp=bst.tree_delete(root,num);
                if(temp==NULL){
                    cout<<"Element "<<num<<" Not Present in Tree"<<endl;
                }
                else{
                    cout<<"Element "<<num<<" Deleted from the Tree"<<endl;
                }
                cout<<endl;
                break;

            case 11:
                cout<<"Display BST:"<<endl;
                bst.display(root,1);
                cout<<endl;
                break;

            case 12:
                if(bst.isBinarySearchtree(root,-2147483648,2147483648)){
                    cout<<"It is a Binary Search Tree"<<endl;
                }
                else
                    cout<<"It is not a Binary Search Tree"<<endl;
                break;

            case 13:
                height=bst.FindHeight(root);
                cout<<"Height of Binary Search Tree : "<<height<<endl;
                break;
            case 14:
                cout<<"Elements of Tree :";
                bst.LevelOrder(root);
                cout<<endl;
                break;
            case 20:
                return 0;
        }
    }

    return 0;
}

void printline(){
    for (int i = 0; i < 50; ++i)
    {
        cout<<"-";
    }
    cout<<endl;
}