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

//void new_func_test()
//{
//    MDO d = MDO(relatie1);
//    assert(d.stergeValoriPentruCheie(3).size() == 0);
//    d.adauga(1, 2);
//    d.adauga(1, 3);
//    assert(d.stergeValoriPentruCheie(1).size() == 2);
//    assert(d.vid());
//
//
//    d.adauga(1, 2);
//    d.adauga(1, 3);
//    d.adauga(2, 4);
//    d.adauga(2, 5);
//    d.adauga(3, 100);
//    assert(d.stergeValoriPentruCheie(2).size() == 2);
//    assert(d.dim() == 3);
//}

