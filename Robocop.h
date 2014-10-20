/**
 * A classe Robocop terá um ID para identificar que pessoa foi transformada em ciborgue, métodos para olhar para a esquerda ou direita, correr, parar e até falar.
 * 
 * Lista de Requisitos:
 *  Pelo menos 4 atributos - OK
 *  Pelo menos 4 funções membro sem incluir getters e setters - OK
 *  Todos os atributos devem ser inicializados - OK
 *  Três construtores, incluindo um construtor de cópia e construtor com parâmetros default - OK
 *  Deve ter um atributo string - OK
 *  Um atributo static - OK
 *  Um atributo const static - OK
 *  Dois métodos constantes (não pode ser get) - OK
 *  Um array - OK
 *  Uma função inline (não pode ser get ou set) - OK
 *  Método com passagem por referência usando ponteiro - OK
 *  Método static - deve ser chamado no main - OK
 *  Relacionar a classe "Data" - OK
 *  Criar duas classes relacionadas - OK
 *  Alocação dinâmica de memória - OK
 *  Friend - OK
 *  Operator << - OK
 *  Operator = - OK
 *  vector push_back - ??
 * 
 * Atributos:
 * 
 * Data dataTransformacao; //Data da transformação em ciborgue
 * int idOriginal; //ID original da Pessoa que foi transformada em ciborgue
 * static int numeroInstancias; //numero de Pessoas transformadas em ciborgues
 * double velocidade; //velocidade atual do ciborgue
 * static double velocidadeMaxima; //velocidade máxima do ciborgue
 * string diretivaPadrao; //diretiva padrão do ciborgue
 * static const string nome; //nome do ciborgue
 * int numeroDiretivas; //quantidade de diretivas conhecidas pelo ciborgue
 * string diretivas[1000]; //as diretivas conhecidas por ele
 * 
 * Métodos:
 * 
 * friend ostream operator << (ostream&, const Robocop&); //operador << friend
 * 
 * //CONSTRUTORES:
 * Robocop();
 * Robocop(const Robocop&); //Construtor de cópia
 * Robocop(double);
 * Robocop(string&, string = "Nunca devo desobedecer as ordens do comando.");
 * 
 * ~Robocop(); //Destrutor
 * 
 * Robocop& operator = (const Robocop&); //Operator=
 * 
 * inline void falar(string); //fala algo
 * void correr(); //velocidade sobe em 10 km/h
 * void correr(double); //corre, dado uma certa aceleração
 * void olharDireita() const; //olha para a direta
 * void olharEsquerda() const; //olha para a esquerda
 * void mostrarDetalhes() const; //exibe as informações do ciborgue
 * void parar(); //para de correr
 * void initDiretivas(); //inicializa o array diretivas
 * 
 * //GETTERS:
 * Data& getDataTransformacao() const;
 * int getIDOriginal() const;
 * string getDiretivaPadrao() const;
 * static double getVelocidadeMax();
 * int getNumeroDiretivas() const;
 * string* getDiretivas();
 * double getVelocidade() const;
 * static int getNumeroInstancias();
 * 
 * //SETTERS:
 * void setDataTransformacao(Data*);
 * void setIDOriginal(int);
 * void setDiretivaPadrao(string);
 * static void setVelocidadeMax(double);
 * void setNumeroDiretivas(unsigned int);
 * void setDiretivas(string&);
 * void setVelocidade(double);
*/

#include <iostream>
using namespace std;

#include <string>
using std::string;

#include "Data.h"
using namespace std;

#include "Pessoa.h"
using namespace std;

#ifndef ROBOCOP_H
#define ROBOCOP_H

class Robocop : public Pessoa{ //Relacionada (herança) da classe Pessoa
	friend ostream& operator << (ostream &saida, const Robocop& robo){
		saida << "Robocop ID: " << robo.idOriginal << "\n"
		<< "Velocidade maxima: " << robo.velocidadeMaxima << "\n"
		<< "Numero de diretivas: " << robo.numeroDiretivas << "\n";
		return saida;
	}
public:
	Robocop();
	Robocop(const Robocop&); //construtor de cópia
	Robocop(double);
	Robocop(string&, string = "Nunca devo desobedecer as ordens do comando.");
	~Robocop();
	Robocop& operator = (const Robocop&); //operator =
	Data* getDataTransformacao() const;
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
	void parar();
private:
	//4 atributos
	Data* dataTransformacao; //Composição com a classe "Data"
	int idOriginal;
	static int numeroInstancias; //1 atributo static
	double velocidade;
	static double velocidadeMaxima;
	string diretivaPadrao; //um atributo string
	static const string nome; // 1 atributo static const
	int numeroDiretivas;
	string diretivas[1000]; //1 array
	void initDiretivas();
	void setDataTransformacao(Data*);
	void setIDOriginal(int);
	void setDiretivaPadrao(string);
	static void setVelocidadeMax(double);
	void setNumeroDiretivas(unsigned int);
	void setDiretivas(string&); //1 método com passagem referência usando ponteiro
	void setVelocidade(double);
};

#endif // ROBOCOP_H
