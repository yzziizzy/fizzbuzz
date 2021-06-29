



// This version uses branching for updating the number printing counters

int branch_1(int max, char* b) {
	char o = 1, t = 0, h = 0;
	char oc = 0, tc = 0;
	int c = 0;
	
	#define Q(x) (~((x & 1) | ((x & 4) >> 3)) & ((((x & 8) >> 2) & (x & 2)) >> 1))
	
	
	#define J \
	if(++o == 10) {\
		o = 0; \
		if(++t == 10) { t = 0; h++; }\
    } \
	P('\n')
	
	#define P(x) b[c++]=x;
	#define _F P('F')P('i')P('z')P('z')
	#define _B P('B')P('u')P('z')P('z')
	#define F _F J
	#define B _B J
	#define FB _F _B J
	#define N P('0'+h)P('0'+t)P('0'+o) J
	
	for(;max >= 15; max -= 15) {
		N N F N B F N N F B N F N N FB 
	}
	
	#define I if(--max == 0) break;
	
	do {
		N I N I F I N I B I F I N I N I F I B I N I F I N I N I F B 
	} while(0);
	
	b[c] = 0;
	
//	puts(b);
}






void naive_1(int max, char* b) {
	
	for(int i = 0; i <= max; i++) {
		if(i % 3 == 0) printf("Fizz");
		if(i % 5 == 0) printf("Buzz");
		if(i % 5 != 0 && i % 3 != 0) printf("%d", i);
		printf("\n");
	}
}

void buffered_1(int max, char* b) {
	int c = 0;
	
	#define P(x) b[c++]=x;
	#define _F P('F')P('i')P('z')P('z')
	#define _B P('B')P('u')P('z')P('z')
	
	for(int i = 0; i <= max; i++) {
		if(i % 3 == 0) { _F };
		if(i % 5 == 0) { _B };
		if(i % 5 != 0 && i % 3 != 0) c += sprintf(b + c, "%d", i);
		P('\n');
	}
	
	b[c] = 0;
	
//	puts(b);
}

