#include <iostream>
#include "Robocop.h"

using namespace std;

int main(){
	Robocop robocop1;
	Robocop robocop2(robocop1);
	Robocop robocop3 = robocop2;

	string array[1];
	Robocop robocop4(*array);
	Robocop robocop5(50.0);
	//Pessoa* p1 = new Robocop();
	//Robocop* robocop6 = (Robocop*) p1;

	robocop1.falar("Ola!");
	robocop1.correr(55.0);
	robocop2.correr();
	robocop4.falar(robocop4.getDiretivaPadrao());
	robocop3.correr(85.0);
	robocop5.correr(20.0);
	robocop5.falar(robocop5.getDiretivaPadrao());

	robocop1.mostrarDetalhes();
	robocop1.olharDireita();
	
	robocop2.mostrarDetalhes();
	robocop2.olharDireita();
	
	robocop3.mostrarDetalhes();
	robocop3.olharEsquerda();
	
	robocop4.mostrarDetalhes();
	robocop4.olharEsquerda();
	
	robocop5.olharDireita();
	robocop5.mostrarDetalhes();
	
	cout << "Numero de Robocops: " << Robocop::getNumeroInstancias() << endl;

	/*
	robocop6->falar("Ola. Agora sou um Robocop.");
	robocop6->olharDireita();
	robocop6->correr();
	robocop6->mostrarDetalhes();
	*/
	return 0;
}
