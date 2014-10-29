
//gsoap calc service name: calc
//gsoap calc service namespace: http://dept-info.labri.fr/~denis/calc.wsdl
//gsoap calc service location: http://localhost:18083/calc/

int calc__add(double a, double b, double*result);

int calc__sub(double a, double b, double*result);

int calc__sqrt(double a, double*result);

int calc__div(double a, double b, double*result);

int calc__mul(double a, double b, double*result);