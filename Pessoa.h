#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

#include <iostream>
using namespace std;

class Pessoa{
public:
	Pessoa();
	Pessoa(const Pessoa&);
	Pessoa(string);
	Pessoa(int);
	~Pessoa();
	virtual const Pessoa& operator = (const Pessoa&);
	virtual ostream& operator << (const Pessoa&);
protected:
	int id;
	void mostrarDetalhes() const;
private:
	static int numeroPessoas;
	string nome;
};

#endif // PESSOA_H
