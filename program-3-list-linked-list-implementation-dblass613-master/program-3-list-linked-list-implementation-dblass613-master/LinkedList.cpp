#include "LinkedList.h"
#include <iostream>
#include <random>
using namespace std;

LinkedList::LinkedList(){ //create an empty linked list
    first = NULL;
    n=0;
}

bool LinkedList::Empty(){ //checks to see if list is empty
    if(first == NULL){
        return true;
    }else{
        return false;
    }
}

void LinkedList::InsertAtEnd(ElementType x){ //inserts a non-empty string at the end of the list
    node* newptr = new node;
    newptr->data = x;
    newptr->next=NULL;
    node *p = first;

    if(n==0){
        first = newptr;
        n++;
    }else if(first->next == NULL){
        first->next = newptr;
        n++;
    }else{
        do{
            p = p->next;
        }while(p->next != NULL);
        p->next = newptr;
        n++;
    }
}

void LinkedList::Delete(ElementType x) { // If value x is in the list, remove x (all instances)
    node *a = first->next;
    node *follow = first;
    for(int i=0; i<n; i++){
        if(first->data == x){
            if(first->next == NULL){
                node *b = first;
                delete b;
                cout<<"list is empty insert more strings"<<endl;
                n--;
            }else{
                node *b = first;
                first = first->next;
                delete b;
                n--;
            }
        }else if(a->data == x){
            if(a->next == NULL){
                node *b = a;
                delete b;
                n--;
            }else{
                follow->next = a->next;
                node *b = a;
                a = a->next;
                delete b;
                follow = follow->next;
                n--;
            }
        }else{
            follow = a;
            a = a->next;
        }
    }
}

void LinkedList::Display() { // Display the data values in the list
    node *c = first;
    for(int i=0; i<n; i++){
        cout<<c->data<<endl;
        c=c->next;
    }
}

void LinkedList::Sort(){ // Sort the list of strings based on length (shortest to longest)
    node *d = first;
    for(int i=0; i<n; i++) {
        temp[i] = d->data;
        if(d->next == NULL)
            break;
        else
            d=d->next;
    }

    for(int i=1 ;i<n; i++){
        string hold= temp[i];
        int j = i - 1;
        while (j >= 0 && hold.length() < temp[j].length()){
            temp[j+1] = temp[j];
            j--;
        }
        temp[j+1] = hold;
    }

    d = first;
    for(int i=0; i<n; i++){
        d->data = temp[i];
        if(d->next == NULL)
            break;
        else
            d=d->next;
    }
}

double LinkedList::Average() { // Compute amd return the average string length for the strings in the list
    double sum = 0;
    double average = 0;
    double total = n;
    node *m = first;
    for(int i=0; i<n; i++){
        sum+=m->data.length();
        if(m->next == NULL)
            break;
        else
            m=m->next;
    }
    return average = sum/total;
}

double LinkedList::Median(){ //Compute and return the median string length for the strings in the list
    Sort();
    double sum;
    double median;
    double total = n;
    node *l = first;
    if(n%2 == 0){
        for(int i=0; i<(n/2-1); i++){
            l = l->next;
        }
        return median = (l->data.length() + l->next->data.length())/2;
    }else{
        for(int i=0;i<n/2; i++){
            l = l->next;
        }
        median = l->data.length();
        return median;
    }
}

void LinkedList::Shuffle() { // Shuffle the strings in the list around
    node *d = first;
    ElementType hold[MAX];
    for(int i=0; i<n; i++){
        temp[i] = d->data;
        d = d->next;
    }

    random_device random;
    mt19937 gen(random());
    uniform_int_distribution<>dis(0 , n);

    for(int j=0; j<n; j++){
        int rdInt = dis(gen);
        if (temp[rdInt] != "") {
            hold[j] = temp[rdInt];
            temp[rdInt] = "";
        } else {
            j--;
        }
    }
    d=first;
    for(int k=0; k<n; k++){
        d->data = hold[k];
        d=d->next;
    }

}























