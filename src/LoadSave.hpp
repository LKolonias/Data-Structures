/*===========================================================================*
 *  To arxeio periexei tis sunarthseis pou xrhsimopoiountai gia:
 *   - Fortwsh
 *   - Apothikeush
 *   - Fortwsh tou AVL dentrou
 *   - Fortwsh tou Trie
 *  twn arxeiwn pou periexoun ta dedomena ta opoia epeksergazetai h vash.
 *===========================================================================*/




/*====================== Fortwsh eggrafwn apo Arxeio ===============================*/

// Sunarthsh pou xrhsimopoieitai gia na fortwsoume tis eggrafes sthn mnhmh apo arxeio
void loadFile(char* y) {

	ifstream data (y);
	int n;
	string line, element;
	getline(data, line); // pairnoume thn prwth seira tou arxeiou pou periexei ton
						 //arithmo twn eggrafwn wste na arxikopoihsoume ta vectors sth sunexeia

	
	//Arxikopoihsh twn megethwn twn clasewn Employee, Company kai Companies
	//Ginontai me vectors dioti me xrhsh malloc 'h new tha uparksei provlhma
	//mnhmhs otan exoume polles eggrafes (bad_alloc)
	Companies* companies = new Companies[sizeof(Companies)];
	n=companies->numberOfCompanies = atoi(line.c_str());
	vector<Company> company(n);
	vector<Employee> employee(n*7);

	//Arxikopoihsh voithitikou tou voithitikou array dataArr pou xrhsimevei gia
	//na ginei to parsing apo to arxeio kai voithitikwn metavlhtwn
	vector<string> dataArr(companies->numberOfCompanies*11);
	string first,last;
	int i,j,z;
	i=j=z=0;
	
		
	//Edw ginetai to parsing apo to arxeio stoixeio pros stoixeio.
	//Ta stoixeia apothikeuontai proswrina sto dataArr mias kai einai ola strings
	//arxika. Sth sunexeia metatrepontai sthn katallhlh morfh kai apothikeuontai
	//sta com, coms kai emp.
	while (getline(data, line)) {
		istringstream s(line);
	
		while (getline(s, element,';')){
			dataArr[j]=element;
			j=j+1;
		
		}

		company[i].id=atoi(dataArr[j-11].c_str());
		dataArr[j-10].copy(company[i].title, dataArr[j-10].length());
		dataArr[j-9].copy(company[i].summary, dataArr[j-9].length());		
		company[i].numberOfEmployees=atoi(dataArr[j-8].c_str());

		for (z=0; z<company[i].numberOfEmployees; z++) {
			first=dataArr[j+z-7].substr(0, dataArr[j+z-7].find(" "));
			first.copy(employee[z+7*i].firstName,first.length());  
			last=dataArr[j+z-7].substr(dataArr[j+z-7].find(" ")+1);
			last.copy(employee[z+7*i].lastName,last.length());

			company[i].employees[z]=employee[i*7+z];
					
		}

		companies->arr=&company[0];
		i=i+1;
	}

	com=company;
	coms=companies;
	emp=employee;

}
/*=======================================================================================*/


/*=================================== Fortwsh AVL dentrou ===============================*/

// Sunarthsh pou xrhsomopoihtai gia na fortwsoume tis egrafes sto AVL dentro.
// H eisagwgh ginetai me thn apostolh duo parametrwn, tou id kathe etairias
// kai ton auksonta arithmo kata ton opoio einai paothikeumenh h etairia sto
// array com.
void loadAVLTree() {
	AVL->avlCreation();		
	for (int i=0; i<coms->numberOfCompanies; i++) {
		AVL->avlInsertion(newNode(com[i].id ,i));		
	}	
}
/*=======================================================================================*/


/*=================================== Fortwsh Trie ======================================*/

// Sunarthsh pou xrhsomopoihtai gia na fortwsoume ta epitheta sto Trie.
// H eisagwgh ginetai me thn apostolh duo parametrwn, tou epithetou kathe upallhlou
// kai ton auksonta arithmo ths etairias sthn opoia douleuei.
void loadTrie(){
	for(int i=0; i<coms->numberOfCompanies; i++){
		for(int k=0; k<com[i].numberOfEmployees; k++) {
			Trie->trieInsertion(com[i].employees[k].lastName,i);
		}
	}
}
/*=======================================================================================*/



/*============================= Apothikeush se Arxeio ===================================*/

// H parakatw sunarthsh apothikeuei ta dedomena pou uparxoun sta com, coms kai emp thn stigmh pou
// kaleitai, se arxeio pou dinetai apo ton xrhsth.
void saveFile(string str){
	
	file = &str[0u];
	ofstream data;
	data.open(file);
	data << coms->numberOfCompanies;
	
	for (int i=0; i<coms->numberOfCompanies; i++) {
		data << "\n" << com[i].id << ";" << com[i].title << ";" << com[i].summary << ";" << com[i].numberOfEmployees;					
	
		for(int j=0; j<com[i].numberOfEmployees; j++){
		data << ";" << emp[j+7*i].firstName << " " << emp[j+7*i].lastName;
		}					
	}				
	
}
/*=======================================================================================*/
