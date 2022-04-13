#include "IteratorMDO.h"
#include "MDO.h"
#include <exception>

/// Teta(1)
IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
	/// Constructor
	this->p = this->dict.Inceput;
	if (this->p != NULL)
		this->pval = this->p->e.second;
	else
		this->pval = NULL;
}

/// Teta(1)
void IteratorMDO::prim(){
	/// Resetam iteratorul
	this->p = this->dict.Inceput;
}

/// Teta(1)
void IteratorMDO::urmator(){
	/// trecem la urmatorul element din lista
	if(! this->valid())
		throw exception();

	if (this->pval->urm == NULL)
	{
		this->p = this->p->urm;
		if(this->p != NULL)
			this->pval = this->p->e.second;
		return;
	}
	this->pval = this->pval->urm;
}

/// Teta(1)
bool IteratorMDO::valid() const{
	/// Verificam daca iteratorul este valid(element al listei)
	/// Ajunge sa verificam doar daca iteratorul nu este null

	if (this->p == nullptr)
		return false;

	return true;
}

/// Teta(1)
pair <TCheie, TValoare> IteratorMDO::element() const{
	// returnam elementul actual
	if (!this->valid())
		throw exception();

	return pair <TCheie, TValoare>  (this->p->e.first, this->pval->e);
}


