#include <iostream>
using namespace std;

typedef struct Node{
    struct Node* lchild, *rchild;
    int value;    
}Node, *Tree;

void get_all_value(Tree head, int& sum){
    if(head == nullptr){
        return;
    }
    sum += head->value;
    get_all_value(head->lchild, sum);
    get_all_value(head->rchild, sum);
}

int abs(int j){
    return j<0?-j:j; 
}

int get_node(Tree *NodeList, int n){
    int all_sum = 0;
    int min = 99999;
    int min_index = -1;
    get_all_value(NodeList[1], all_sum);
    for(int i = 0; i< n-1; i++){
        int node_sum = 0;
        int num = 0;
        if(NodeList[i+2] != nullptr){
            get_all_value(NodeList[i+2],node_sum);
            num = abs(all_sum - 2 * node_sum);
            if(min > num){
                min_index = -1;
                min = num;
            }
        }
    }
    return min_index;
}

void delete_node(Tree head){
    if(head == nullptr)
    return
    delete_node(head->lchild);
    delete_node(head->rchild);
    delete(head);
}

int main(){
    int class_num, question_num;
    cin >> class_num >> question_num;
    Tree *class_array = new Tree[class_num+1];
    for(int i = 0; i < class_num ; i++){
        int temp;
        cin >> temp;
        class_array[i+1]->value = temp;
    }
    for(int i = 0; i< class_num-1; i++){
        int temp;
        cin >> temp;
        if(class_array[temp]->lchild != nullptr)
        class_array[temp]->rchild = class_array[i+2];
        else
        class_array[temp]->lchild = class_array[i+2];
    }
    for(int i = 0; i< question_num -1; i++){
        int question_class;
        cin >> question_class;
        while(1){
            int node_index = get_node(class_array, class_num);
            if(question_class == node_index){
                cout << "Yes";
                break;
            }
            if(node_index == 1) break;
            else{
                cout << "No";
                cout << node_index << " ";
                delete_node(class_array[node_index]);
            }
        }
    }
}
