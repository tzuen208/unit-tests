#include "swap.c"

void merge_sort(List **head){
    if( !(*head)->next) return;    
    List *mid;
    List *fast;
    List *pre_mid;
    mid = *head;
    fast = *head;
    pre_mid = *head;

   for(; fast && fast->next;){
        pre_mid = mid;
        mid = mid->next;
        fast = fast->next;
        if(fast->next)
            fast = fast->next;
    }
    pre_mid->next = NULL;
   // fast = *head;
    if((*head)){
    	merge_sort( head);
    	merge_sort( &mid);
    	merge( head, &mid); 
    }
    return;
}

void merge(List **left, List **right){
    List *chead; 
    List *combine;
    int first = 1;
    for(;(*left) || (*right);){
        if( !(*left)){
            if(first){           
                combine = (*right);
                chead = combine;
                first = 0;
	    }else{
	        combine->next = (*right);
	        combine = combine->next;
            }
            (*right) = (*right)->next;
        }
        else if( !(*right)){
            if(first){           
                combine = (*left);
                chead = combine;
                first = 0;
	    }else{
		combine->next = (*left);
	        combine = combine->next;
            }
            (*left) = (*left)->next;
        }
        else if( (*left)->value >= (*right)->value){
            if(first){          
                combine = (*right);
                chead = combine;
                first = 0;
	    }else{
		combine->next = (*right);
	        combine = combine->next;
            }
            (*right) = (*right)->next;
        }
	else{
            if(first){           
                combine = (*left);
                chead = combine;
                first = 0;
	    }else{
		combine->next = (*left);
	        combine = combine->next;
            }
            (*left) = (*left)->next;
	}
    }
    (*left) = chead;
}
