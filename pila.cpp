#include <iostream>
class pila {
	public:
		int elem[10];
		int *top = elem;
		bool push(int a){
			if (top < elem+10){
				*top = a;
				top++;
				return true;
			}
			else {
				return false;
			}
		}
		bool pop(int& a){
			if (top > elem){
				top--;
				a = *top;
				return 1;
			}
			else 
				return 0;
		}
		void print(){
			int* rec = elem;
			while(rec < top){
				std::cout<<"el valor es: " << *rec<< "\n";
				rec++;
			}
		}
		
};
int main (){
	int valor;
	pila prueba;
	prueba.push(1);
	prueba.push(2);
	prueba.push(3);
	prueba.push(4);
	prueba.push(5);
	prueba.push(6);
	prueba.push(7);
	prueba.push(8);
	prueba.push(9);
	prueba.push(10);

	prueba.print();

	prueba.pop(valor);
	prueba.print();
	std::cout<<"el valor eliminado fue: " << valor << "\n";

	return 0;
}
