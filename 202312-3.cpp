#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct Node{
    struct Node* lchild, *rchild;
    int value;    
    int valid;
}Node, *Tree;

void get_all_value(Tree head, int& sum){
    if(head == nullptr || head->valid == 0){
        return;
    }
    sum += head->value;
    get_all_value(head->lchild, sum);
    get_all_value(head->rchild, sum);
}

int abs(int j){
    return j<0?-j:j; 
}

int get_node(Tree NodeList, int n){
    int all_sum = 0;
    int min = 99999;
    int min_index = -1;
    get_all_value(&NodeList[1], all_sum);
    for(int i = 0; i< n-1; i++){
        int node_sum = 0;
        int num = 0;
        if(NodeList[i+2].valid == 1){
            get_all_value(&NodeList[i+2],node_sum);
            num = abs(all_sum - 2 * node_sum);
            if(min > num){
                min_index = i+2;
                min = num;
            }
        }
    }
    return min_index;
}

void delete_node(Tree head, Tree save){
    if(head == nullptr || head->valid == 0 || head == save)
        return;
    delete_node(head->lchild, save);
    delete_node(head->rchild, save);
    head->valid = 0;
}

bool only_one(Tree NodeList, int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += NodeList[i].valid;
    }
    if (sum == 1) return true;
    else return false;
}

void set_valid(Tree head){
    if(head == nullptr)return;
    head->valid = 1;
    set_valid(head->lchild);
    set_valid(head->rchild);
}

int main(){
    int class_num, question_num;
    cin >> class_num >> question_num;
    Tree class_array = new Node[class_num+1];
    for(int i = 0; i < class_num ; i++){
        int temp;
        cin >> temp;
        class_array[i+1].value = temp;
        class_array[i+1].lchild = nullptr;
        class_array[i+1].rchild = nullptr;
        class_array[i+1].valid = 1;
    }

    for(int i = 0; i< class_num-1; i++){
        int temp;
        cin >> temp;
        if(class_array[temp].lchild != nullptr)
        class_array[temp].rchild = &class_array[i+2];
        else
        class_array[temp].lchild = &class_array[i+2];
    }

    for(int i = 0; i< question_num; i++){
        int question_class;
        cin >> question_class;
        while(1){
            Tree root;
            int answer;
            if(class_array[1].valid == 1)
                root = &class_array[1];
            int node_index = get_node(class_array, class_num);
            if(question_class == node_index){
                if(answer != node_index)
                    cout << node_index << " " ;
                answer = node_index;
                delete_node(root,&class_array[node_index]);
                root = &class_array[node_index];
                bool only = only_one(class_array,class_num);
                if(only)
                {
                    for(int i = 0; i < class_num ; i++) class_array[i+1].valid = 1;
                    cout << endl;
                    break;
                }
            }
            else{
                cout << node_index << " ";
                delete_node(&class_array[node_index], nullptr);
            }
        }
    }
}
