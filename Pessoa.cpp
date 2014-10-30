#include "Pessoa.h"

#include <string>
using std::string;

#include <iostream>
using namespace std;

int Pessoa::numeroPessoas = 0;

Pessoa::Pessoa(){
	this->nome = "Sem nome";
	this->id = numeroPessoas++;
}

Pessoa::Pessoa(const Pessoa& pessoa){
	this->nome = pessoa.nome;
	this->id = pessoa.id;
}

Pessoa::~Pessoa(){
	numeroPessoas--;
}
/*
Pessoa& Pessoa::operator = (const Pessoa&){
	//return new Pessoa();
}

ostream& Pessoa::operator << (const Pessoa& pessoa){
	//return cout << "";
}
*/
void Pessoa::mostrarDetalhes() const{
	cout << "ID da Pessoa: " << this->id << "\n"
	<< "Nome da Pessoa: " << this->nome << "\n"
	<< endl;
}
