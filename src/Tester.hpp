/*===========================================================================*
 *  To arxeio periexei tis sunarthseis pou xrhsimopoiountai gia thn dokimh
 *  kai ton elegxo twn domwn pou exoume dhmiourghsei. Sugkekrimena periexei 
 *  sunarthseis gia:
 *   - Anazhthsh vash Id gia oles tis periptwseis
 *   - Anazhthsh vash epwnumou gia oles tis periptwseis
 *  To arxeio auto afora to Meros E ths askhshs.
 *===========================================================================*/
#include <iomanip>
#include <sys/time.h>
//#include <windows.h> 
#include <stdio.h>
#include <time.h>
#include <unistd.h>
//#include <dos.h>



/*============================= Metrhsh Xronou ===========================================*/

// Sunarthsh metrhshs tou xronou se microseconds
double time_diff(struct timeval x , struct timeval y)
{
    double x_ms , y_ms , diff;   
    x_ms = (double)x.tv_sec*1000000 + (double)x.tv_usec;
    y_ms = (double)y.tv_sec*1000000 + (double)y.tv_usec; 
    diff = (double)y_ms - (double)x_ms;
    
    return diff;
}
/*=======================================================================================*/


/*============================= Test Id ==================================================*/


void testId() {
	
	struct timeval tv[8];
	
	
	int randomIdArray[15000];
	double x=0;
	avlNode* temp;
	for(int i=0; i<15000; i++){
		randomIdArray[i] = rand() % 12000 + 1;
	}
	
	pr = false;
	cout << "\n\n    Linear     Binary      Binary Intp     AVL \n";
	cout<<"---------------------------------------------------------------\n";
	for(int j=0; j<10; j++){
	
		//Gramminkh anazhthsh me vash to id
		gettimeofday (&tv[0], NULL);	
		for(int i=0; i<15000; i++){
			linearSearchId(randomIdArray[i]);
		}
		gettimeofday (&tv[1], NULL);
		x = time_diff(tv[0],tv[1]);
		cout <<setw(10) <<x ;	
		
		//Binary anazhthsh me vash to id
		gettimeofday (&tv[2], NULL);	
		for(int i=0; i<15000; i++){
			binarySearchId(randomIdArray[i]);
		}
		gettimeofday (&tv[3], NULL);
		x = time_diff(tv[2],tv[3]);
		cout <<setw(9) <<x ;
		
		//Binary Interpolation anazhthsh me vash to id
		gettimeofday (&tv[4], NULL);	
		for(int i=0; i<15000; i++){
			binaryInterpolationSearch(randomIdArray[i]);
		}
		gettimeofday (&tv[5], NULL);
		x = time_diff(tv[4],tv[5]);
		cout <<setw(12) <<x ;
		
		int d;
			
		//Anazhthsh me vash to id sto AVL dentro
		gettimeofday (&tv[6], NULL);
		for(int i=0; i<15000; i++){
			d=randomIdArray[i];
			AVL->avlSearch(d);
		}
		gettimeofday (&tv[7], NULL);
		x = time_diff(tv[6],tv[7]);
		cout <<setw(16) <<x <<"\n";
	
	}
	pr = true;
}

void testSurname(){
	struct timeval tv[8];
	double x = 0;
	int randomIdArray[1500];
	int n = coms->numberOfCompanies*7;
	for(int i=0; i<1500; i++){
		randomIdArray[i] = rand() % n;
	}
	
	pr =false;
	cout << "\n\n    Linear           Trie\n";
	cout<<"------------------------------------\n";
	for(int j=0; j<10; j++){
		// Grammikh anazhthsh epithetou
		gettimeofday (&tv[0], NULL);
		for(int i=0; i<1500; i++){
			string str(emp[randomIdArray[i]].lastName);
			linearSearchSurname(str);
		}
		gettimeofday (&tv[1], NULL);
		x = time_diff(tv[0],tv[1]);
		cout <<setw(15) <<x ;
		
		// Anazhthsh epithetou mesw Trie
		gettimeofday (&tv[2], NULL);
		for(int i=0; i<1500; i++){
			string str(emp[randomIdArray[i]].lastName);
			Trie->trieSearch(str);
		}
		gettimeofday (&tv[3], NULL);
		x = time_diff(tv[2],tv[3]);
		cout <<setw(10) <<x <<"\n";
	}

	pr = true;
}
