#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAX_ITERATIONS = 6;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/***** Function declarations here. *****/
void print(const mpf_t& pi);

/**
 * The main.
 * Set constants, initialize variables, and iterate
 * to compute pi to the desired number of decimal places.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits
    mpf_t a0,y0,root2,two,constant,four,six,one,y_val,a_val,sub_val,sub_main_val,add_main_val,y_main_val,y_sq,y_add,y_add2,pi,count; //Declaring all variables.
	
	//Initializing all variables.
    mpf_inits(a0);
    mpf_init(y0);
	mpf_init(root2);
	mpf_init(constant);
	mpf_init(y_val);
	mpf_init(a_val);
	mpf_init(sub_val);
	mpf_init(y_main_val);
	mpf_init(y_sq); 
	mpf_init(y_add);
	mpf_init(add_main_val);
	mpf_init(sub_main_val);
	mpf_init(y_add2);
	mpf_init(pi);
	mpf_init(count);

   /*Setting values of constant integers*/
	mpf_init_set_ui (two, 2);
	mpf_init_set_ui (four, 4);
	mpf_init_set_ui (six, 6);
	mpf_init_set_ui (one, 1);
	
	mpf_sqrt(root2,two);              //Calculating value of root 2.
	mpf_mul (constant, four, root2); //Calculating value of 4*root 2
	mpf_sub (a0, six, constant);     //Calculating value of a0
	mpf_sub (y0, root2, one);		//Calculating value of y0

	

	for (int i = 1; i <= MAX_ITERATIONS; i++)
	    {
			
			/*Calculating value of Yn*/
		    mpf_pow_ui (y_val,y0,4);
			mpf_sub (sub_val,one,y_val);
			mpf_sqrt(sub_val,sub_val);
			mpf_sqrt(sub_val,sub_val);
			mpf_sub(sub_main_val,one,sub_val);
			mpf_add(add_main_val,one,sub_val);
			mpf_div(y_main_val,sub_main_val,add_main_val); 
			
			/*Calculating value of An*/
			/*part B*/
			mpf_pow_ui (y_sq,y_main_val,2);
			mpf_add(y_add,y_main_val,y_sq);
			mpf_add(y_add,one,y_add);
			mpf_mul(y_add,y_add,y_main_val);
			mpf_pow_ui(count,two,((2*i)+1));
			mpf_mul(y_add,count,y_add);
			
			/*part A*/
			mpf_add(y_add2,one,y_main_val);
			mpf_pow_ui(y_add2,y_add2,4);
			mpf_mul(y_add2,y_add2,a0);
			
			/*Subtracting part a and b*/
			mpf_sub(a_val,y_add2,y_add);
						
			/*Updating value of A0,Y0*/
	     	mpf_set(a0,a_val);
			mpf_set(y0,y_main_val);
			
			
	
	    }
		//Clearing all variables.
		
		mpf_div(pi,one,a_val);
	    print(pi);
		mpf_clear(a0);
		mpf_clear(y0);
		mpf_clear(root2);
		mpf_clear(two);
		mpf_clear(constant);
		mpf_clear(four);
		mpf_clear(six);
		mpf_clear(one);
		mpf_clear(y_val);
		mpf_clear(a_val);
		mpf_clear(sub_val);
		mpf_clear(sub_main_val);
		mpf_clear(add_main_val);
		mpf_clear(y_main_val);
		mpf_clear(y_sq);
		mpf_clear(y_add);
		mpf_clear(y_add2);
		mpf_clear(pi);
		mpf_clear(count);

    return 0;
}


/***** Function definitions. *****/
void print(const mpf_t& pi)
{
	mp_exp_t expptr;
	char* str=NULL;
	char* str2;
	FILE* stream;
	size_t n=PRECISION;
	str2= mpf_get_str (str,&expptr,BASE, n, pi);
	 	 
	cout<<*str2;
	cout<<".";
	str2++;
	  
	for(int i=1;i<=LINE_COUNT;i+=5){
		//cout<<"i"<<i<<endl;
		int x=0;
	    while(x!=GROUP_SIZE){
			int y=0;
			while(y!=LINE_SIZE){
				int z=0;
				while(z!=BLOCK_SIZE){
					cout<<*str2;
					str2++;
					z++;
					y++;
				}
				cout<<" ";
			}
			cout<<endl;
			cout<<"  ";
			x++;
		}	
		cout<<endl;
		cout<<"  ";
	} 
	
}



