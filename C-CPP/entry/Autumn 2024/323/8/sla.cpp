#include <iostream>
using namespace std;


typedef struct element * po;
struct element{
    po next;
    int data;
};

int main()
{
    po  na =NULL , p, contr; int x;
    cin>>x; p=new element; p->data=x;
    p->next=na;
    if (na==NULL || na->data >=x ) {
        na =p;
    }

    else
    {
        do{
        contr=p->next;
        p->next= p->next->next;
    }while (p->next!=NULL && p->next->data < x);
        contr->next = p;
    }
}