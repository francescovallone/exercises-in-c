#include <stdio.h>
#include <stdlib.h>
#include "poly.h"
#define max(a,b) ((a) > (b)) ? (a) : (b)

poly poly_init(int degree, double* coeffs){
	poly temp = malloc(sizeof(struct poly));
	temp->degree = degree;
	temp->coeff = malloc((degree+1)*sizeof(double));
	for(int i = 0; i<degree; i++){
		temp->coeff[i] = coeffs[i];
	}
	return temp;
}


poly sum_poly(poly a, poly b){
	int max_degree = max(a->degree, b->degree);
	double* coeffs = malloc((max_degree+1)*sizeof(double));
	for(int i = 0; i<= a->degree; i++){
		coeffs[i] += a->coeff[i];
	}
	for(int i = 0; i<= b->degree; i++){
		coeffs[i] += b->coeff[i];
	}
	poly c = poly_init(max_degree, coeffs);
	free(coeffs);
	return c;
}


poly mul_poly(poly a, poly b){
	int degree = a->degree + b->degree;
	double *coeffs = malloc((degree+1)*sizeof(double));
	for(int i = 0; i <= a->degree; i++){
		for(int j = 0; j <= b->degree; j++){
			coeffs[i+j] += a->coeff[i] * b->coeff[j];
		}
	}
	poly c = poly_init(degree, coeffs);
	free(coeffs);
	return c;
}

void print_poly(poly a){
	for(int i = a->degree; i >= 0; i--)
	{
		if(a->coeff[i])
		{
			printf("%+.2f", a->coeff[i]);
			if(i >= 1) printf("x");
			if(i > 1) printf("^%d", i);
		}
	}
}

void free_poly(poly a){
	free(a->coeff);
	free(a);
}