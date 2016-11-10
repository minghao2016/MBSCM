#if !defined(DEQUE_NUMERIC)
#define DEQUE_NUMERIC	


bool compare(deque<double> & one, deque<double> & two) {

	
	if (one.size()!=two.size())
		return false;
	
	for (int i=0; i<int(one.size()); i++) {
		
		if (fabs(one[i] - two[i]) > 1e-7)
			return false;
	}

	
	return true;


}

double Euclidean_norm(const deque<double> & a) {

	
	double norm=0;
	for(int i=0; i<int(a.size()); i++) {
		norm+=a[i]*a[i];
	}
	
	return sqrt(norm);


}



int Euclidean_normalize(deque<double> & a) {

	
	double norm=Euclidean_norm(a);
	for(int i=0; i<int(a.size()); i++) {
		a[i]/=norm;
	}
	
	return 0;


}



double scalar_product(deque<double> & a, deque<double> & b) {

	
	
	



	double norm=0;
	for(int i=0; i<int(a.size()); i++) {
		norm+=a[i]*b[i];
	}
	
	

	return norm;




}



int orthogonalize(deque<double> & a, deque<deque<double> > & M) {

	Euclidean_normalize(a);
	

	
	for(int i=0; i<int(M.size()); i++) {
	
		
		double w= scalar_product(a, M[i]);
		
		for(int j=0; j<int(a.size()); j++)
			a[j]-=w*M[i][j];
		
	
	}
	
	Euclidean_normalize(a);
	
		
	return 0;

}



int matrix_time_vector(deque<deque<double> > & Q, deque<double> & v, deque<double> & new_s) {

	
	new_s.clear();
	
	for(int i=0; i<int(Q.size()); i++) {
		
		double n=0;
		for(int j=0; j<int(Q[i].size()); j++)
			n+=Q[i][j] * v[j];
		
		new_s.push_back(n);
	
	
	
	}


	return 0;
	
}


void set_to_deque(const set<int> & s, deque<int> & a) {
	
	a.clear();
	
	for(set<int>::iterator its=s.begin(); its!=s.end(); its++)
		a.push_back(*its);

}


void set_to_deque(const set<double> & s, deque<double> & a) {
	
	a.clear();
	
	for(set<double>::iterator its=s.begin(); its!=s.end(); its++)
		a.push_back(*its);

}


void deque_to_set(const deque<double> & a, set<double> & s) {

	s.clear();
	for(int i=0; i<int(a.size()); i++)
		s.insert(a[i]);



}

void deque_to_set(const deque<int> & a, set<int> & s) {

	s.clear();
	for(int i=0; i<int(a.size()); i++)
		s.insert(a[i]);



}



void deque_to_set_app(const deque<int> & a, set<int> & s) {

	for(int i=0; i<int(a.size()); i++)
		s.insert(a[i]);



}




double norm_one(const deque<double> & a) {

	
	double norm=0;
	for(int i=0; i<int(a.size()); i++) {
		norm+=a[i];
	}
	
	return norm;


}



int normalize_one(deque<double> & a) {

	
	double norm=norm_one(a);
	for(int i=0; i<int(a.size()); i++) {
		a[i]/=norm;
	}
	
	return 0;


}



double jaccard(set<int> & a1,  set<int> & a2) {

	deque<int> group_intsec;
	deque<int> group_union;
	set_intersection(a1.begin(), a1.end(), a2.begin(), a2.end(), back_inserter(group_intsec));
	set_union(a1.begin(), a1.end(), a2.begin(), a2.end(), back_inserter(group_union));
	
	return double(group_intsec.size())/group_union.size();



}







#endif

