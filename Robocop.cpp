#include <iostream>
#include "Robocop.h"

using namespace std;

const double Robocop::VELOCIDADE_MAXIMA = 130.0;
int Robocop::numeroInstancias = 0;
const double Robocop::FORCA_MAXIMA = 2000.0;
const string Robocop::DIRETIVA_PADRAO = "Nunca devo desobedecer as ordens do comando.";

Robocop::Robocop(){// : Pessoa(){
	dataTransformacao = new Data();
	idOriginal = ++numeroInstancias;
	initDiretivas();
	velocidade = 0.0;
}

Robocop::Robocop(const Robocop &robocop){// : Pessoa(){
	//robocop = new Robocop();
	dataTransformacao = robocop.dataTransformacao;
	for(int i = 0; i < robocop.getNumeroDiretivas(); i++){
		diretivas[i] = robocop.diretivas[i];
	}
	velocidade = robocop.velocidade;
}

Robocop::Robocop(int ID){// : Pessoa(){
	dataTransformacao = new Data();
	setIDOriginal(ID);
	initDiretivas();
	velocidade = 0.0;
}

Robocop::Robocop(double velAtual){// : Pessoa(){
	dataTransformacao = new Data();
	idOriginal = ++numeroInstancias;
	initDiretivas();
	velocidade = velAtual;
}
/*
Robocop& Robocop::operator = (const Robocop& outro){
	dataTransformacao = outro.dataTransformacao;
	idOriginal = ++numeroInstancias;
	for(int i = 0; i < numeroDiretivas; i++){
		diretivas[i] = outro.diretivas[i];
	}
	velocidade = outro.velocidade;
	return *this;
}

ostream& Robocop::operator << (const Robocop& cop){
	return cout << cop.idOriginal;
}
*/
Robocop::Robocop(string &conjuntoDiretivas, string diretPadrao){// : Pessoa(){
	dataTransformacao = new Data();
	idOriginal = ++numeroInstancias;
	initDiretivas();
	setDiretivas(conjuntoDiretivas);
	velocidade = 0.0;
}

Robocop::~Robocop(){
	numeroInstancias--;
	delete dataTransformacao;
	//delete [] diretivas;
	//delete vetor;
}

void Robocop::initDiretivas(){
	for(unsigned int i = 0; i < diretivas->size(); i++){
		this->diretivas[i] = "Reprogramar.";
	}
}

void Robocop::setDataTransformacao(Data* data){
	dataTransformacao = data;
}

Data* Robocop::getDataTransformacao() const {
	return dataTransformacao;
}

void Robocop::setIDOriginal(int id){
	idOriginal = id;
	numeroInstancias++;
}

int Robocop::getIDOriginal() const {
	return idOriginal;
}

string Robocop::getDiretivaPadrao() const {
	return DIRETIVA_PADRAO;
}

double Robocop::getVelocidadeMax() {
	return VELOCIDADE_MAXIMA;
}

void Robocop::setNumeroDiretivas(int numDiretivas){
	if(numDiretivas > 0 && numDiretivas > (int) diretivas->size()){
		numeroDiretivas = numDiretivas;
	}
	else{
		numeroDiretivas = (int) diretivas->size();
	}
}

int Robocop::getNumeroDiretivas() const {
	return numeroDiretivas;
}

void Robocop::setDiretivas(string& conjuntoDiretivas){
	for(unsigned int i = 0; i < conjuntoDiretivas.size(); i++){
		diretivas[i] = conjuntoDiretivas[i];
	}
}

string* Robocop::getDiretivas(){
	return diretivas;
}

void Robocop::setVelocidade(double vel){
	if(vel > 0 && vel < VELOCIDADE_MAXIMA){
		velocidade = vel;
	}
	else{
		velocidade = VELOCIDADE_MAXIMA;
	}
}

double Robocop::getVelocidade() const {
	return velocidade;
}

int Robocop::getNumeroInstancias(){
	return Robocop::numeroInstancias;
}

void Robocop::correr(){
	cout << "Aumentando velocidade do Robocop " << getIDOriginal() << " em 10 Km/h...\n" << endl;
	setVelocidade(velocidade + 10.0);
	cout << "A velocidade atual do Robocop " << getIDOriginal() << " eh: " << getVelocidade() << " Km/h...\n" << endl;
}

void Robocop::correr(double vel){
	cout << "Aumentando velocidade do Robocop " << getIDOriginal() << " em " << vel << " Km/h...\n" << endl;
	setVelocidade(velocidade + vel);
	cout << "A velocidade atual do Robocop " << getIDOriginal() << " eh: " << getVelocidade() << " Km/h...\n" << endl;
}

void Robocop::olharDireita() const {
	cout << "O Robocop " << getIDOriginal() << " olhou para a direita.\n" << endl;
}

void Robocop::olharEsquerda() const {
	cout << "O Robocop " << getIDOriginal() << " olhou para a esquerda.\n" << endl;
}

void Robocop::mostrarDetalhes() const {
	//Pessoa::mostrarDetalhes();
	cout << "Robocop ID: " << getIDOriginal() << "\n"
	<< "Velocidade atual: " << getVelocidade() << "\n"
	<< "Velocidade maxima: " << getVelocidadeMax() << "\n"
	<< "Numero de diretivas: " << getNumeroDiretivas() << "\n"
	<< "Diretiva padrao: " << getDiretivaPadrao() << "\n"
	<< endl;
}

void Robocop::parar(){
	setVelocidade(0.0);
}
/*
Robocop& Robocop::transformar(const Pessoa& pessoa){
	int id = pessoa.id;
	pessoa = new Robocop(id);
	Robocop* robo = (Robocop) pessoa;
	vetorRobocopsTransformados->push_back(robo);
	return pessoa;
}
*/