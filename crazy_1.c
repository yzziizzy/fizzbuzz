


void crazy_1(int max, char* b) {
	char o = 1, t = 0, h = 0;
	char oc = 0, tc = 0;
	int c = 0;
	
	#define Q(x) (~((x & 1) | ((x & 4) >> 3)) & ((((x & 8) >> 2) & (x & 2)) >> 1))
	
	
	#define J \
	++o; \
	oc = Q(o); \
	o -= oc << 3 | oc << 1; \
	t += oc; \
	tc = Q(t); \
	t -= tc << 3 | tc << 1; \
	h += tc; \
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

