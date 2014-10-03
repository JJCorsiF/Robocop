#include <iostream>
#include "Robocop.h"

using namespace std;

double Robocop::velocidadeMaxima = 130.0;
int Robocop::numeroInstancias = 0;
string nome = "Robocop";

Robocop::Robocop(){
	setIDOriginal(++numeroInstancias);
	initDiretivas();
	setDiretivaPadrao("");
	setVelocidade(0.0);
}

Robocop::Robocop(const Robocop &robocop){
	idOriginal = ++numeroInstancias;
	for(int i = 0; i < robocop.getNumeroDiretivas(); i++){
		diretivas[i] = robocop.diretivas[i];
	}
	diretivaPadrao = robocop.diretivaPadrao;
	velocidade = robocop.velocidade;
}

Robocop::Robocop(double velAtual){
	setIDOriginal(++numeroInstancias);
	initDiretivas();
	setDiretivaPadrao(diretivaPadrao);
	setVelocidade(velAtual);
}

Robocop& Robocop::operator = (const Robocop& outro){
	idOriginal = ++numeroInstancias;
	for(int i = 0; i < numeroDiretivas; i++){
		diretivas[i] = outro.diretivas[i];
	}
	diretivaPadrao = outro.diretivaPadrao;
	velocidade = outro.velocidade;
	return *this;
}

Robocop::Robocop(string &conjuntoDiretivas, string diretPadrao){
	setIDOriginal(++numeroInstancias);
	initDiretivas();
	setDiretivas(conjuntoDiretivas);
	setDiretivaPadrao(diretPadrao);
	setVelocidade(0.0);
}

Robocop::~Robocop(){
	
}

void Robocop::initDiretivas(){
	for(unsigned int i = 0; i < diretivas->size(); i++){
		diretivas[i] = "Reprogramar.";
	}
}

void Robocop::setIDOriginal(int id){
	idOriginal = id;
}

int Robocop::getIDOriginal() const {
	return idOriginal;
}

void Robocop::setDiretivaPadrao(string dirPadrao){
	diretivaPadrao = dirPadrao;
}

string Robocop::getDiretivaPadrao() const {
	return diretivaPadrao;
}

void Robocop::setVelocidadeMax(double velMax){
	velocidadeMaxima = velMax;
}

double Robocop::getVelocidadeMax() {
	return velocidadeMaxima;
}

void Robocop::setNumeroDiretivas(unsigned int numDiretivas){
	if(numDiretivas > diretivas->size()){
		numeroDiretivas = numDiretivas;
	}
	else{
		numeroDiretivas = diretivas->size();
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
	if(vel < velocidadeMaxima){
		velocidade = vel;
	}
	else{
		velocidade = velocidadeMaxima;
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
	setVelocidade(velocidade + 10);
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
	cout << "Robocop ID: " << getIDOriginal() << "\n"
	<< "Velocidade atual: " << getVelocidade() << "\n"
	<< "Velocidade maxima: " << getVelocidadeMax() << "\n"
	<< "Numero de diretivas: " << getNumeroDiretivas() << "\n"
	<< "Diretiva padrao: " << getDiretivaPadrao() << "\n"
	<< endl;
}