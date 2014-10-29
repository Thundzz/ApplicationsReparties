
//gsoap annuaire service name: annuaire
//gsoap annuaire service namespace: http://dept-info.labri.fr/~denis/annuaire.wsdl
//gsoap annuaire service location: http://localhost:18083/annuaire/

typedef struct entry{
	char* name;
} entry;

int annuaire__add(entry e, int*result);

int annuaire__search(entry e, int*result);