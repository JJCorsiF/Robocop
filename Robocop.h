/**
 * A classe Robocop terá um ID para identificar que pessoa foi transformada em ciborgue, métodos para olhar para a esquerda ou direita, correr, parar e até falar.
 * 
 * Lista de Requisitos:
 * 
 * Pelo menos 4 atributos - OK
 * Pelo menos 4 funções membro sem incluir getters e setters - OK
 * Todos os atributos devem ser inicializados. Fez validação dos dados? - OK
 * Três construtores, incluindo um construtor de cópia e construtor com parâmetros default - OK
 * Deve ter um atributo string - OK
 * Um atributo static. Correta modelagem dos statics? - OK
 * Um atributo const static - OK
 * Dois métodos constantes (não pode ser get) - OK
 * Um array - OK
 * Uma função inline (não pode ser get ou set) - OK
 * Método com passagem por referência usando ponteiro - OK
 * Método static - deve ser chamado no main - OK
 * Composição com a classe Data. Fez uso do objeto criado? - OK
 * Criar duas classes relacionadas - OK
 * Alocação dinâmica de memória. A memória é desalocada? - OK
 * Friend - OK
 * Operator << - OK
 * Operator = - OK
 * vector push_back - OK
 * Usar o destrutor - OK
 * Verifica alocação dentro do construtor de cópia - OK
 * O que é const deve ser const. - OK
 * Diagrama de classes (obrigatório salvar também o png do diagrama no gitHub)
 * Herança pública - OK
 * Construtor de cópia, e sobrecargas dos operadores de atribuição (=) e << (cout << base) para a classe base e derivada - OK
 * Usar Protected acessando diretamente os atributos na classe derivada - OK
 * Alocação dinâmica de memória na classe base e derivada
 * Sobrescrita de método: chamar dentro do método da classe derivada o método correspondente da classe base usando :: - OK
 * No main: criar um ponteiro da classe base para alocar memória para a classe derivada e chamar os vários métodos implementados - OK
 * 
 * Atributos:
 * 
 * Data dataTransformacao; //Data da transformação em ciborgue
 * vector<Robocop>* vetorRobocopsTransformados; //vetor de Robocops Transformados por este
 * int idOriginal; //ID original da Pessoa que foi transformada em ciborgue
 * static int numeroInstancias; //numero de Pessoas transformadas em ciborgues
 * double velocidade; //velocidade atual do ciborgue
 * static double velocidadeMaxima; //velocidade máxima do ciborgue
 * string diretivaPadrao; //diretiva padrão do ciborgue
 * static const double forcaMaxima; //força máxima de um ciborgue
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
 * Robocop(int);
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
 * Robocop& transformar(Pessoa&);
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

#include <vector>
using std::vector;

#include "Data.h"
using namespace std;

//#include "Pessoa.h"
//using namespace std;

#ifndef ROBOCOP_H
#define ROBOCOP_H

class Robocop{// : public Pessoa{ //Relacionada (herança) da classe Pessoa
	friend ostream& operator << (ostream& saida, const Robocop& robo){
		saida << "Robocop ID: " << robo.idOriginal << "\n"
		<< "Velocidade maxima: " << VELOCIDADE_MAXIMA << "\n"
		<< "Numero de diretivas: " << robo.numeroDiretivas << "\n";
		return saida;
	} //friend operator <<
public:
	Robocop();
	Robocop(const Robocop&); //construtor de cópia
	Robocop(double);
	Robocop(int);
	Robocop(string&, double = 0.0);
	~Robocop();
	//Robocop& operator = (const Robocop&); //operator =
	//ostream& operator << (const Robocop&); //operator <<
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
	vector<Robocop>* vetorRobocopsTransformados; //vector
	int idOriginal;
	static int numeroInstancias; //1 atributo static
	double velocidade;
	static const double VELOCIDADE_MAXIMA;
	static const string DIRETIVA_PADRAO; //um atributo string
	static const double FORCA_MAXIMA; // 1 atributo static const
	int numeroDiretivas;
	string diretivas[1000]; //1 array
	void initDiretivas();
	//Robocop& transformar(const Pessoa&);
	void setDataTransformacao(Data*);
	void setIDOriginal(int);
	void setNumeroDiretivas(int);
	void setDiretivas(string&); //1 método com passagem referência usando ponteiro
	void setVelocidade(double);
};

#endif // ROBOCOP_H
