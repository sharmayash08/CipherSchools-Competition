#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node* makeLL(){
    int val;
    cin>>val;
    if(val == -1){
        return NULL;
    }
    Node* head = new Node(val);
    Node* temp = head;
    while(1){
        cin >> val;
        if(val == -1) break;
        Node* new_node = new Node(val);
        temp ->next = new_node;
        temp = temp ->next;
    }
    return head;
    
}

/*int twinSum(Node* head){
    vector<int>arr;
    Node* temp = head;
    while(temp){
        arr.push_back(temp -> data);
        temp = temp -> next;
    }
    int n = arr.size();
    int sum = 0;
    for(int i =0;i< n/2; i++){
        sum = max(sum , (arr[i] + arr[n - 1- i]));
    }

    return sum;
}*/

int twinSum(Node* head){
    Node* slow = head;
    Node* fast = head;
    int sum = 0;
    while(fast !=NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        sum = max(sum , slow -> data + fast -> data);
        slow = slow -> next;
    }
    return sum;

}

void display(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = makeLL();
    display(head);
    // cout << "Maximum twin sum : " << twinSum(head);
    cout << twinSum(head);
    return 0;
}