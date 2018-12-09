/*===========================================================================*
 *  To arxeio periexei tis sunarthseis pou xrhsimopoiountai gia:
 *   - Binary Search
 *   - Binary Interpolation Search
 *  pou afouroun to Meros B ths askhshs.
 *===========================================================================*/


/*========================= Duadikh Anazhthsh ============================================================*/

// H parakatw sunarthsh kanei duadikh anazhthsh sto array twn etairiwn vasei tou id.
void binarySearchId(int id) {
	
	bool z = true;
	int mid,oldmid,left,right;
	left = 0;
	right = coms->numberOfCompanies-1;
	mid = (right - left)/2;
	
	// Oso o prohgoumenos mesos den einai idios me ton epomeno
	// kanoume anazhthsh. Eidalws shmenei oti h anazhthsh apetuxe.
	while(mid!=oldmid){
		
		// an to id anazhthshs einai megalutero tou mesou
		// pou vriskomaste
		if (id>com[mid].id) {
			//anathetoume ta kainouria oria
			left = mid;
			oldmid = mid;
			// kai ton kainourio meso
			mid = mid + (right - left)/2;
		}
		// enw an to id einai mikrotero
		else if(id<com[mid].id) {
			// antistoixa anathetoume kainouria oria
			right = mid;
			oldmid = mid;
			mid = mid - (right - left)/2;
			// o parakatw elegxos einai gia thn anazhthsh
			// ths prwths etairias
			if((mid==1) && (oldmid==1) && (id==com[0].id))
				mid = 0;
		}
		// an to id einai iso me ton meso
		// h anazhthsh termatizetai epituxws
		else if(id==com[mid].id) {	
			// kai ektupwnetai to apotelesma
			if(pr)					
				printCompany(mid);			
			z=false;
			break;
		}
	}
	// Ektupwsh antistoixou mhnumatos se periptwsh apotuxias
	if(z && pr) cout << "\n No company with this id exists\n\n\n";
		
}
/*===============================================================================================================*/


/*========================= Duadikh Anazhthsh Paremvolhs ========================================================*/

// Auth h sunarthsh kanei duikh anazhthsh paremvolhs.
// O algorithmos einai autos ths selidas 82 tou vivliou kai epipleon periexei
// kai tous aparaithtous elegxous se periptwsei pou h anazhthsh ksefugei apo ta oria tou array.
void binaryInterpolationSearch(int id) {
	
	bool z = true;
	
	int size,left,right,next,i,s;
	left = i = 0;	
	right = coms->numberOfCompanies-1;
	size = right-left;
	
	// Arxika kanoume to vhma paremvolhs
	next = (((id-com[left].id)*size)/(com[right].id-com[left].id));
	
	// elegxos wste na apofeuxthei h  anazhthsh se periptwsh pou psaxnoume to
	// prwto stoixeio
	if(id == com[0].id)
		next = 0;
	
	// edw ksekina h anazhthsh	
	while(id!=com[next].id) {
		
		i=0;
		size = right-left;
		// anazhtoume me vhma iso me thn riza tou megethous.		
		s = next+i*sqrt(size);
		
		// pros ta deksia se periptwsh pou meta thn paremvolh vriskomaste
		// se id mikroterou autou pou anazhtoume
		if(id>com[next].id){
			
			while (id>com[s].id) {
				i++;
				s = next+i*sqrt(size);

				right = next + i*sqrt(size);
				left = next + (i-1)*sqrt(size);
				// Sunthikh elegxou an upervoume to anw orio tou array
				if (s > (coms->numberOfCompanies-1)){
					right = coms->numberOfCompanies-1;
					s=coms->numberOfCompanies-1;
					size = right-left;

					break;
				}				
			}	
		}
		// pros ta aristera se periptwsh pou vriskomaste se thesh megaluterh auths pou psaxnoume
		else if(id<com[next].id) {
			while (id<com[s].id) {
				i++;
				s = next-i*sqrt(size);
			
			
				right = next-(i-1)*sqrt(size);
				left = next - i*sqrt(size);
				// Sunthikh elegxou gia na mhn upervoume to katw orio tou array
				if(s < 0){
					left = 0;
					size = right-left;
					s=0;
				}
			}
		}
		// upologizoume to neo megethos tou array anazhthshs kai
		// kanoume to vhma paremvolhs
		size = right-left; 
		next = left + (((id-com[left].id)*size)/(com[right].id-com[left].id));

		if (size==1) 
			break;			
	
		if(id>coms->numberOfCompanies-1)
			break;		
	}
	// Ektupwsh twn apotelesmatwn
	if((id==com[next].id) && pr)
		printCompany(next);
	else
		if(pr)
			cout << "\n No company with this id exists\n\n\n";
}
/*===============================================================================================================*/
