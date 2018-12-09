/*===========================================================================*
 *  To arxeio periexei thn sunarthsn pou xrhsimopoieitai gia thn ektupwsh
 *  tou arxikou menu kai twn upomenu gia ta Merh B,C,D kai E ths askhshs.
 *  Epishs periexei thn sunarthsh gia thn ektupwsh twn stoixiwn etairias
 *===========================================================================*/


// Sunarthsh pou ektupwnei sthn othonh to arxiko menu epilogwn
void printMenu(){
	
	cout << "\n |========================================================|\n";
	cout << " ||           Companies Database Management              ||\n";
	cout << " ||======================================================||\n";
	cout << " ||                                                      ||\n";
	cout << " ||  1.Load companies from file                          ||\n";
	cout << " ||  2.Save companies to file                            ||\n";
	cout << " ||  3.Add a company                                     ||\n";
	cout << " ||  4.Delete a company by id                            ||\n";
	cout << " ||  5.Display a company by id                           ||\n";
	cout << " ||  6.Display companies                                 ||\n";
	cout << " ||  7.Display companies by surname search               ||\n";
	cout << " ||  8.Exit                                              ||\n";
	cout << " ||                                                      ||\n";
	cout << " ||  9.Binary mode                                       ||\n";
	cout << " || 10.AVL mode                                          ||\n";
	cout << " || 11.Trie mode                                         ||\n";
	cout << " ||                                                      ||\n";
	cout << " || 12.Test results                                      ||\n";		
	cout << " |========================================================|\n";
	cout << "\n Please select what to do [1-12]:";
	
}


// Sunarthsh pou ektupwnei to menu gia to Meros B ths askhshs
void printBinaryMenu(){
	
	cout << "\n |========================================================|\n";
	cout << " ||                    Binary Mode                       ||\n";
	cout << " ||======================================================||\n";
	cout << " ||                                                      ||\n";
	cout << " ||  1.Binary search                                     ||\n";
	cout << " ||  2.Binary Interpolation Search                       ||\n";
	cout << " ||  3.Exit Binary mode                                  ||\n";
	cout << " ||                                                      ||\n";		
	cout << " |========================================================|\n";
	cout << "\n Please select what to do [1-3]:";
	
}


// Sunarthsh pou ektupwnei to menu gia to Meros C ths askhshs
void printAVLMenu(){
	
	cout << "\n |========================================================|\n";
	cout << " ||                      AVL Mode                        ||\n";
	cout << " ||======================================================||\n";
	cout << " ||                                                      ||\n";
	cout << " ||  1.AVL search                                        ||\n";
	cout << " ||  2.AVL Insertion                                     ||\n";
	cout << " ||  3.AVL Deletion                                      ||\n";
	cout << " ||  4.Exit AVL mode                                     ||\n";
	cout << " ||                                                      ||\n";		
	cout << " |========================================================|\n";
	cout << "\n Please select what to do [1-4]:";
	
}


// Sunarthsh pou ektupwnei to menu gia to Meros D ths askhshs
void printTrieMenu(){
	
	cout << "\n |========================================================|\n";
	cout << " ||                     Trie Mode                        ||\n";
	cout << " ||======================================================||\n";
	cout << " ||                                                      ||\n";
	cout << " ||  1.Trie search                                       ||\n";
	cout << " ||  2.Trie Insertion                                    ||\n";
	cout << " ||  3.Exit Trie mode                                    ||\n";
	cout << " ||                                                      ||\n";		
	cout << " |========================================================|\n";
	cout << "\n Please select what to do [1-3]:";
	
}


// Sunarthsh pou ektupwnei ta stoixeia mias etairias.
void printCompany(int n){
	
	cout << "\n ||------------------------------------------------------------------\n";
	cout << " || Id: " << com[n].id <<"\n";
	cout << " || Title: " << com[n].title <<"\n";
	cout << " || Summary:	" << com[n].summary <<"\n";
	cout << " || Number of employees: " << com[n].numberOfEmployees <<"\n";
	for(int y=0; y<com[n].numberOfEmployees; y++) {
		cout << " || Employee No" << y+1 << " : "<< emp[n*7+y].firstName << " "<< emp[n*7+y].lastName <<"\n";
	}
	cout << " ||------------------------------------------------------------------\n";
	
}
