#include "Pessoa.h"

#include <string>
using std::string;

#include <iostream>
using namespace std;

int Pessoa::numeroPessoas = 0;

Pessoa::Pessoa() : id(++numeroPessoas){
	this->nome = "Sem nome";
}

Pessoa::Pessoa(const Pessoa& pessoa) : id(++numeroPessoas){
	this->nome = pessoa.nome;
}

Pessoa::Pessoa(string nome) : id(++numeroPessoas){
	this->nome = nome;
}

Pessoa::Pessoa(int iD) : id(iD){
	this->nome = "Sem nome";
}

Pessoa::~Pessoa(){
	numeroPessoas--;
}

const Pessoa& Pessoa::operator = (const Pessoa& pessoa){
	this->nome = pessoa.nome;
	return *this;
}

ostream& Pessoa::operator << (const Pessoa& pessoa){
	return cout << "A pessoa " << pessoa.nome << " foi criada.\n";
}

void Pessoa::mostrarDetalhes() const{
	cout << "ID da Pessoa: " << this->id << "\n"
	<< "Nome da Pessoa: " << this->nome << "\n"
	<< endl;
}
