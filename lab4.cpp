// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include "Tree.h"

int main()
{
    Tree<int>tree;
    tree.insert(2);
    tree.insert(4);
    tree.insert(1);
    tree.insert(12);
    tree.insert(7);
    tree.insert(0);
    tree.insert(24);
    tree.insert(23);
    tree.insert(22);
    tree.insert(15);
    tree.insert(17);
    tree.insert(19);
    tree.print();
    tree.clear();
    std::cout << "\n";
    Tree<char>tree2;
    tree2.insert('a');
    tree2.insert('q');
    tree2.insert('a');
    tree2.insert('b');
    tree2.insert('c');
    tree2.insert('z');
    tree2.insert('2');
    tree2.insert('4');
    tree2.print();
    return 0;
}

