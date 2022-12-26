#include<iostream>
using namespace std;
class array{
    int *a;
    int size;
    int length;
    void swap(int*,int*);
    public:
    array(){
        size=10;
        length=0;
        a=new int[size];
    }
    array(int sz){
        size=sz;
        length=0;
        a=new int[size];
    }
    ~array(){
        delete []a;
    }
    void display();
    void insert(int,int);
    void append(int);
    void Delete(int);
    int linear_search(int);
    int binary_search(int);
    int get(int);
    void set(int,int);
    int max();
    int sum();
    float avg();
    int min();
    void reverse();
    void sorted_insert(int);
    void signed_sorted();
    void sort();
    array merge(array);
    void set_array();
};
void array:: display(){
    for(int i=0;i<length;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
void array::insert(int key,int position)
{
    position--;
    if(position>=0 && position<length){
    for(int i=length;i>position;i--){
        a[i]=a[i-1];
    }
    a[position]=key;
    length++;
    }
}
void array::append(int key){
    if(length<size){
        a[length]=key;
        length++;
    }
}
void array::Delete(int pos){
    pos--;
    if(pos>=0 && pos<length){
        for(int i=pos;i<length-1;i++){
            a[i]=a[i+1];
        }
        length--;
    }
}
void array::swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int array::linear_search(int key){
    int temp;
    for(int i=0;i<length;i++){
        if(a[i]==key){
            temp=a[i];
            a[i]=a[i-1];
            a[i-1]=temp;
            return i;
            
        }
    }
    return -1;
}
int array::binary_search(int key){
    int low=0,high=length-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(key<a[mid]){
            high=mid-1;
        }
        else if(key>a[mid]){
            low=mid+1;
        }
            
    }
    return -1;
}
/*int rbin_search(int l,int h,array arr,int key){
    int mid;
    if(l<=h){
        mid=(l+h)/2;
        if(arr.a[mid]==key){
            return mid;
        }
        else if(arr.a[mid]>key){
            return rbin_search(l,mid-1,arr,key);
        }
        else{
            return rbin_search(mid+1,h,arr,key);
        }
    }
    return -1;
}*/
int array::get(int index){
    if(index>=0 && index<length){
        return a[index];
    }
    return -1;
}
void array::set(int index,int x){
    if(index>=0 && index<length){
        a[index]=x;
    }
}
int array::max(){
    int m=a[0];
    for(int i=1;i<length;i++){
        if(a[i]>m){
            m=a[i];
        }
    }
    return m;
}
int array::sum(){
    int sum=0;
    for(int i=0;i<length;i++){
        sum+=a[i];
    }
    return sum;
}
float array::avg(){
    return (float)sum()/length;
}
int array::min(){
    int m=a[0];
    for(int i=1;i<length;i++){
        if(a[i]<m){
            m=a[i];
        }
    }
    return m;
}
void array::reverse(){
    int temp;
    for(int i=0,j=(length-1);i<j;i++,j--){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
void array::sorted_insert(int key)
{   int i=length-1;
    if(size==length)
    return;
    while(a[i]>key){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=key;
    length++;
}
void array::signed_sorted(){
    int i=0,j=length-1,temp;
    while(i<j){
        while(a[i]<0){
            i++;
        }
        while(a[j]>=0){
            j--;
        }
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}
void array::sort(){
    int temp;
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
/*array array::merge(array b){
    array* c=new array[length+b.length];
    int i,j,k;
    i=j=k=0;
    while(i<length && j<b.length){
        if(a[i]<b.a[j]){
            c->a[k++]=a[i++];
        }
        else{
            c->a[k++]=b.a[j++];
        }
    }
    for(;i<length;i++)
        c->a[k++]=a[i];
    for(;j<b.length;j++)
        c->a[k++]=b.a[j];
        c->length=length+b.length;
}*/
void array:: set_array(){
    length=size;
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
}
int main(){
    array a;
    a.set_array();
    a.display();
    return 0;
}
