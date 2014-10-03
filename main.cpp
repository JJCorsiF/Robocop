#include <iostream>
#include "Robocop.h"

using namespace std;

int main(){
	Robocop robocop1;
	
	Robocop robocop2(robocop1);
	
	Robocop robocop3 = robocop2;
	string array[1];
	Robocop robocop4(*array);
	
	robocop1.falar("Ola!");
	robocop1.correr(55.0);
    robocop2.correr();
	robocop4.falar(robocop4.getDiretivaPadrao());
    robocop3.correr(85.0);
	
	robocop1.mostrarDetalhes();
	robocop1.olharDireita();
	robocop2.mostrarDetalhes();
	robocop2.olharDireita();
	robocop3.mostrarDetalhes();
	robocop3.olharEsquerda();
	robocop4.olharEsquerda();
	robocop4.mostrarDetalhes();
	
	cout << "Numero de Robocops: " << Robocop::getNumeroInstancias() << endl;
	
	return 0;
}
