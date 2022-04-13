#pragma once

#include <vector>

typedef int TCheie;
typedef int TValoare;


// Lista inlantuita de val

class NodVal;

//se defineste tipul PNod ca fiind adresa unui Nod
typedef NodVal* PNodVal;

class NodVal
{
public:
	friend class IteratorMDO;
	friend class MDO;
	//constructor
	NodVal();
	NodVal(TValoare e, PNodVal urm, PNodVal pre);
	TValoare element();
	PNodVal urmator();
	PNodVal precedent();

private:

	TValoare e;
	PNodVal urm;
	PNodVal pre;
};



#include <utility>
typedef std::pair<TCheie, TValoare> TElem;
typedef std::pair<TCheie, PNodVal> TElem_new;

using namespace std;

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);

/// Lista de perechi

class Nod;

//se defineste tipul PNod ca fiind adresa unui Nod
typedef Nod* PNod;

class Nod
{
public:
	friend class IteratorMDO;
	friend class MDO;
	//constructor
	Nod(TElem_new e, PNod urm, PNod pre);
	TElem_new element();
	PNod urmator();
	PNod precedent();

private:

	TElem_new e;
	PNod urm;
	PNod pre;
};

class MDO {
	friend class IteratorMDO;
    private:
		PNod Inceput;
		Relatie rel;
		int len;
    public:

	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile in ordine in raport cu relatia de ordine
	IteratorMDO iterator() const;

	// destructorul 	
	~MDO();

};
