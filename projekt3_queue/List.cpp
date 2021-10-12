#include "List.h"
#include <iostream>

List::List()
{
    first = nullptr;
    last = nullptr;
    front = nullptr;
    back = nullptr;
    actual = nullptr;
    size = 0;
}

void List::next() const
{
    if (actual == last)
    {
        actual = first;
    }
    else
    {
        actual = actual->next;
    }
}

void List::prev() const
{
    if (actual == first)
    {
        actual = last;
    }
    else
    {
        actual = actual->prev;
    }
}

void List::add_beg(int n)
{
    Node* new_node = new Node;
    new_node->value = n;
    new_node->next = first;
    if (size > 0) //lista nie by³a pusta
    {
        first->prev = new_node;
    }
    else //lista by³a pusta, wiêc przypisz dodawany element do actual i do last
    {
        actual = new_node;
        last = new_node;
    }
    first = new_node;
    size++;
}

void List::add_end(int n)
{
    Node* new_node = new Node;
    new_node->value = n;
    new_node->prev = last;
    if (size > 0) //lista nie by³a pusta
    {
        last->next = new_node;
    }
    else //lista by³a pusta, wiêc przypisz dodawany element do actual i do first
    {
        actual = new_node;
        first = new_node;
    }
    last = new_node;
    size++;
}

void List::add_act(int n)
{
    if (actual == first) //actual jest pierwszym elementem (lub lista jest pusta)
    {
        add_beg(n);
    }
    else //actual nie jest pierwszym elementem
    {
        Node* new_node = new Node;
        new_node->value = n;
        new_node->next = actual;
        new_node->prev = actual->prev; //ustawianie poprzednika na poprzednika actuala
        actual->prev = new_node; //ustawianie poprzednika actuala na nowy wêze³
        (new_node->prev)->next = new_node; //ustaw nexta poprzednika actuala na nowy element
        size++;
    }
}

void List::del_beg()
{
    if (size == 1) //lista ma jeden element
    {
        delete first;
        last = nullptr;
        first = nullptr;
        actual = nullptr;
        size--;
    }
    else if (size > 1) //gdy lista ma wiêcej ni¿ jeden element
    {
        if (actual == first) //jeœli actual by³ pierwszym elementem
        {
            prev();
        }
        if (front == first && back == first)
        {
            front = nullptr;
            back = nullptr;
        }
        else if (back == first)
        {
            back = back->next;
        }
        else if (front == first)
        {
            front = last;
        }
        first = first->next;
        delete first->prev;
        first->prev = nullptr;
        size--;
    }
}

void List::del_end()
{
    if (size == 1) //lista ma jeden element
    {
        delete last;
        last = nullptr;
        first = nullptr;
        actual = nullptr;
        size--;
    }
    else if (size > 1) //gdy lista ma wiêcej ni¿ jeden element
    {
        if (actual == last) //jeœli actual by³ ostatnim elementem
        {
            prev();
        }
        if (front == last && back == last)
        {
            front = nullptr;
            back = nullptr;
        }
        else if (back == last)
        {
            back = first;
        }
        else if (front == last)
        {
            front = front->prev;
        }
        last = last->prev;
        delete last->next;
        last->next = nullptr;
        size--;
    }
}

void List::delete_node(Node* n)
{
    if (n != nullptr && n->prev == nullptr) //n jest pierwszym elementem
    {
        del_beg();
    }
    else if (n != nullptr && n->next == nullptr) //n jest ostatnim elementem
    {
        del_end();
    }
    else if (n != nullptr) //n jest którymœ ze œrodkowych elementów
    {
        if (actual == n) //jeœli actual by³ n
        {
            prev();
        }
        if (front == n && back == n)
        {
            front = nullptr;
            back = nullptr;
        }
        else if (front == n)
        {
            front = front->prev;
        }
        else if (back == n)
        {
            back = back->next;
        }
        (n->prev)->next = n->next;
        (n->next)->prev = n->prev;
        delete n;
        size--;
    }
}

void List::print_forward() const
{
    if (first == nullptr)
    {
        std::cout << "NULL\n";
    }
    else
    {
        Node* temp = first;
        while (temp != nullptr)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

void List::print_backward() const
{
    if (last == nullptr)
    {
        std::cout << "NULL\n";
    }
    else
    {
        Node* temp = last;
        while (temp != nullptr)
        {
            std::cout << temp->value << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
}
 //Metody kolejki
int List::count() const
{
    if (front == nullptr)
    {
        return 0;
    }

    int count = 1;
    actual = front;
    while (actual != back)
    {
        count++;
        prev();
    }

    return count;
}

void List::push(int n)
{
    if (size == 0) //pierwszy element (zarówno na liœcie jak i w kolejce)
    {
        add_beg(n);
        front = first;
        back = first;
    }
    else if (count() == 0) //pierwszy element w kolejce
    {
        front = last;
        back = last;
        front->value = n;
    }
    else if (size == count()) //lista jest zape³niona, wiêc dodaj kolejny element przed actual (przed back)
    {
        actual = back;
        add_act(n);
        prev();
        back = actual;
    }
    else //na liœcie s¹ wolne elementy do wykorzystania
    {
        actual = back;
        prev();
        back = actual;
        back->value = n;
    }
}

void List::pop()
{
    if (count() == 0)
    {
        std::cout << "NULL\n";
    }
    else if (count() == 1)
    {
        std::cout << front->value << std::endl;
        front = nullptr;
        back = nullptr;
        actual = nullptr;
    }
    else
    {
        std::cout << front->value << std::endl;
        if (front == first) //czo³o kolejki przeskakuje na koniec listy
        {
            front = last;
        }
        else
        {
            front = front->prev;
        }
    }
}

void List::print_queue() const
{
    if (count() == 0)
    {
        std::cout << "NULL\n";
    }
    else
    {
        actual = front;
        while (actual != back)
        {
            std::cout << actual->value << " ";
            prev();
        }
        std::cout << actual->value << std::endl;
    }
}

void List::garbage_soft()
{
    if (count() == 0) //w kolejce nie ma elementów - wyzeruj ca³¹ listê
    {
        actual = first;
        while (actual != nullptr)
        {
            actual->value = 0;
            actual = actual->next;
        }
    }
    else
    {
        actual = back;
        prev();
        while (actual != front)
        {
            actual->value = 0;
            prev();
        }
    }
}

void List::garbage_hard()
{
    if (count() == 0) //w kolejce nie ma elementów - usuñ ca³¹ listê
    {
        actual = first;
        while (actual != nullptr)
        {
            delete_node(actual); //ta funkcja przestawia element actual w lewo, tak¿e usunie siê ca³a lista
        }
    }
    else
    {
        actual = back;
        prev();
        while (actual != front)
        {
            Node* temp = actual;
            prev();
            delete_node(temp);
        }
    }
}