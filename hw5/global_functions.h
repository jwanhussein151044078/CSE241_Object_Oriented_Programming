# ifndef global_functions_H_
# define global_functions_H_

# include <iostream>
# include <vector>
# include "SHAPE.h"
# include "POLYGON.h"
# include "POLYGONVECT.h"
using namespace std;
namespace jwan_{
	
	ostream& operator <<(ostream& outputStream,SHAPE& a);
	void printAll(ostream& outputStream,const vector<SHAPE*> v);
	void printPoly(ostream& outputStream,const vector<SHAPE*>& v);
	vector<POLYGON*> convertAll(const vector<SHAPE*>& v);
	void sortShapes(vector<SHAPE*>& v);


}

#endif /* global_functions_H_ */