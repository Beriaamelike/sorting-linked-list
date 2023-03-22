#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//Creating the struct
struct Student{
	
 char name[50];
 char gender;
 struct Student * next;
 
};




struct Student * insertNode (char *name, char gender, struct Student * list){
	
 struct Student *s;
 //Allocate memory for node (malloc operation)
 s = malloc (sizeof (struct Student));
 if (s == NULL)
 {
 printf ("Memory allocation failed.");
 return list;
 }
 strcpy(s->name, name);
 s->gender = gender;
 s->next = list; //list is the start of the list
 list = s;

 return list;
 
}



//find the number of linked list array items
int numberOfLinkedListItems(struct Student *list){
	
	
	int count = 0;
	struct Student *ptr;
	ptr = list;
	
	if(ptr == NULL){
		return count;  // empty array
	}
	else{
		while(ptr!=NULL){
			count++;
			ptr = ptr->next; //traverse the list
		}
	}
	return count;
	
}






//Sorting function
struct Student * sortList (struct Student *list){
	
	int count = numberOfLinkedListItems(list);  //Number Of Array Items
	
	//Creating three Initial Node Variables
	struct Student *ptr1;
	struct Student *ptr2;
	struct Student *ptr3;
	
	
	
	
	
	int i;
	int j;
	
	
	
	for(j=0; j<count-1; j++){   //Bubble Sort Algorithm
	     
	    ptr1=NULL;
     	ptr2=list;
	    ptr3=ptr2->next;
	    
	    // always compare ptr2 and ptr3 variables
	
        for(i=0; i<count-j-1; i++){
		
            if(ptr2->gender == 'M' && ptr3->gender == 'M' && strcmp(ptr3->name,ptr2->name)>0 ){  //Compare two men by their names.
        	
        	    ptr2->next = ptr3->next;
        	    ptr3->next = ptr2;
        	    if(ptr1!=NULL){
				
        	    ptr1->next = ptr3;
        	    }
        	    ptr1 = ptr3;
        	    ptr3 = ptr2->next;
        	    if(i==0){
        	    	list=ptr1;  //Declare head of list
				}
        	    
        	 
		    }
		    else if(ptr2->gender == 'F' && ptr3->gender == 'F' && strcmp(ptr3->name,ptr2->name)<0 ){   //Compare two women by their names.
        	
        	   ptr2->next = ptr3->next;
        	    ptr3->next = ptr2;
        	    if(ptr1!=NULL){
				
        	    ptr1->next = ptr3;
        	    }
        	    ptr1 = ptr3;
        	    ptr3 = ptr2->next;
        	    if(i==0){
        	    	list=ptr1;   //Declare head of list
				}
        	 
	    	}
	    	else if(ptr2->gender == 'M' && ptr3->gender == 'F' ){  //Replace man and woman 
        	
        	    
        	    ptr2->next = ptr3->next;
        	    ptr3->next = ptr2;
        	    if(ptr1!=NULL){
				
        	    ptr1->next = ptr3;
        	    }
        	    ptr1 = ptr3;
        	    ptr3 = ptr2->next;
        	    if(i==0){
        	    	list=ptr1;  //Declare head of list
				}
        	
        	}
        	else{
        		
        		ptr1 = ptr2;       //Change the address held by the pointer variables.
        	    ptr2 = ptr3;
        	    ptr3 = ptr3->next;
        	    if(i==0){
        	    	list=ptr1;     // Declare head of list
				}
        	    
        	    
			}
        
		
	    }
    }
    
    
	
	return list;
}







//Printing function
void printList (struct Student * list){
	
 while (list != NULL)
 {
 printf ("%s\t%c\n", list->name, list->gender);
 list = list->next;
 }
 
}





int main (){
	
 //Creating an Initial Node Variable
 struct Student * head=NULL;
 //Call to functions

 
 head = insertNode("Cenk", 'M', head);
 head = insertNode("Ceyda", 'F', head);
 head = insertNode("Esra", 'F', head);
 head = insertNode("Okan", 'M', head);
 head = insertNode("Tugce", 'F', head);
 head = insertNode("Mehmet", 'M', head);
 head = insertNode("Ayse", 'F', head);
 head = insertNode("Merve", 'F', head);
 head = insertNode("Sedat", 'M', head);
 head = insertNode("Ahmet", 'M', head);
 
 
 
 //call to sorting function
 head = sortList(head);
 printList(head);
 
 
 return 0;
}

