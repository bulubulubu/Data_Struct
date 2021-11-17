#include"List_Sequence.h"

#include<iostream>
using namespace std;

#define TOTAL_LENGTH_INIT_SIZE 50
#define LENGTH_INCREMENT 20

template<typename diverse>
List_Sequence<diverse>::List_Sequence(){
    Date_type_length = sizeof(diverse);
    Base_address = (diverse*)malloc(TOTAL_LENGTH_INIT_SIZE*sizeof(diverse));
    Total_length = TOTAL_LENGTH_INIT_SIZE;
    Used_length = 0;
}
template<typename diverse>
List_Sequence<diverse>::~List_Sequence(){
    free(Base_address);
}
template<typename diverse>
void List_Sequence<diverse>::ClearList(){
    free(Base_address);
    Date_type_length = sizeof(diverse);
    Base_address = (diverse*)malloc(TOTAL_LENGTH_INIT_SIZE*sizeof(diverse));
    Total_length = TOTAL_LENGTH_INIT_SIZE;
    Used_length = 0;
}
template<typename diverse>
bool List_Sequence<diverse>::ListEmpty(){
    if(Used_length == 0) return true;
    else return false;
}
template<typename diverse>
int List_Sequence<diverse>::ListLength(){
    return Used_length;
}
template<typename diverse>
void List_Sequence<diverse>::GetElem(int i, diverse* e){
    if(i>Used_length || i<0){
        e = NULL;
    }
    else {
        *e = Base_address[i];
    }
}
template<typename diverse>
int List_Sequence<diverse>::LocateElem(diverse* e, void compare()){
    return 0;
}
template<typename diverse>
int List_Sequence<diverse>::PriorElem(diverse* e, diverse* pre_e){
    return 0;
}   
template<typename diverse>
int List_Sequence<diverse>::NextElem(diverse* e, diverse* next_e){
    return 0;
}
template<typename diverse>
void List_Sequence<diverse>::ListInsert(int i, diverse* e){
    if(Used_length == Total_length){
        diverse* alternate = (diverse*)malloc((Total_length + LENGTH_INCREMENT)*sizeof(diverse));
        for(int i=0; i<Used_length; i++){
            alternate[i]=Base_address[i];
        }
        free(Base_address);
        Base_address = alternate;
        Total_length = Total_length + LENGTH_INCREMENT;
    }
    int y = 0;
    for(y=Used_length; y>=i-1; y--){
         Base_address[y+1] = Base_address[y];
    }
    Base_address[y] = *e;
    Used_length += 1;
}
template<typename diverse>
void List_Sequence<diverse>::ListDelete(int i, diverse* e){
    *e = Base_address[i-1];
    for(int y = i-1; y<Used_length; y++){
        Base_address[y] = Base_address[y+1];
    }
    diverse* altenate = (diverse*)malloc(1*sizeof(diverse));
    Base_address[Used_length] = *altenate;
    Used_length -= 1;
}
template<typename diverse>
void List_Sequence<diverse>::ListTraverse(void visit()){

}

template<typename diverse>
void List_Sequence<diverse>::WriteElem(diverse* e){
    if(Used_length == Total_length){
        diverse* alternate = (diverse*)malloc((Total_length + LENGTH_INCREMENT)*sizeof(diverse));
        for(int i=0; i<Used_length; i++){
            alternate[i]=Base_address[i];
        }
        free(Base_address);
        Base_address = alternate;
        Total_length = Total_length + LENGTH_INCREMENT;
    }
    Base_address[Used_length] = *e;
    Used_length += 1;
}