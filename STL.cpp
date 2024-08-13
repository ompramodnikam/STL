//Write the application to create Standard Templete Library(STL) 
//which contains all the inbuild functions of Data structures 

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Singly Linear Linked List
//  Description  :      Implimentation of All the methods of Data structures of Singly Linear LinkedList
//  Author       :      Om Pramod Nikam
//  Date         :      04/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
struct nodeSL 
{
    T data;
    struct nodeSL* next;
};

template <class T>
class SinglyLL
{
    private :
        struct nodeSL <T> * First;
        int iCount;

    public :
        SinglyLL();
        void Display();
        int Count();
        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL <T> :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL <T> :: Display()
{
    struct nodeSL <T> * temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL <T> :: Count()
{
    return iCount;
}

template <class T>
void SinglyLL <T> :: InsertFirst(T No)
{
    struct nodeSL <T> * newn = NULL;
    newn = new nodeSL <T> ;
    
    newn ->data = No;
    newn ->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL <T> :: InsertLast(T No)
{
    struct nodeSL <T> * newn = NULL;
    newn = new nodeSL <T> ;

    struct nodeSL <T> * temp = NULL;
    
    newn ->data = No;
    newn ->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp->next != NULL)
        {
            temp = temp ->next;
        }
        temp ->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL <T> :: InsertAtPos(T No, int iPos)
{
    struct nodeSL <T> * newn = NULL;
    struct nodeSL <T> * temp = NULL;
    int iLength = 0;
    int i = 0;

    newn = new nodeSL <T> ;
    newn ->data = No;
    newn ->next = NULL;

    iLength = Count();

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == (iLength+1))
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp ->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL <T> :: DeleteFirst()
{    
    struct nodeSL <T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    else if(First ->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        delete temp;
    }

    iCount--;
}

template <class T>
void SinglyLL <T> :: DeleteLast()
{
    struct nodeSL <T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    else if(First ->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        
        while(temp ->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

template <class T>
void SinglyLL <T> :: DeleteAtPos(int iPos)
{
    struct nodeSL <T> * temp1 = NULL;
    struct nodeSL <T> * temp2 = NULL;

    int iLength = 0;
    int i = 0;

    iLength = Count();

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp1 = temp1 ->next;
        }

        temp2 = temp1 ->next;
        temp1 ->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Singly Circular Linked List
//  Description  :      Implimentation of All the methods of Data structures of Singly Circular LinkedList
//  Author       :      Om Pramod Nikam
//  Date         :      04/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeSC
{
    T data;
    struct nodeSC<T>* next;
};

template <class T>
class SinglyCL
{
    private : 
        struct nodeSC<T>* First;
        struct nodeSC<T>* Last;
        int iCount;

    public :
        SinglyCL();
        void Display();
        int Count();
        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);      
};

template <class T>
SinglyCL <T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL <T> :: Display()
{
    do
    {
        cout<<"| "<<First->data<<" | -> ";
        First = First->next;

    }while(First != Last->next);

    cout<<endl;
}

template <class T>
int SinglyCL <T> :: Count()
{
    return iCount;
}

template <class T>
void SinglyCL <T> :: InsertFirst(T No)
{
    struct nodeSC<T>* newn = NULL;
    newn = new nodeSC<T>;
    newn ->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        First ->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyCL <T> :: InsertLast(T No)
{
    struct nodeSC<T>* newn = NULL;
    newn = new nodeSC<T>;
    newn ->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        First ->next = First;
    }
    else
    {
        Last->next = newn;
        newn->next = First;
        Last = newn;
    }
    iCount++;
}

template <class T>
void SinglyCL <T> :: InsertAtPos(T No, int iPos)
{
    int i = 0;

    struct nodeSC<T>* temp = NULL;
    struct nodeSC<T>* newn = NULL;
    newn = new nodeSC<T>; 

    newn ->data = No;
    newn ->next = NULL;

    int iLength = 0;
    iLength = Count();

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp ->next;
        }
        newn->next = temp->next;
        temp ->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL <T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is empty.."<<endl;
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL <T> :: DeleteLast()
{
    struct nodeSC<T>* temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is empty.."<<endl;
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;
        while(temp ->next != Last)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp ->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL <T> :: DeleteAtPos(int iPos)
{
    int i = 0;
    int iLength = 0;
    iLength = Count();

    struct nodeSC<T>* temp1 = NULL;
    struct nodeSC<T>* temp2 = NULL;

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1 ->next = temp2 ->next;
        delete temp2;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Doubly Linear Linked List
//  Description  :      Implimentation of All the methods of Data structures of Doubly Linear LinkedList
//  Author       :      Om Pramod Nikam
//  Date         :      04/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeDL
{   
    T data;
    struct nodeDL<T>* next;
    struct nodeDL<T>* prev;
};

template <class T>
class DoublyLL
{
    private :
        struct nodeDL<T>* First;
        int iCount;

    public : 
        DoublyLL();
        void Display();
        int Count();
        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL <T> :: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL <T> :: Display()
{
    struct nodeDL<T>* temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template <class T>
int DoublyLL <T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyLL <T> :: InsertFirst(T No)
{
    struct nodeDL<T>* newn = NULL;
    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        First->prev = newn;
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL <T> :: InsertLast(T No)
{
    struct nodeDL<T>* newn = NULL;
    newn = new nodeDL<T>;
    struct nodeDL<T>* temp = NULL;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL <T> :: InsertAtPos(T No, int iPos)
{
    int i = 0;
    int iLength = 0;
    iLength = Count();

    struct nodeDL<T>* temp = NULL;
    struct nodeDL<T>* newn = NULL;
    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == (iLength+1))
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        for(i = 1 ; i < (iPos-1) ; i++)
        {
            temp = temp->next;
        }
        temp ->next->prev = newn;
        newn->next = temp->next;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL <T> :: DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL <T> :: DeleteLast()
{
    struct nodeDL<T>* temp = NULL;

    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL <T> :: DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeDL<T>* temp = NULL;
    int iLength = 0;
    iLength = Count();

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength+1)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Doubly Circular Linked List
//  Description  :      Implimentation of All the methods of Data structures of Doubly Circular LinkedList
//  Author       :      Om Pramod Nikam
//  Date         :      04/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeDC
{
    T data;
    struct nodeDC<T>* next;
    struct nodeDC<T>* prev;
};

template <class T>
class DoublyCL
{
    private : 
        struct nodeDC<T>* First;
        struct nodeDC<T>* Last;
        int iCount;
    
    public :
        DoublyCL();
        void Display();
        int Count();
        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL <T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL <T> :: Display()
{
    do
    {
        cout<<"| "<<First->data<<" | -> ";
        First = First->next;
    } while (First != Last->next);   

    cout<<endl;
}

template <class T>
int DoublyCL <T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyCL <T> :: InsertFirst(T No)
{
    struct nodeDC<T>* newn = NULL;
    newn = new nodeDC<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        First->next = newn;
        First->prev = newn;
    }
    else
    {
        First->prev = newn;
        newn->next = First;
        First = newn;
        First->prev = Last;
        Last->next = First;
    }
    iCount++;
}

template <class T>
void DoublyCL <T> :: InsertLast(T No)
{
    struct nodeDC<T>* newn = NULL;
    newn = new nodeDC<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        First->next = newn;
        First->prev = newn;
    }
    else
    {
        newn->prev = Last;
        Last->next = newn;
        Last = newn;
        newn->next = First;
        First->prev = Last;
    }
    iCount++;
}

template <class T>
void DoublyCL <T> :: InsertAtPos(T No, int iPos)
{
    int i = 0;
    int iLength = 0;
    iLength = Count();

    struct nodeDC<T>* temp = NULL;

    struct nodeDC<T>* newn = NULL;
    newn = new nodeDC<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        
        iCount++;
    }
}

template <class T>
void DoublyCL <T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    else if(First == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = Last;
        Last->next = First;
    }

    iCount--;
}

template <class T>
void DoublyCL <T> :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    else if(First == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete Last->next;
        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

template <class T>
void DoublyCL <T> :: DeleteAtPos(int iPos)
{
    int i = 0;
    int iLength = 0;

    iLength = Count();

    struct nodeDC<T>* temp = NULL;

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Stack
//  Description  :      Implimentation of All the methods of Stack
//  Author       :      Om Pramod Nikam
//  Date         :      04/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeS
{
    T data;
    struct nodeS<T>* next;
};

template <class T>
class Stack
{
    private : 
        struct nodeS<T>* First;
        int iCount;

    public : 
        Stack();
        void Display();
        int Count();
        void Push(T No);
        int Pop();
};

template <class T>
Stack <T> :: Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack <T> :: Display()
{
    struct nodeS<T>* temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

template <class T>
int Stack <T> :: Count()
{
    return iCount;
}

template <class T>
void Stack <T> :: Push(T No)
{
    struct nodeS<T>* newn = NULL;
    newn = new nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
int Stack <T> :: Pop()//DeleteFirst()
{
    int Poped = 0;
    struct nodeS<T>* temp = NULL;
    
    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        Poped = First->data;
        First = First->next;
        delete temp;
    }
    iCount++;
    return Poped;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Queue
//  Description  :      Implimentation of All the methods of Queue
//  Author       :      Om Pramod Nikam
//  Date         :      04/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeQ
{
    T data;
    struct nodeQ<T>* next;
};

template <class T>
class Queue
{
    private : 
        int iCount;
        struct nodeQ<T>* First;

    public : 
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);
        int DeQueue();
};

template <class T>
Queue <T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue <T> :: Display()
{
    struct nodeQ<T>* temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp ->next;
    }
    cout<<endl;
}

template <class T>
int Queue <T> :: Count()
{
    return iCount;
}

template <class T>
void Queue <T> :: EnQueue(T No)
{
    struct nodeQ<T>* newn = NULL;
    newn = new nodeQ<T>;

    struct nodeQ<T>* temp = NULL;
    
    newn ->data = No;
    newn ->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp->next != NULL)
        {
            temp = temp ->next;
        }
        temp ->next = newn;
    }
    iCount++;
}

template <class T>
int Queue <T> :: DeQueue()
{
    struct nodeQ<T>* temp = NULL;
    T iDelete;

    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
    }
    else if(First ->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        iDelete = temp->data;
        delete temp;
    }
    iCount--;
    return iDelete;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Bubble Sorting
//  Description  :      Implimentation of Bubble Sort Algorithm
//  Author       :      Om Pramod Nikam
//  Date         :      04/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class BubbleSorting
{
    private :   
        int iSize;
        T *Arr;
    
    public : 
        BubbleSorting(int A);
        ~BubbleSorting();
        void Accept();
        void Display();
        void BubbleSort();
};

template <class T>
BubbleSorting <T> :: BubbleSorting(int A)
{
    this->iSize = A;
    this->Arr = new T[iSize];
}

template <class T>
BubbleSorting <T> :: ~BubbleSorting()
{
    delete []Arr;
}

template <class T>
void BubbleSorting <T> :: Accept()
{
    int i = 0;

    cout<<"Enter the elements : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void BubbleSorting <T> :: Display()
{
    int i = 0;

    cout<<"Entered elements are : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<endl;
}

template <class T>
void BubbleSorting <T> :: BubbleSort()
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for(i = 0 ; i < iSize ; i++)
    {
        for(j = 0 ; j < iSize-1-i ; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Selection sort
//  Description  :      Implimentation of Selection sort ALgorithm
//  Author       :      Om Pramod Nikam
//  Date         :      04/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SelectionSorting
{
    private :   
        int iSize;
        T *Arr;
    
    public : 
        SelectionSorting(int A);
        ~SelectionSorting();
        void Accept();
        void Display();
        void SelectionSort();
};

template <class T>
SelectionSorting <T> :: SelectionSorting(int A)
{
    this->iSize = A;
    this->Arr = new T[iSize];
}

template <class T>
SelectionSorting <T> :: ~SelectionSorting()
{
    delete []Arr;
}

template <class T>
void SelectionSorting <T> :: Accept()
{
    int i = 0;

    cout<<"Enter the elements : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void SelectionSorting <T> :: Display()
{
    int i = 0;

    cout<<"Entered elements are : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<endl;
}

template <class T>
void SelectionSorting <T> :: SelectionSort()
{
    int i = 0;
    int j = 0;
    int min_index = 0;
    int temp = 0;

    for(i = 0 ; i < iSize ; i++)
    {
        min_index = i;

        for(j = i ; j < iSize ; j++)
        {
            if(Arr[min_index] > Arr[j])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Insertion Sort 
//  Description  :      Implimentation of Insertion sort Algorithm
//  Author       :      Om Pramod Nikam
//  Date         :      04/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class InsertionSorting
{
    private :   
        int iSize;
        T *Arr;
    
    public : 
        InsertionSorting(int A);
        ~InsertionSorting();
        void Accept();
        void Display();
        void InsertionSort();
};

template <class T>
InsertionSorting <T> :: InsertionSorting(int A)
{
    this->iSize = A;
    this->Arr = new int[iSize];
}

template <class T>
InsertionSorting <T> :: ~InsertionSorting()
{
    delete []Arr;
}

template <class T>
void InsertionSorting <T> :: Accept()
{
    int i = 0;

    cout<<"Enter the elements : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
void InsertionSorting <T> :: Display()
{
    int i = 0;

    cout<<"Entered elements are : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<endl;
}

template <class T>
void InsertionSorting <T> :: InsertionSort()
{
    int i = 0;
    int key = 0;
    int j = 0;

    for(i = 1 ; i < iSize ; i++)
    {
        key = Arr[i];
        j = i - 1;

        while((j >= 0) && (Arr[j] > key))
        {
            Arr[j+1] = Arr[j];
            j = j-1;
        }
        Arr[j+1] = key;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Linear Search
//  Description  :      Implimentation of Linker Search Algorithm
//  Author       :      Om Pramod Nikam
//  Date         :      13/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class LinearSearching
{
    private :   
        int iSize;
        T *Arr;
    
    public : 
        LinearSearching(int A);
        ~LinearSearching();
        void Accept();
        bool LinearSearch(T iNo);
};

template <class T>
LinearSearching <T> :: LinearSearching(int A)
{
    this->iSize = A;
    this->Arr = new int[iSize];
}

template <class T>
LinearSearching <T> :: ~LinearSearching()
{
    delete []Arr;
}

template <class T>
void LinearSearching <T> :: Accept()
{
    int i = 0;

    cout<<"Enter the elements : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
bool LinearSearching <T> :: LinearSearch(T iNo)
{
    bool bFlag = false;
    int i = 0;

    for(i = 0 ; i < iSize ; i++)
    {
        if(Arr[i] == iNo)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Birectional Search
//  Description  :      Implimentation of Birectional Search Algorithm
//  Author       :      Om Pramod Nikam
//  Date         :      13/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Bidirectional
{
    private :   
        int iSize;
        T *Arr;
    
    public : 
        Bidirectional(int A);
        ~Bidirectional();
        void Accept();
        bool Bidirsearch(T iNo);
};

template <class T>
Bidirectional <T> :: Bidirectional(int A)
{
    this->iSize = A;
    this->Arr = new int[iSize];
}

template <class T>
Bidirectional <T> :: ~Bidirectional()
{
    delete []Arr;
}

template <class T>
void Bidirectional <T> :: Accept()
{
    int i = 0;

    cout<<"Enter the elements : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
bool Bidirectional <T> :: Bidirsearch(T iNo)
{
    int iStart = 0;
    int iEnd = 0;
    bool bFlag = false;
    int i = 0;

    for(iStart = 0,iEnd = iSize-1 ; iStart <= iEnd ; iStart++,iEnd--)
    {
        if((Arr[iStart] == iNo ) || (Arr[iEnd] == iNo))
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DS Name      :      Binary Search
//  Description  :      Implimentation of Binary Search Algorithm
//  Author       :      Om Pramod Nikam
//  Date         :      13/08/2024
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class BinarySearch
{
    private :   
        int iSize;
        T *Arr;
    
    public : 
        BinarySearch(int A);
        ~BinarySearch();
        void Accept();
        bool Binarysearch(T iNo);
};

template <class T>
BinarySearch <T> :: BinarySearch(int A)
{
    this->iSize = A;
    this->Arr = new int[iSize];
}

template <class T>
BinarySearch <T> :: ~BinarySearch()
{
    delete []Arr;
}

template <class T>
void BinarySearch <T> :: Accept()
{
    int i = 0;

    cout<<"Enter the elements : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cin>>Arr[i];
    }
}

template <class T>
bool BinarySearch <T> :: Binarysearch(T iNo)
{
    int iStart = 0;
    int iMid = 0;
    int iEnd = 0;
    bool bFlag = false;

    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart)/2);

        if(Arr[iStart] == iNo || Arr[iMid] == iNo || Arr[iEnd] == iNo)
        {
            bFlag = true;
            break;
        }
        else if(Arr[iMid] < iNo)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > iNo)
        {
            iEnd = iMid + 1;
        }
    }
    return bFlag;
}


int main()
{
    //It is a library which don't have Main Function 

    return 0;
}