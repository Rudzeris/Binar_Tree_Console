// Binar Tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;

struct Tree {
    int x;
    Tree* Left=NULL;
    Tree* Right=NULL;
    Tree(int a) {
        x = a;
        Left = NULL;
        Right = NULL;
    }
};

Tree* Init(Tree* T,int x) {
    if (T == NULL)
        return new Tree(x);
    if (x < T->x) {
        T->Left = Init(T->Left, x);
    }
    else {
        T->Right = Init(T->Right, x);
    }
    return T;
}

void Show(Tree* T) {
    if (T != NULL) {
        Show(T->Left);
        cout << T->x <<" | ";
        Show(T->Right);
    }
}

void Shows(Tree* T) {
    cout << "Вывод дерева:" << endl;
    Show(T);
    cout << endl;
}

//int Height(Tree* T) {
//    if (T != NULL) {
//        int 
//    }
//    return 0;
//}

void CreateTree() {
    int n;
    cout << "Количество вершин: "; cin >> n;
    Tree* T=NULL;
    int x;
    for (int i = 0; i < n; i++) {
        cout << "x >> "; x = rand() % 20;
        T=Init(T, x);
        Shows(T);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    CreateTree();
}
