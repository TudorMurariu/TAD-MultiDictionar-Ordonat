#include "TestScurt.h"

using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	MDO dictOrd = MDO(relatie1);
	assert(dictOrd.dim() == 0);
	assert(dictOrd.vid());
    dictOrd.adauga(1,2);
    dictOrd.adauga(1,3);
    assert(dictOrd.dim() == 2);
    assert(!dictOrd.vid());
    vector<TValoare> v= dictOrd.cauta(1);
    assert(v.size()==2);
    v= dictOrd.cauta(3);
    assert(v.size()==0);
    IteratorMDO it = dictOrd.iterator();
    it.prim();
    while (it.valid()){
    	TElem e = it.element();
        //cout << e.first << " " << e.second << endl;
    	it.urmator();
    }
    assert(dictOrd.sterge(1, 2) == true);
    assert(dictOrd.sterge(1, 3) == true);
    assert(dictOrd.sterge(2, 1) == false);
    assert(dictOrd.vid());
}

void new_test()
{
    MDO d = MDO(relatie1);
    d.adauga(3, 3);
    d.adauga(1, 1);
    d.adauga(3, 2);
    d.adauga(3, 1);
    d.adauga(2, 7);
    d.adauga(2, 23);

    int i = 0;
    IteratorValori it(d, 3);
    it.prim();

    while (it.valid())
    {
        //cout << it.element() << " \n";
        it.urmator();
        i++;
    }

    assert(i == 3);

    i = 0;
    IteratorValori it1(d, 2);
    it1.prim();

    while (it1.valid())
    {
        //cout << it1.element() << " \n";
        it1.urmator();
        i++;
    }

    assert(i == 2);


    IteratorValori it2(d, 1);
    it2.prim();
    assert(it2.element() == 1);

}

