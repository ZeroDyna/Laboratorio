#include <iostream>
using namespace std;

class node {
public:
    node* next = nullptr;
    node* prev = nullptr;
    int* valor = nullptr;
    node(int* v = nullptr, node* n = nullptr, node* p = nullptr) : valor(v), next(n), prev(p) {}
};

class Le {
public:
    node* head = nullptr;
    void add(int* arr) {
        if (head == nullptr) {
            head = new node(arr, nullptr, nullptr);
        }
        else {
            node* rec = head;
            while (rec->next) {
                rec = rec->next;
            }
            node* newNode = new node(arr, nullptr, rec);
            rec->next = newNode;
        }
    }
};

class elementor {
public:
    Le map;
    int tam;
    int* ini = nullptr;
    int* fin = nullptr;

    elementor(int t) : tam(t) {}

    void ad(int valor) {
        node* pos = nullptr;
        if (!find(valor, pos)) {
            int* arr = new int[tam]();
            *arr = valor;
            map.add(arr);

            if (ini == nullptr) {
                ini = arr;
            }
            fin = arr;
        }
        else {
            int* arr = pos->valor;
            int i = 0;
            while (i < tam && arr[i] != 0 && arr[i] < valor) {
                i++;
            }

            if (i == tam || (i == 0 && arr[i] == 0)) {
                if (fin == nullptr) {
                    int* newArr = new int[tam]();
                    newArr[0] = valor;
                    fin = newArr;
                    if (ini == nullptr) {
                        ini = newArr;
                    }
                }
                else {
                    *(fin + 1) = valor;
                    fin++;
                }
            }
            else {

                for (int j = tam - 1; j > i; j--) {
                    arr[j] = arr[j - 1];
                }
                arr[i] = valor;

                if (arr == fin && arr[tam - 1] != 0) {
                    fin = new int[tam]();
                    *fin = valor;
                }
                else if (arr == ini && arr[0] != 0) {
                    ini = new int[tam]();
                    *ini = valor;
                }
            }
        }
    }
    bool find(int valor, node*& pos) {
        pos = nullptr;
        node* p = map.head;
        while (p != nullptr) {
            int* arr = p->valor;
            for (int i = 0; i < tam && arr[i] != 0; ++i) {
                if (arr[i] > valor) {
                    pos = p;
                    return true;
                }
            }
            p = p->next;
        }
    }

    void print() {
        node* current = map.head;

        while (current != nullptr) {
            int* arr = current->valor;
            int j = 0;

            while (j < tam && arr[j] != 0) {
                cout << arr[j] << " ";
                j++;
            }

            current = current->next;
        }

        cout << endl;
    }

    void del(int valor) {
        node* current = map.head;


        while (current != nullptr) {
            int* arr = current->valor;
            int i = 0;

            
            while (i < tam && arr[i] != valor) {
                i++;
            }

            
            if (arr[i] == valor) {
                for (int j = i; j < tam - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                arr[tam - 1] = 0;

                if (i == 0 && arr[i] == 0) {
                    if (current->prev == nullptr) {
                        map.head = current->next;
                    }
                    else {
                        current->prev->next = current->next;
                    }
                    if (current->next != nullptr) {
                        current->next->prev = current->prev;
                    }
                    delete[] current->valor;
                    delete current;
                    return;
                }
            }
            current = current->next;
        }
    }
    void print_prim() {
        node* current = map.head;
        int i = 0;
        int* arr = current->valor;
        int j = 0;

        while (j < tam && arr[j] != 0) {
            cout << arr[j] << " ";
            j++;
        }
    }

    ~elementor() {
        node* current = map.head;
        while (current != nullptr) {
            node* temp = current;
            current = current->next;

            delete[] temp->valor;
            delete temp;
        }
    }
};

int main() {
    elementor test(5);
    test.ad(5);
    test.ad(9);
    test.ad(7);
    test.ad(1);
    test.ad(2);
    test.ad(3);
    test.ad(4);
    test.print();
    test.print_prim();
    test.del(1);
    test.del(2);
    test.del(3);
    test.del(4);
    test.del(5);
    test.del(7);
    test.del(9);

    std::cout << "Despues de eliminar:\n";
    test.print();
    return 0;
}
