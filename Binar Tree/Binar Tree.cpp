#include <iostream>
#include <ctime>
using namespace std;

struct Tree {
    int x;
    Tree* Left=NULL;
    Tree* Right=NULL;
    Tree(int a) { // Конструктор
        this->x = a;
        this->Left = NULL;
        this->Right = NULL;
    }
    Tree(Tree* a) { // Конструктор
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

Tree* CreateTree(Tree* T) {
    int n;
    cout << "Количество вершин: "; cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        //cout << "x >> ";
        //cin >> x;
        x = rand() % 20;
        T=Init(T, x);
        //Shows(T);
    }
    return T;
}


void Show(Tree* T, int s) {
    if (T != NULL) {
        Show(T->Right, s + 4);
        for (int i = 0; i < s; i++)
            cout << " ";
        cout << T->x << endl;
        Show(T->Left, s + 4);
    }
}

void Shows(Tree* T) {
    cout << "\nВывод дерева:" << endl;
    Show(T, 0);
    cout << endl;
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

int Height(Tree* T,int h, int n) { // Даем ссылку на первую вершину - T,
    //h - высота дерева, n - нужная высота

    if (T != NULL) {
        if (h == n)
            return 1;

        int a = 0;
        a += Height(T->Left, h + 1, n); // Переходим в левую ветвь и добавляем ему высоту
        a += Height(T->Right, h + 1, n); // Так же в правую
        return a;
    }
    else {
        return 0;
    }
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
    int n;
    cout << "n >> "; cin >> n;
    while (n != 0) {
        cout << "\nКоличество вершин на уровне " << n << ": " << Height(T, 1, n) << endl;
        cout << "n >> "; cin >> n;
    }
}
