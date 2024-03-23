#include <iostream>
template <class t>
class enlace {
public:
	t a;
	t* arr[10] = nullptr;
	enlace(t x, t* arr) : a(x), arr(arr) {}
};
template <class t>
struct elementor{

	t* top = nullptr;
	t* rec = arr;
	void add(t valor) {
		t* arr = new t[10];
		*rec = valor;
		top = rec;
		rec++;
		if (top - arr % 9 == 0 && top -arr != 0) {
			t* arr_1 = new t[10];

		}
	}
	void del(t valor) {
		//¿como elimino el contenido de un array (lo puedo remplazar...)
	}
	void print() {
		t* rec_1 = arr;
		while (rec_1 < top) {
			std::cout << "el valor es: " << *rec_1;
			rec_1++;
		}
	}
	void find() {

	}
	elementor(t elem) {}
	~elementor() {}
};
int main() {
	enlace<int> pri(int a = 1);
	enlace<int> seg(int a = 1);
	enlace<int> ter(int a = 1);
	enlace<int> cuar(int a = 1);
	enlace<int> quin(int a = 1);
	elementor<int> prueba(pri);
	return 0;
}
