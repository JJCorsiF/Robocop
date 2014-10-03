#include <iostream>
using namespace std;

#include <string>
using std::string;

#ifndef ROBOCOP_H
#define ROBOCOP_H

class Robocop{
public:
	Robocop();
	Robocop(const Robocop&); //construtor de cópia
	Robocop(double);
	Robocop(string&, string = "Nunca devo desobedecer as ordens do comando.");
	~Robocop();
	Robocop& operator = (const Robocop&);
	int getIDOriginal() const;
	string getDiretivaPadrao() const;
	static double getVelocidadeMax();
	int getNumeroDiretivas() const;
	string* getDiretivas();
	double getVelocidade() const;
	//4 funções membro
	inline void falar(string frase){
		cout << "O Robocop " << getIDOriginal() << " disse: \"" << frase << "\"\n" << endl;
	}; //1 função inline
	void correr();
	void correr(double);
	static int getNumeroInstancias(); //1 método static
	//2 métodos const
	void olharDireita() const;
	void olharEsquerda() const;
	void mostrarDetalhes() const;
private:
	//4 atributos
	int idOriginal;
	static int numeroInstancias; //1 atributo static
	double velocidade;
	static double velocidadeMaxima;
	string diretivaPadrao; //um atributo string
	static const string nome; // 1 atributo static const
	int numeroDiretivas;
	string diretivas[1000]; //1 array
	void initDiretivas();
	void setIDOriginal(int);
	void setDiretivaPadrao(string);
	static void setVelocidadeMax(double);
	void setNumeroDiretivas(unsigned int);
	void setDiretivas(string&); //1 método com passagem referência usando ponteiro
	void setVelocidade(double);
};

#endif // ROBOCOP_H
