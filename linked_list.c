#include <stdio.h>
#include <stdlib.h>

#define		get_of_entry(ptr, type, member)	( (void*)(\
(char*)ptr \
- (sizeof(type) - sizeof(struct _list)) \
+ (int)&(((type*)0)->member) \
) )

struct _list{
	struct _list *next, *prev;
};

struct _item{
	int A;
	char B;
	float C;
	double D;
	char* E;
	struct _list list;
};

int main(void) {
	struct _list head, *ptr;
	struct _item item1, item2, item3;
	char* str1 = "item1", *str2 = "item2", *str3 = "item3";
	
	head.next = &item1.list;
	head.prev = NULL;
	
	item1.A = 11;	item1.B = 12;	item1.C = 13.0;	item1.D = 14.0;	item1.E = str1;
	item1.list.prev = NULL;
	item1.list.next = &item2.list;
	
	item2.A = 21;	item2.B = 22;	item2.C = 23.0;	item2.D = 24.0;	item2.E = str2;
	item2.list.prev = &item1.list;
	item2.list.next = &item3.list;
	
	item3.A = 31;	item3.B = 32;	item3.C = 33.0;	item3.D = 34.0;	item3.E = str3;
	item3.list.prev = &item2.list;
	item3.list.next = NULL;
	
	printf("A: %d[%08X], B: %d[%08X], C: %f[%08X], D: %lf[%08X], E: %s[%08X], list: %08X, next: %08X, prev: %08X\n", 
		item1.A, &item1.A, item1.B, &item1.B, item1.C, &item1.C, item1.D, &item1.D, item1.E, &item1.E, 
		&item1.list, &item1.list.next, &item1.list.prev
	);
	printf("A: %d[%08X], B: %d[%08X], C: %f[%08X], D: %lf[%08X], E: %s[%08X], list: %08X, next: %08X, prev: %08X\n", 
		item2.A, &item2.A, item2.B, &item2.B, item2.C, &item2.C, item2.D, &item2.D, item2.E, &item2.E, 
		&item2.list, &item2.list.next, &item2.list.prev
	);
	printf("A: %d[%08X], B: %d[%08X], C: %f[%08X], D: %lf[%08X], E: %s[%08X], list: %08X, next: %08X, prev: %08X\n", 
		item3.A, &item3.A, item3.B, &item3.B, item3.C, &item3.C, item3.D, &item3.D, item3.E, &item3.E, 
		&item3.list, &item3.list.next, &item3.list.prev
	);
	
	puts("--------");
	
	for(ptr = &head; ptr->next != NULL; ptr = ptr->next) {
		printf("A: %d[%08X], B: %d[%08X], C: %f[%08X], D: %lf[%08X], E: %s[%08X]\n", 
			   *(int*)get_of_entry(ptr->next, struct _item, A), get_of_entry(ptr->next, struct _item, A), 
			  *(char*)get_of_entry(ptr->next, struct _item, B), get_of_entry(ptr->next, struct _item, B), 
			 *(float*)get_of_entry(ptr->next, struct _item, C), get_of_entry(ptr->next, struct _item, C), 
			*(double*)get_of_entry(ptr->next, struct _item, D), get_of_entry(ptr->next, struct _item, D),
			 *(char**)get_of_entry(ptr->next, struct _item, E), get_of_entry(ptr->next, struct _item, E)
		);
	}
	
	return EXIT_SUCCESS;
}
