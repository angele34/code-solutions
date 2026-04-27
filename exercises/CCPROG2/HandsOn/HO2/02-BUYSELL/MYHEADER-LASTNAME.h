/* 
   	Encode your Name and Section below.
	    
    LASTNAME, FIRSTNAME: _____________________
    SECTION: _________
*/

#include "buysell.h"  

/* 
	TO DO #1 [5 points]:
	
	Declare a structure data type for the Seller structure. 
  	
  	HARD REQUIREMENTS:
	1. Use  sellerTag as tag name.  
	
	2. The names of each structure members should be EXACTLY the same 
	   as those given in the table in the PDF file (names are in blue font color, and yellow fill color).
	   
	3. You have to make proper use of String30 (declared in buysell.h) for string member/s. 	   
*/

struct sellerTag {
	int ID;
	String30 firstname;
	String30 lastname;
	float rating;
};



/* 
	TO DO #2 [5 points]:
	
	Declare a structure data type for the Product structure. 
	
	1. Use productTag as tag name.  
	
  	2. The names of the structure member should be EXACTLY the same 
	   as those given in the table in the PDF file (names are in blue font color, and yellow fill color).
	3. You have to make proper use of String30 (declared in buysell.h) for string member/s. 	   
*/

struct productTag {
	int ID;
	String30 product_type;
	float price;
};

void InputSellers(struct sellerTag SELLERS[], int n_sellers);
void InputProducts(struct productTag PRODUCTS[], int n_products);
int Linear_Search(struct sellerTag SELLERS[], int n_sellers, int key);
void Recommend(struct sellerTag SELLERS[], struct productTag PRODUCTS[], int n_sellers, int n_products, const char* product);



