/*===========================================================================*
 *  Tmhma Mhxanikwn H/Y kai Plhroforikhs
 *  Domes Dedomenwn
 *  Ergasia Ak. Etos 2014 - 2015
 *  
 *
 *  Leonidas Kolonias, 4469, Etos 7o
 *===========================================================================*/


#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <vector>
#include <unordered_map>

using namespace std;

// Sthn metavlhth file pername to onoma tou arxeiou pou theloume na fortwsoume
char* file;

// Metavlhth gia thn ektupwsh apotelesmatwn
bool pr=true;

/*=============================== Klaseis ============================*/

// Parakatw fainontai oi klaseis opws dwthikan apo thn ekfwnhsh ths askhseis
// Epishs dhmiourgoume kai treiskatholikes metavlhtes thn emp, thn com kai thn
// coms pou periexoun ta dedomena pou einai fortwmena sto programma, kathe fora.
class Employee {
public:
char firstName[56]; 
char lastName[56];
};
vector<Employee> emp;

class Company {
public:
int id;
char title[256]; 
char summary[2048];
int numberOfEmployees;
vector<Employee> employees=vector<Employee>(7);
};
vector<Company> com;

class Companies {
public:
Company *arr;
int numberOfCompanies;
}*coms;
/*===========================================================================*/

// Header files pou periexoun tis sunarthseis pou dhmiourghsame gia tous skopous ths askhshs
// Einai topothethmena etsi wste kathe arxeio pou xreiazetai kapoia sunarthsh apo kapoio allo
// na mporei na thn vrei.

#include "Prints.hpp"
#include "AVL.hpp"
avlTree* AVL = new avlTree(); 

#include "Trie.hpp"
trie* Trie = new trie();

#include "LoadSave.hpp"
#include "Linear.hpp"
#include "Binary.hpp"
#include "Tester.hpp"



/*======================================= Main ======================================*/

// H main periexei kapoies switch gia tis epiloges tou xrhshth kai ektelei apla kapoies
// upotupwdeis leitourgies ths askhseis. Oi kuries sunarthseis pou xrhsimopoiei to programma
// vriskontai sta antistoixa header files.
int main(int argc, char** argv) {
	
	// Edw elegxoume an uparxei orisma gia
	// na fortwthei to antistoixo arxeio
	if (argc==2){
		loadFile(argv[1]);
	} 
	// alliws eisagetai to default arxeio data.csv
	else{
	 	file = "data.csv";
		loadFile(file);
	}
	bool menu = true;	

	while (menu) {
		printMenu();
		
		string str;
		int choice;	
		cin >> choice;
		
	switch(choice){
			
			/*=================== Epilogh 1: Load companies from file =====================================*/
			
			// Zhtame apo ton xrhsth na plhktrologisei to onoma tou arxeiou pou thelei na fortwsei
			// kai me auto san orisma kaloume thn sunarthsh "loadFile()" na kanei ta upoloipa.
			case 1:
			{
				cout << "\n\n ----------------------------------------------------------\n";
				cout << " Please note that the file must be in the main directory\n" << " Enter the name of the file: ";
				cin >> str;
				file = &str[0u]; //metatroph tou string pou plhktrologei o xrhsths se char*
				loadFile(file);
				cout << "\n File " << str << " has been loaded.";
				break;
			}
			/*==============================================================================================*/
			
			
			/*=================== Epilogh 2: Save companies to file ========================================*/
			
			// Zhtame apo ton xrhsth na plhktrologisei to onoma tou arxeiou sto opoio thelei na apothikeusei ta
			// dedomena pou uparxoun thn parousa stigmh sto programma kai me auto san orisma kaloume thn sunarthsh 
			// "saveFile()" h opoia xrhsimopoieitai gia thn apothikeush twt dedomenwn se arxeio.	
			case 2:
			{
				cout << "\n\n ----------------------------------------------------------\n";
				cout << " Please enter the name of the file to save the data: ";
				cin >> str;
				saveFile(str);
				break;	
			}
			/*==============================================================================================*/
			
			
			/*=================== Epilogh 3: Add a company =================================================*/	
			
			// Edw dhmiourgoume mia voithitikh metavlhth tupou Company kai apothikeuoume proswrina ta dedomena,
			// ths kainourias etairias, ta opoia plhktrologountai apo ton xrhsth. Epishs kanoume elegxo an to id
			// ths etairias pou theloume na eisagoume uparxei hdh sthn lista mas afou kathe etairia prepei na exei
			// monadiko id. H sunarthsh "newCompanyInsertion()" xrhsimopoieitai gia thn eisagwgh kainourias etairias.
			case 3:
			{
				Company newcompany;
				bool w=true;
				
				cout << "\n\n ----------------------------------------------------------\n";

				while(w){				
					cout << " Enter id: ";
					cin >> newcompany.id;
					for (int i=0; i<coms->numberOfCompanies; i++) {
						if(newcompany.id==com[i].id) {
							cout << "\n This id already exists, try again\n";
							w=true;
						break;
						} 						
						else 
							w=false;
					}
				}
				
				cout << " Enter title: ";
				cin >> newcompany.title;
				cout << " Enter Summary: ";	
				cin >> newcompany.summary;
				cout << " Enter the number of the employees[1-7]: ";	
				cin >> newcompany.numberOfEmployees;
				
				Employee* newemployees = new Employee[7*sizeof(Employee)];	
				for (int j=0; j<newcompany.numberOfEmployees; j++) {
					cout << " Enter first name of the employee No" << j+1 <<": ";
					cin >> newemployees[j].firstName;
					cout << " Enter last name of the employee No" << j+1 <<": ";
					cin >> newemployees[j].lastName;
				}
								
				newCompanyInsertion(newcompany, newemployees);
								
				break;				
			}
			/*==============================================================================================*/
			
			
			/*=================== Epilogh 4: Delete a company by id ========================================*/
			
			// H diagrafh ginetai zhtwntas apo ton xrhsth na plhktrologhsei to id ths etairias pou thelei na 
			// diagrapsei kai an to id einai egkuro tote kalwntas thn sunarthsh "companyDeletion()" diagrafetai
			// h etairia.
			case 4:
			{
				int id,z;
				z=0;
				cout << "\n\n ----------------------------------------------------------\n";
				cout << " Please enter the id of the company you want to delete: ";
				cin >> id;
				
				for (int i=0; i<coms->numberOfCompanies; i++) {
						if(id!=com[i].id) {
							z=1;
						} 	
						else {
							companyDeletion(id);
							z=0;
							break;
						} 					
					}
				if(z==1) cout << "\n No company with this id exists";
				break;
			}
			/*==============================================================================================*/
			
			
			/*=================== Epilogh 5: Display a company by id =======================================*/
			
			// Edw ektupwnoume ta stoixeia mias etairias thn opoia zhta o xrhsths plhktrologwntas to id ths.
			// Kaleite h sunarthsh "linearSearchId()" h opoia kanei grammikh anazhthsh gia thn euresh tou id.
			case 5:
			{
				int id;
				cout << "\n\n ----------------------------------------------------------\n";
				cout << " Please enter the id of the company you want to display: ";
				cin >> id;

			  	linearSearchId(id);
				break;
			}
			/*==============================================================================================*/
			
			
			/*=================== Epilogh 6: Display companies =============================================*/
			
			// Ektupwsh olwn twn etairiwn. Exoume kataskeuasei thn sunarthsh "printCompany()" h opoia xrhsimopoieitai
			// gia thn ektupwsh twn stoixeiwn mias etairias me mono orisma ton aukswnta arithmo ths etairias.
			case 6:
			{
				int id,z;
				cout << "\n\n ----------------------------------------------------------\n";
				
				for (int i=0; i<coms->numberOfCompanies; i++) {
					printCompany(i);
				} 
						
				break;					
			}
			/*==============================================================================================*/
			
			
			/*=================== Epilogh 7: Display companies by surname search ===========================*/	
			
			// Ektupwsh twn stoixiwn twn etairiwn stis opoies ergazetai upallhlos me to epithetou pou plhktrologithike
			// apo ton xrhsth. H anazhthsh ginetai grammika me thn sunarthsh "linearSearchSurname()"		
			case 7:
			{
				string surname;
				cout << "\n\n ----------------------------------------------------------\n";
				cout << " Please enter the surname of the company you want to display: ";
				cin >> surname;				
				linearSearchSurname(surname);
				
				break;
			}
			/*==============================================================================================*/
			
			
			/*==================== Epilogh 8: Exit =========================================================*/	
			
			// pragmatopoieitai eksodos apo to programma thetontas thn metavlhth "menu" se false wste na 
			// stamathsei h ektupwsh tou menu.
			case 8:
			{
				menu = false;
				break;
			}
			/*==============================================================================================*/
			
			
			
			
			
			
			
			/*==================== Epilogh 9: Binary mode ===================================================*/
			
			// Edw afhnoume ton xrhsth na ana zhthsei kapoia etairia me vash to id ths ektelwntas
			//  - Duadikh anazhthsh
			//  - Duadikh anazhthsh paremvolhs
			// Telos, h epilogh 3 einai gia thn epistrofh sto arxiko menu opou ola ginontai me grammiko tropo.
			case 9:
			{				
				bool binaryMenu = true;
				while(binaryMenu) {
					char choiceBinary;
					printBinaryMenu();
					
					cin >> choiceBinary;
					switch(choiceBinary){
						
						/*============= Epilogh 1: Binary Search ===========================*/
						
						// Ginetai duadikh anazhthsh me thn sunarthsh "binarySearch()"
						case '1':
						{
							int id;
							cout << "\n\n ----------------------------------------------------------\n";
							cout << " Please enter the id of the company you want to display: ";
							cin >> id;
							binarySearchId(id);
							break;
						}						
						/*==================================================================*/
						
						/*============= Epilogh 2: Binary Interpolation Search =============*/
						
						// Edw kanoume duadikh anazhthsh paremvolhs me thn sunarthsh "binaryInterpolationSearch()"
						case '2':
						{
							int id;
							cout << "\n\n ----------------------------------------------------------\n";
							cout << " Please enter the id of the company you want to display: ";
							cin >> id;
							binaryInterpolationSearch(id);
							break;
						}
						/*==================================================================*/
						
						/*============= Epilogh 3: Exit ====================================*/
						case '3':
						{
							binaryMenu = false;
							break;
						}
						/*==================================================================*/
						
						default:
						{
							cout << "\n\n ----------------------------------------------------------\n";
							cout<< "Your choice is not valid!\n";
							break;
						}				
					}					
				}
				break;
			}
			/*==============================================================================================*/
			
			
						
			
			
			/*==================== Epilogh 10: AVL mode ====================================================*/
			
			// Edw dhmiourgeitai to AVL dentro kai me tis parakatw epiloges dinoume thn dunatothta ston xrhsth
			// na anazhthsei, na eisagei kai na diagrapsei kapoia etairia.
			case 10:
			{	
				loadAVLTree(); // fortwsh twn eggrafwn sto dentro
							
				bool avlMenu = true;
				while(avlMenu) {
					char choiceAVL;
					printAVLMenu();
					
					cin >> choiceAVL;
					switch(choiceAVL){
						/*============= Epilogh 1: AVL search =============================*/
						case '1':
						{
							int id;
							avlNode* temp;
							cout << "\n\n ----------------------------------------------------------\n";
							cout << " Please enter the id of the company you want to display: ";
							cin >> id;
							temp = AVL->avlSearch(id);
							if(temp!=NULL)
								printCompany(temp->count);
							else
								cout << "\n No company with this id exists\n\n\n";
							break;
						}
						/*==================================================================*/
						
						/*============= Epilogh 2: AVL Insertion ===========================*/
						
						// Edw ginetai eisagwgh mias etairias, ta stoixeia ths opoias exei eisagei o 
						// xrhsths apo to plhktrologio, mesw ths sunarthsh "AVLInsertion()" ths klashs
						// avlTree. Shmeiwnoume oti h etairia eisagetai kai sthn lista com pou diateiroume.
						// Epishs arxika ekteloume elegxo gia to an h etairia uparxei hdh wste na mhn eisagoume
						// to idio id ksana.
						case '2':
						{
							Company newcompany;
							avlNode* temp;
							bool w=true;
							
							cout << "\n\n ----------------------------------------------------------\n";
			
							while(w){				
								cout << " Enter id: ";
								cin >> newcompany.id;
								temp = AVL->avlSearch(newcompany.id);
								
								if(temp!=NULL) {
									cout << "\n This id already exists, try again\n";
								} 						
								else 
									w=false;
							}
							
							cout << " Enter title: ";
							cin >> newcompany.title;
							cout << " Enter Summary: ";	
							cin >> newcompany.summary;
							cout << " Enter the number of the employees[1-7]: ";	
							cin >> newcompany.numberOfEmployees;
							
							Employee* newemployees = new Employee[7*sizeof(Employee)];	
							for (int j=0; j<newcompany.numberOfEmployees; j++) {
								cout << " Enter first name of the employee No" << j+1 <<": ";
								cin >> newemployees[j].firstName;
								cout << " Enter last name of the employee No" << j+1 <<": ";
								cin >> newemployees[j].lastName;
							}							
							newCompanyInsertion(newcompany, newemployees);							
							AVL->avlInsertion(newNode(com[coms->numberOfCompanies-1].id ,coms->numberOfCompanies-1));											
											
							break;				
						}
						/*==================================================================*/
						
						/*============= Epilogh 3: AVL Deletion ============================*/
						
						// Edw ginetai diagrafh etairias vasei tou id ths me thn sunarthsh "AVLDeletion()"
						// ths klashs avlTree. H etairia diagrafetai kai pao thn vasikh domh pou diateiroume.
						// Kai edw ekteleitai elegxos gia to an uparxei h etairia.
						case '3':
						{
							int id;
							avlNode* temp;

							cout << "\n\n ----------------------------------------------------------\n";
							cout << " Please enter the id of the company you want to delete: ";
							cin >> id;
							
							temp = AVL->avlSearch(id);
							if(temp!=NULL) {
								AVL->avlDeletion(id);
								companyDeletion(id);
							} 	
							else 
								cout << "\n No company with this id exists";
							
							break;
						}
						/*==================================================================*/
						
						/*============= Epilogh 4: Exit ====================================*/
						
						// Me thn epilogh exit o xrhsths epistrefei sto arxiko menu
						case '4':
						{
							avlMenu = false;
							break;
						}
						/*==================================================================*/
						
						default:
						{
							cout << "\n\n ----------------------------------------------------------\n";
							cout<< "Your choice is not valid!\n";
							break;
						}				
					}					
				}
				break;
			}
			/*==============================================================================================*/
			
			
						
			
			
			/*==================== Epilogh 11: Trie mode ===================================================*/
			
			// Edw dhmiourgeitai to Trie kai afhnoume ton xrhsth na anazhthsei kapoio epwnumo mesw autou.
			// Ta apotelesmata pou epistrefontai apo thn sunarthsh "trieSearch()" ths klashs Trie einai oi etairies
			// stis opoies douleuei upallhlos me to epwnumo pou anazhtoume.
			case 11:
			{
				loadTrie(); // fortwsh twn epithetwn sto trie
				
				bool trieMenu = true;
				while(trieMenu) {
					char choiceTrie;
					printTrieMenu();
					cin >> choiceTrie;
					switch(choiceTrie){
						
						/*============= Epilogh 1: Trie search =============================*/
						
						//Anazhthsh etairiwn sto Trie vasei epwnumou
						case '1':
						{
							string surname;
							cout << "\n\n ----------------------------------------------------------\n";
							cout << " Please enter the surname of the company you want to display: ";
							cin >> surname;
							cout<<surname<<"\n";
							Trie->trieSearch(surname);
														
							break;			
						}
						/*==================================================================*/
						
						/*============= Epilogh 2: Trie Insertion ==========================*/
						// Eisagwgh epwnumou sto Trie
						case '2':
						{
							// Den kaloume thn sunarthsh eisagwghs enos aplou upallhlou dioti
							// tha prepei na eisaxthei oloklhsh etairia.
						}
						/*==================================================================*/
						
						/*============= Epilogh 3: Exit ====================================*/
						//Epistrofh sto arxiko menu
						case '3':
						{
						trieMenu = false;
						break;
						/*==================================================================*/
						
						}
						default:
						{
							cout << "\n\n ----------------------------------------------------------\n";
							cout<< "Your choice is not valid!\n";
							break;
						}
					}
				}
				break;
			}			
			/*==============================================================================================*/
			
			
						
			
			
			/*==================== Epilogh 12: Test results =================================================*/
			
			// Sthn teleutaia epilogh "trexoume" tis sunarthseis anazhthshs pou exoume dhmiourgeisei gia enan
			// megalo arithmo anazhthsewn kai ektupwnoume tous xronous pou katanalwthikan kata thn diarkeia
			// twn anazhthsewn se kathe periptwsh.
			case 12:
			{
				loadAVLTree(); // fortwsh twn eggrafwn sto dentro
				loadTrie(); // fortwsh twn epithetwn sto trie
				
				testId();
				testSurname();
				break;
			}
			/*==============================================================================================*/			
			default:
				cout << "\n\n ----------------------------------------------------------\n";
                cout<< "Your choice is not valid!\n";		
		}
	}
	
	return 0;
}
