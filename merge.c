#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <limits.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>
#include <inttypes.h>
#include <math.h>
typedef long long int ll;
struct arg
{
	ll l;
	ll r;
	ll* arr;
};
ll * shareMem(size_t size){
     key_t mem_key = IPC_PRIVATE;
     int shm_id = shmget(mem_key, size, IPC_CREAT | 0666);
     return (ll*)shmat(shm_id, NULL, 0);
}
void insertion_sort(ll arr[],ll n){
for(int i = 1;i<n;i++){
		ll x = arr[i];
		int j = i-1;
		while(j>=0 && arr[j] > x){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = x;
	}
}

void merge(ll arr[],ll l,ll m,ll r){
	int i,j,k;
	int n1 = m-l+1;
	int n2  = r - m;
	ll L[n1],R[n2];
	for(i = 0;i<n1;i++){
		L[i] = arr[l+i];
	}
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	 
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 



	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
	
}
void mergesort(ll arr[],ll l,ll r){

if(l<r){
	ll m = (l+r)/2;
	mergesort(arr,l,m);
	mergesort(arr,m+1,r);
	merge(arr,l,m,r);
}
}

void normal_mergesort(ll arr[],ll n){
	mergesort(arr,0,n-1);
	 for(int i=0;i<n;i++){
                printf("%lld ",arr[i]);
        }
        printf("\n");
}
void cmergesort(ll arr[],ll l,ll r){
	int i,len,m;
	len = r-l+1;
	m = (l+r-1)/2;
	if(len<5){
		insertion_sort(arr+l,len);
		return;
	}
	int pid1,pid2;
	pid1 = fork();
	if(pid1<0){
	 perror("Left Child Proccess"); 
        exit(1);	
	}
	else if(pid1 == 0){
		cmergesort(arr,l,m);
		exit(0);
	}
	else{
		pid2 = fork();
		 if (pid2<0) 
        { 
            // Rchild proc not created 
            perror("Right Child Proc. not created\n"); 
            exit(1); 
        } 
        else if(pid2==0) 
        { 
            cmergesort(arr,m+1,r); 
            exit(0); 
        } 
        else{
        	int status;
			waitpid(pid1, &status, 0); 
		    waitpid(pid2, &status, 0); 
		    // Merge the sorted subarrays 
		    merge(arr, l, m, r);  
        }
        }	
}
void concurrent_mergesort(ll arr[],ll n){
	cmergesort(arr,0,n-1);
	for(int i = 0;i<n;i++){
		printf("%lld ",arr[i]);
    }
        printf("\n");
}
void* threaded_mergeSort(void* a){
	struct arg *args = (struct arg*) a;

     int l = args->l;
     int r = args->r;
     int *arr = args->arr;
     if(l>r) return NULL;
     
}
void runsorts(){
	ll n;
	scanf("%lld",&n);
	ll *arr = shareMem(sizeof(ll)*(n+1));
	ll brr [n];
	for(ll i = 0;i<n;i++){
		scanf("%lld",&arr[i]);
		brr[i] = arr[i];

	}

	struct timespec ts;

	
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    long double st = ts.tv_nsec/(1e9)+ts.tv_sec;
    // concurrent
    concurrent_mergesort(arr,n);

    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    long double en = ts.tv_nsec/(1e9)+ts.tv_sec;
    long double t1 = en-st;
    printf("time for concurrent mergesort is = %Lf\n", t1);
   

//////////////////////////////////////////////////////////////////////////
    
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    st = ts.tv_nsec/(1e9)+ts.tv_sec;
    //normal
    normal_mergesort(brr,n);

    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    en = ts.tv_nsec/(1e9)+ts.tv_sec;
    long double t2 = en-st;
    printf("time for normal_mergesort is  = %Lf\n", t2);
////////////////////////////////////////////////////////////////////////////////
    pthread_t tid;
     struct arg a;
     a.l = 0;
     a.r = n-1;
     a.arr = brr;
     clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
     st = ts.tv_nsec/(1e9)+ts.tv_sec;

     //multithreaded mergesort
     pthread_create(&tid, NULL, threaded_mergeSort, &a);
     pthread_join(tid, NULL);
      clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
     en = ts.tv_nsec/(1e9)+ts.tv_sec;
     long double t2 = en-st;
     printf("time = %Lf\n", t2);
     


    printf("normal_mergesort ran:\n\t[ %Lf ] times faster than concurrent_mergesort\n\n", t1/t2);
}
int main(){
	
	runsorts();
}
