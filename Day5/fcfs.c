#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    struct node* nxt;
} Node;

Node* create(int pid, int at, int bt) 
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL) 
    {
        printf("Error creating a new node.\n");
    }
    newNode->pid = pid;
    newNode->at = at;
    newNode->bt = bt;
    newNode->nxt = NULL;
    return newNode;
}

Node* insert(Node* head, int pid, int at, int bt) 
{
    Node* newNode = create(pid, at, bt);
    if(head == NULL) 
    {
        return newNode;
    }
    Node* temp = head;
    while(temp->nxt != NULL) 
    {
        temp = temp->nxt;
    }
    temp->nxt = newNode;
    return head;
}

void FCFS(Node* head) 
{
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    int time = 0;
    while(head != NULL) 
    {
        if(time < head->at) 
        {
            time = head->at;
        }
        time += head->bt;
        head->ct = time;
        head->wt = time - head->at - head->bt;
        head->tat = time - head->at;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", head->pid, head->at, head->bt, head->ct, head->wt, head->tat);
        head = head->nxt;
    }
}

int main() 
{
    Node* p = NULL;
    p = insert(p, 1, 0, 3);
    p = insert(p, 2, 4, 2);
    p = insert(p, 3, 5, 3);
    p = insert(p, 4, 2, 1);
    p = insert(p, 5, 5, 2);
    FCFS(p);
    return 0;
}
