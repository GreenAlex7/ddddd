#include <iostream> 
#include <vector> 
using std::cout; 
using std::endl; 
using std::vector; 

namespace mycontainers 
{ 
template <class T> 
struct Node 
{ 
T data; // данные в узле 
Node* next; // указатель на следующий узел 
int n; 
Node(T data) // конструктор 
{ 
this->data = data; 
this->next = nullptr; 
} 
}; 



template <class T> 
class MyLinkedList 
{ 
protected: 
Node<T>* head; // указатель на начало списка 
size_t count; // счетчик количества элементов 
public: 
MyLinkedList(); 
~MyLinkedList(); 
void push_back(T x); 
void push_front(T x); 
void insert(T x,T n); 
void show() const; 
void pop_back(); 
void pop_front(); 
int size(); 
void clear(); 
}; 



template <class T> 
MyLinkedList<T>::MyLinkedList() 
{ 
cout « " "; 
cout « "MyLinkedList created!" « endl; 
head = nullptr; 
count = 0; 
} 
template <class T> 
void MyLinkedList<T>::insert(T x, T n) 
{ 

Node<T>* current = head; 
count = 1; 
do { 
current = current->next; 
count++; 
} while (count != n); 
current = new Node<T>(x); 
} 
template <class T> 
int MyLinkedList<T>::size() 
{ 
return count; 
cout « count; 
} 

template <class T> 
void MyLinkedList<T>::push_back(T x) 
{ 
if (head == nullptr) // count == 0 
head = new Node<T>(x); 
else 
{ 
Node<T>* current = head; 
while (current->next != nullptr) 
current = current->next; 
current->next = new Node<T>(x); 
} 
++count; 
} 
////////////////////////////////// 

template <class T> 
void MyLinkedList<T>::pop_back() 
{ 
Node<T>* tmp = 0; 
if (head == nullptr) // count == 0 
cout « "nullptr" « endl; 
else 
{ 
Node<T>* current = head; 
while (current->next->next != nullptr) 
current = current->next; 

delete current->next; 
current->next = nullptr; 
} 
—count; 
} 
/////////////////////////////////////// 
template <class T> 
void MyLinkedList<T>::pop_front() 
{ 
Node<T>* tmp = 0; 
if (head == nullptr) // count == 0 
cout « "nullptr" « endl; 
else 
{ 
tmp = head; 
head = head->next; 
delete tmp; 
} 
—count; 
} 
template <class T> 
void MyLinkedList<T>::show() const 
{ 
if (count > 0) 
{ 
Node<T>* current = head; 
while (current != nullptr) 
{ 
cout « current->data « " -> "; 
current = current->next; 
} 
cout « "nullptr" « endl; 
} 
} 
template <class T> 
void MyLinkedList<T>::push_front(T x) 
{ 
if (count == 0) 
head = new Node<T>(x); 
else 
{ 
Node<T>* newobj = new Node<T>(x); 
newobj->next = head; 
head = newobj; 
} 
++count; 
} 
template <class T> 
void MyLinkedList<T>::clear() 
{ 
count = 0; 
} 
template <class T> 
MyLinkedList<T>::~MyLinkedList() 
{ 
if (count > 0) 
{ 
cout « "MyLinkedList removing all objects" « std::endl; 
Node<T>* tmp = nullptr; 
while (head != nullptr ) 
{ 
tmp = head; 
head = head->next; 
delete tmp; 
} 
} 
} 

} 

int main() 
{ 
mycontainers::MyLinkedList<int> lst; 
lst.push_back(16); 
lst.push_back(25); 
lst.push_back(32); 
lst.push_back(24); 
lst.push_back(24); 
lst.push_back(20); 
lst.insert(3, 4); 
lst.size(); 
// cout « lst.head->data « endl; 
// cout « lst.head->next->data « endl; 
// cout « lst.head->next->next->data « endl; 
mycontainers::Queue<char> q; 
// реализовать 
// pop_back():, pop_front():, insert(), size():, clear():, empty() 
// erase() — удалить объект по индексу. 
// перегрузка оператора [] для вывода через for(int i;..) lst[i] 
// 
}
