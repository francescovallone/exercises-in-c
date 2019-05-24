struct poly{
	int degree;
	double *coeff;
};

typedef struct poly* poly;


poly poly_init(int, double*);
poly sum_poly(poly, poly);
poly mul_poly(poly, poly);
void print_poly(poly);
void free_poly(poly);