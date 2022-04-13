#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;

/// Teta(1)
NodVal::NodVal() {
	this->pre = nullptr;
	this->urm = nullptr;
	this->e = 0;
}

/// Teta(1)
NodVal::NodVal(TValoare e, PNodVal urm, PNodVal pre) {
	/// constructor
	this->e = e;
	this->urm = urm;
	this->pre = pre;
}

/// Teta(1)
TValoare NodVal::element() {
	return e;
}

/// Teta(1)
PNodVal NodVal::urmator() {
	return urm;
}

/// Teta(1)
PNodVal NodVal::precedent() {
	return this->pre;
}


/// Teta(1)
Nod::Nod(TElem_new e, PNod urm, PNod pre) {
	/// constructor
	this->e = e;
	this->urm = urm;
	this->pre = pre;
}

/// Teta(1)
TElem_new Nod::element() {
	return e;
}

/// Teta(1)
PNod Nod::urmator() {
	return urm;
}

/// Teta(1)
PNod Nod::precedent() {
	return this->pre;
}

/// Teta(1)
MDO::MDO(Relatie r) {
	/// constructor , setam inceputul cu null
	this->Inceput = NULL;
	this->len = 0;
	this->rel = r;
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
void MDO::adauga(TCheie c, TValoare v) {

	this->len++;
	/// daca lista e vida definim un nod de inceput in care ne punem elementele

	if (this->Inceput == NULL)
	{
		PNodVal pval = new NodVal(v, nullptr, nullptr);
		TElem_new e;
		e.first = c;
		e.second = pval;
		PNod newp = new Nod(e, nullptr, nullptr);
		this->Inceput = newp;
		return;
	}

	PNod aux1 = this->Inceput;
	PNod aux2 = this->Inceput->urm;

	// testam sa vedem daca elementul trebuie pus la inceput

	if (c == aux1->e.first) // daca cheia exista deja
	{
		PNodVal pval = new NodVal(v, nullptr, nullptr);
		pval->urm = aux1->e.second;
		aux1->e.second->pre = pval;
		aux1->e.second = pval;
		return;
	}

	if (this->rel(c, aux1->e.first))
	{
		PNodVal pval = new NodVal(v, nullptr, nullptr);
		TElem_new e;
		e.first = c;
		e.second = pval;
		PNod newp = new Nod(e, nullptr, nullptr);
		newp->urm = this->Inceput;
		this->Inceput = newp;
		return;
	}

	// iteram prin lista cautand elementul

	while (aux2 != NULL)
	{
		if (c == aux2->e.first) // daca cheia exista deja
		{
			PNodVal pval = new NodVal(v, nullptr, nullptr);
			aux2->e.second->pre = pval;
			pval->urm = aux2->e.second;
			aux2->e.second = pval;
			return;
		}

		// unde relatia este satisfacuta acolo trebuie pus elementul
		if (this->rel(c, aux2->e.first))
		{
			PNodVal pval = new NodVal(v, nullptr, nullptr);
			TElem_new e;
			e.first = c;
			e.second = pval;
			PNod newp = new Nod(e, nullptr, nullptr);
			newp->urm = aux2;
			newp->pre = aux1;
			aux1->urm = newp;
			aux2->pre = newp;
			return;
		}

		aux1 = aux1->urm;
		aux2 = aux2->urm;
	}

	// daca iesim din while elementul trebuie pus la finalul listei
	PNodVal pval = new NodVal(v, nullptr, nullptr);
	TElem_new e;
	e.first = c;
	e.second = pval;
	PNod newp = new Nod(e, nullptr, nullptr);
	newp->pre = aux1;
	aux1->urm = newp;
	return;
}


/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
vector<TValoare> MDO::cauta(TCheie c) const {
	//cauta o cheie si returneaza vectorul de valori asociate

	vector<TValoare> v;
	PNod aux1 = this->Inceput;

	while (aux1 != NULL)
	{
		if (c == aux1->e.first)
		{
			PNodVal aux2 = aux1->e.second;

			while (aux2 != NULL)
			{
				v.push_back(aux2->e);
				aux2 = aux2->urm;
			}
			return v;
		}

		aux1 = aux1->urm;
	}

	return v;
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
bool MDO::sterge(TCheie c, TValoare v) {

	// cautam dupa cheie apoi dupa valoare

	if (this->Inceput == NULL)
		return false;

	PNod aux = this->Inceput;
	PNod auxA = this->Inceput->urm;

	if (c == aux->e.first)
	{
		PNodVal aux1 = aux->e.second;
		PNodVal aux2 = aux1->urm;

		// verificam daca prima val este cea cautata
		if (v == aux1->e)
		{
			this->Inceput->e.second = this->Inceput->e.second->urm;
			if (this->Inceput->e.second == NULL) // daca este null atunci stergem cheia din dictionar
			{
				this->Inceput = this->Inceput->urm;
			}
			this->len--;
			return true;
		}

		while (aux2 != NULL)
		{
			if (v == aux2->e)
			{
				aux1->urm = aux2->urm;
				if (aux1->urm != NULL)
					aux2->urm->pre = aux1;
				this->len--;
				return true;
			}
			aux1 = aux1->urm;
			aux2 = aux2->urm;
		}
		return false;
	}

	while (auxA != NULL)
	{
		if (c == auxA->e.first)
		{
			PNodVal aux1 = auxA->e.second; 
			PNodVal aux2 = aux1->urm;
			
			// verificam daca prima val este cea cautata
			if (v == aux1->e)
			{
				auxA->e.second = auxA->e.second->urm;
				if (auxA->e.second == NULL) // daca este null atunci stergem cheia din dictionar
				{
					aux->urm = auxA->urm;
					if (aux->urm != NULL)
						aux->urm->pre = aux;
				}
				this->len--;
				return true;
			}

			while (aux2 != NULL)
			{
				if (v == aux2->e)
				{
					aux1->urm = aux2->urm;
					if (aux1->urm != NULL)
						aux2->urm->pre = aux1;
					this->len--;
					return true;
				}
				aux1 = aux1->urm;
				aux2 = aux2->urm;
			}

			return false;
		}

		aux = aux->urm;
		auxA = auxA->urm;
	}
	
	return false;
}

/// Teta(1)
int MDO::dim() const {
	// returnam dimensiunea
	return this->len;
}

/// Teta(1)
bool MDO::vid() const {
	// returnam adevarat daca dictionarul este vid
	return this->len == 0;
}

/// Teta(1)
IteratorMDO MDO::iterator() const {
	// se returneaza iterator pe dictionar
	return IteratorMDO(*this);
}

/// Teta(n)
MDO::~MDO() {
	/// trecem prim toate elementele ramase in lista pentru a le sterge din memorie
	while (this->Inceput != nullptr)
	{
		PNod p = this->Inceput;
		this->Inceput = this->Inceput->urm;
		delete p;
	}
}
