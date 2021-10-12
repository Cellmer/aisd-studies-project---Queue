#pragma once

struct Node
{
    int value = 0;
    Node* next = nullptr; //nast�pny element
    Node* prev = nullptr; //poprzedni element
};

class List
{
private:
    Node* first; //pocz�tek listy
    Node* last; //koniec listy
    Node* front; //pocz�tek kolejki
    Node* back; //koniec kolejki
    mutable Node* actual; //pomocniczy przy r�nych operacjach
    int size; //rozmiar listy

public:
    List();

    //metody listy
    Node* get_actual() const { return actual; }
    int get_size() const { return size; } //zwraca rozmiar listy
    void next() const; //przestawia actual na nast�pny element
    void prev() const; //przestawia actual na poprzedni element
    void add_beg(int n); //dodaje w�ze� o warto�ci n na pocz�tek listy
    void add_end(int n); //dodaje w�ze� o warto�ci n na koniec listy
    void add_act(int n); //dodaje w�ze� o warto�ci n jako poprzednik actual
    void del_beg(); //usuwa z listy pierwszy w�ze�
    void del_end(); //usuwa z listy ostatni w�ze�
    void delete_node(Node* n); //usuwa z listy dany w�ze�
    void print_forward() const; //drukuje zawarto�� listy od pierwszego do ostatniego elementu
    void print_backward() const; //drukuje zawarto�� listy od ostatniego do pierwszego elementu

    //metody kolejki
    int count() const; //zwraca rozmiar kolejki
    void push(int n); //wpycha element o warto�ci n na koniec kolejki
    void pop(); //wyci�ga pierwszy element z kolejki
    void print_queue() const; //drukuje zawarto�� kolejki (od przodu do ostatnio dodanego elementu)
    void garbage_soft(); //wpisuje warto�� 0 do wszystkich element�w listy kt�re nie nale�� do kolejki
    void garbage_hard(); //usuwa z listy wszystkie elementy, kt�re nie nale�� do kolejki

};

