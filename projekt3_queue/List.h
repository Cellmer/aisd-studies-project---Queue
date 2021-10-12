#pragma once

struct Node
{
    int value = 0;
    Node* next = nullptr; //nastêpny element
    Node* prev = nullptr; //poprzedni element
};

class List
{
private:
    Node* first; //pocz¹tek listy
    Node* last; //koniec listy
    Node* front; //pocz¹tek kolejki
    Node* back; //koniec kolejki
    mutable Node* actual; //pomocniczy przy ró¿nych operacjach
    int size; //rozmiar listy

public:
    List();

    //metody listy
    Node* get_actual() const { return actual; }
    int get_size() const { return size; } //zwraca rozmiar listy
    void next() const; //przestawia actual na nastêpny element
    void prev() const; //przestawia actual na poprzedni element
    void add_beg(int n); //dodaje wêze³ o wartoœci n na pocz¹tek listy
    void add_end(int n); //dodaje wêze³ o wartoœci n na koniec listy
    void add_act(int n); //dodaje wêze³ o wartoœci n jako poprzednik actual
    void del_beg(); //usuwa z listy pierwszy wêze³
    void del_end(); //usuwa z listy ostatni wêze³
    void delete_node(Node* n); //usuwa z listy dany wêze³
    void print_forward() const; //drukuje zawartoœæ listy od pierwszego do ostatniego elementu
    void print_backward() const; //drukuje zawartoœæ listy od ostatniego do pierwszego elementu

    //metody kolejki
    int count() const; //zwraca rozmiar kolejki
    void push(int n); //wpycha element o wartoœci n na koniec kolejki
    void pop(); //wyci¹ga pierwszy element z kolejki
    void print_queue() const; //drukuje zawartoœæ kolejki (od przodu do ostatnio dodanego elementu)
    void garbage_soft(); //wpisuje wartoœæ 0 do wszystkich elementów listy które nie nale¿¹ do kolejki
    void garbage_hard(); //usuwa z listy wszystkie elementy, które nie nale¿¹ do kolejki

};

