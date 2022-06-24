#include <iostream>
#include <ctime>
using namespace std;

struct Tree {
    int x;
    Tree* Left=NULL;
    Tree* Right=NULL;
    Tree(int a) {
        this->x = a;
        this->Left = NULL;
        this->Right = NULL;
    }
    Tree(Tree* a) {
        this->x = a->x;
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

void Show(Tree* T,int s) {
    if (T != NULL) {
        Show(T->Left,s+4);
        for (int i = 0; i < s; i++)
            cout << " ";
        cout << T->x <<endl;
        Show(T->Right,s+4);
    }
}

void Shows(Tree* T) {
    cout << "Вывод дерева:" << endl;
    Show(T,0);
    cout << endl;
}

Tree* CreateTree(Tree* T) {
    int n;
    cout << "Количество вершин: "; cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        x = rand() % 20;
        cout << "x >> " << x << endl;
        T=Init(T, x);
        //Shows(T);
    }
    return T;
}

Tree* Mirror(Tree* A, Tree* B) {
    if (A != NULL) {
        B = new Tree(A);
        B->Left = Mirror(A->Right, B->Left);
        B->Right = Mirror(A->Left, B->Right);
    }
    else {
        return NULL;
    }
    return B;
}

Tree* Mirror(Tree* A) {
    Tree* B = NULL;
    B=Mirror(A, B);
    return B;
}

int main()
{
    setlocale(LC_ALL, "russia");
    srand(time(NULL));
    Tree* T = NULL;
    T=CreateTree(T);
    Shows(T);
    Tree* T2 = NULL;
    T2 = Mirror(T, T2);
    Shows(T2);
}
