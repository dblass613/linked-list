/*
 * Author: Dazhia Blassingame
 *file: LinkedList.h
*/
#include <iostream>
using namespace std;
typedef string ElementType;
const int MAX=100;
struct node

{
    ElementType data;
    node * next;
};

class LinkedList{
public:
    LinkedList(); // Create an empty list
    bool Empty(); // Return true if the list is empty, otherwise return false
    void InsertAtEnd(ElementType x); // Insert a value x at the end of the list
    void Delete(ElementType x); // If value x is in the list, remove x (all instances)
    void Display(); // Display the data values in the list
    void Sort(); // Sort the list of strings based on length (shortest to longest)
    double Average(); // Compute amd return the average string length for the strings in the list
    double Median(); // Compute and return the median string length for the strings in the list
    void Shuffle(); // Shuffle the strings in the list around

private:
    node * first; // Pointer
    int n;
    ElementType temp[MAX];

};
