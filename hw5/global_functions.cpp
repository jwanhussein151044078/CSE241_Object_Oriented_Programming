
# include "global_functions.h"

namespace jwan_{


	ostream& operator <<(ostream& outputStream , SHAPE& a){
		a.print_shape(outputStream);
		return outputStream ;
	}
	void printAll(ostream& outputStream,const vector<SHAPE*> v){
		for (int i =0 ; i < v.size() ; i++){
			outputStream << *v[i] << endl;
		}
	}

	void printPoly(ostream& outputStream,const vector<SHAPE*>& v){
		for(int i =0 ; i < v.size() ; i++){	
			if (v[i]->get_type() == polygon){
				outputStream << *v[i] << endl;
			}
		}
	}

	
	vector<POLYGON*> convertAll(const vector<SHAPE*>& v){
		
	}


	void sortShapes(vector<SHAPE*>& v){
		SHAPE* temp ;
		for (int i = 0 ; i < v.size() ; ++i) {
            for (int j = i + 1 ; j < v.size(); ++j){
                if (v[i]->get_area() > v[j]->get_area()) {
                    temp =  v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
	}

}