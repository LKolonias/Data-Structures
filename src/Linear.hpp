/*===========================================================================*
 *  To arxeio periexei tis sunarthseis pou xrhsimopoiountai gia:
 *   - Eisagwgh
 *   - Diagrafh
 *   - Anazhthsh vasei Id
 *   - Anazhthsh vash eponumou
 *  oi opoies xrhsimopoun grammiko tropo.
 *===========================================================================*/


/*========================= Eisagwgh Etairias ========================================================*/

// H sunarthsh eisagei mia kainouria etairia pou exei plhktrologithei apo ton xrhsth.
// Leitourgei desmevontas ena kainourio array apo vectors isou megethous me to prohgoumeno me
// mia epipleon thesh kai epaneisagei oles tis etairies kai thn kainouria sthn swsth seira.
void newCompanyInsertion(Company newcompany, Employee* newemployees) {

	// Orizoume metavlhtes gia thn sunarthsh kai desmevoume ek neou vector arrays
	// gia thn kainouria lista. H printVal krata ton aukswn arithmo gia thn ektupwsh
	// ths kainourias etairias sto telos
	int n,printVal;
	Companies* companies = new Companies[sizeof(Companies)];
	n = companies->numberOfCompanies = coms->numberOfCompanies + 1;
	vector<Company> company(n);
	vector<Employee> employee(n*7);
	bool z = true;
	
	for(int i=0; i<n; i++){
		
		// Aparaithtoi elegxoi gia na topothetithei h etairia sthn 
		// swsth seira. Auto ginetai gia na douleuoun swsta oi
		// duadikes anazhthseis pou apaitoun taksinomimenes listes
		if((com[i].id>newcompany.id)&&(z==true)){
			company[i]=newcompany;
			printVal=i;
			z=false;
		}
		else {
			if(z)
				company[i] = com[i];
			else
				company[i] = com[i-1];	
		}
		
	}
	
	// Paromoia diadikasia ginetai gia thn eisagwgh twn upallhlwn
	// ths kainourias etairias
	z=true;
	for(int i=0; i<n; i++){			
		for(int j=0; j<7; j++) {
			if(company[i].id==newcompany.id) {
				employee[7*i+j] = newemployees[j];
				z=false;
			}
			else{
				if(z)
					employee[7*i+j] = emp[7*i+j];
				else
					employee[7*i+j] = emp[7*(i-1)+j];
			}
			
		}
	}	
	companies->arr=&company[1];
	
	// Anathetoume stis global metavlhtes ta kainouria arrays	
	com=company;
	coms=companies;
	emp=employee;
	
	cout << "\n New company was added successfully and has the following data";
	printCompany(printVal);
}
/*========================================================================================================*/

/*========================= Diagrafh Etairias ============================================================*/

// H parakatw sunarthsh pairnei san orisma ena id kai diagrafei thn etairia kai tous upallhlous ths, me
// to antistoixo id. Shmeiwnoume oti h einai sigouro pws uparxei h antistoixh etairia afou exoume hdh
// kanei elegxo sthn main apo opou kai kaleitai h sunarthsh.
// Leitourgei me paromoio tropo opws kai h sunarthsh eisagwghs afou desmevei ek neou ta aparaithta arrays kai
// tous anathetei thn kainouria lista xwris thn etairia pou diagrafhke.
void companyDeletion(int id) {
	
	int n;
	Companies* companies = new Companies[sizeof(Companies)];
	n = companies->numberOfCompanies = coms->numberOfCompanies - 1;
	vector<Company> company(n);
	vector<Employee> employee(n*7);
	int j;
	int z=0;
	
	// Ginetai anathesh twn etairiwn ek neou sta kainouria arrays kai 
	// molis sunanthsoume authn me to id pou theloume na diagrapsoume
	// apla thn prospername.
	for(int i=0; i<coms->numberOfCompanies; i++){
		if (com[i].id != id){
			company[z] = com[i];

			z=z+1;
		}
		else {
			j=i;
		}
	}
	
	// Parakatw diagrafoume kai tous upallhlous apo to array twn upallhlwn me paromoio tropo
	z=0;
	for(int i=0; i<coms->numberOfCompanies*7; i++){
		if ( (i==7*j) || (i==7*j+1) || (i==7*j+2) || (i==7*j+3) || (i==7*j+4) || (i==7*j+5) || (i==7*j+6) ) {
			// edw apla prospername tous upallhlous pros diagrafh
		}
		else {
			employee[z] = emp[i];
			z++;
		}
	}
		
	// Anathetoume stis global metavlhtes ta kainouria arrays
	com=company;
	coms=companies;
	emp=employee;
	
}
/*========================================================================================================*/

/*========================= Grammikh Anazhthsh Id ========================================================*/

// H parakatw sunarthsh pairnei san orisma ena id kai ektupwnei sthn othonh ola ta stoixeia ths etairias
// me to antistoixo id. Se periptwsh pou den uparxei etairia me auto to id ektupwnei to antistoixo mhnuma.
void linearSearchId(int id) {
	bool z=true;
	// Grammikh anazhthsh sto array twn etairiwn
	for (int i=0; i<coms->numberOfCompanies; i++) {
		if((id==com[i].id) && pr) {
			printCompany(i);
			z=false;
		} 					
	}
	if(z && pr) 
		cout << "\n No company with this id exists\n\n\n";
}
/*========================================================================================================*/

/*========================= Grammikh Anazhthsh Epithetou =================================================*/

// Auth h sunarthsh pairnei san orisma ena epitheto pou eisagei o xrhsths kai ektupwnei tis etairies stis
// opoies douleuei upallhlos me auto to epitheto. H anazhthsh ginetai grammika se olo to array twn upallhlwn
void linearSearchSurname(string surname) {
	bool z=true;
	// Edw kanoume grammikh anazhthsh upallhlwn
	for (int i=0; i<coms->numberOfCompanies*7; i++) {
		if((surname==emp[i].lastName) && pr) {
			printCompany(i/7);
			z=false;							
		} 					
	}
	if(z && pr) 
		cout << "\n No employee with this surname works in a company\n\n\n";	
}
/*========================================================================================================*/
