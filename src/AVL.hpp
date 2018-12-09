/*===========================================================================*
 *  To arxeio periexei tis sunarthseis pou xrhsimopoiountai gia:
 *   - Eisagwgh
 *   - Diagrafh
 *   - Anazhthsh vasei Id
 *  mesw tou AVL dentrou kai aforoun to Meros C ths askhshs.
 *===========================================================================*/


/* domh tou komvou gia to dentro. Periexei deiktes gia to deksi kai aristero paidi
 * kai ton patera, metavlhth gia to upsos tou komvou, metavlhth gia thn isorropia
 * to kleidi pou einai to idio me to id kathe etairias kai metavlhth count pou einai 
 * o aukswn arithmos me ton opoio einai apothikeumenh h etairia sto array, com, twn etairiwn*/
struct avlNode {
	int key;
	avlNode* left;
	avlNode* right;
	avlNode* parent;
	int height;
	int balance;
	int count;
};

/*============================= AVL Class ===============================================*/

// sthn parakatw klash periexontai oles oi sunarthseis pou aforoun th domh tou AVL dentrou
// kai tis energies tou.
class avlTree
{		
	public:
		avlNode* root;
		void rotateLeft(avlNode* node);
		void rotateRight(avlNode* node);
		void avlDeletion(int id);
		
		void avlCreation();
		void avlDestruction(avlNode* node);
		void avlInsertion(avlNode* node);
		void restoreHeights(avlNode* node);
		void restoreBalances(avlNode* node);
		void restoreAvlTree(avlNode* node);
		avlNode* avlSearch(int id);
		avlNode* findMax(avlNode* node);
		avlNode* findMin(avlNode* node);
};
/*=======================================================================================*/


// Sunarthsh gia thn dhmiourgia tou dentrou
// Arxikopoiei thn riza root ish me NULL
void avlTree::avlCreation() {
	root = NULL;	
}

// Sunarthsh gia thn katastrofh kai thn olikh diagrafh tou dentrou
// H diagrafh ginetai anadromika kathws h sunarthsh episkeptetai kathe komvo
// kai kalei ton eauto ths gia kathe ena apo ta paidia tou.
void avlTree::avlDestruction(avlNode* node) {
	if (node!=NULL) {
		avlDestruction(node->left);
		avlDestruction(node->right);
		delete node;
	}
}


/*============================= Anazhthsh ===============================================*/

// Edw ginetai anazhthsh etairias vasei tou id ths pou einai to idio me thn metavlhth key.
// H sunarthsh pairnei san orisma to id pros anazhthsh kai epistrefei ton komvo pou exei san
// key to sugkekrimeno id. Se periptwsh apotuxias epistrefei enan komvo NULL.
avlNode* avlTree::avlSearch(int id) {
	avlNode *temp;
	
	temp = root;

	while (temp != NULL) {
		if(id < temp->key) 		
			temp = temp->left;			
		else if(id > temp->key) 
			temp = temp->right;		 			
		else if(id == temp->key) 
			break;				
	}
	
	return temp;
}
/*=======================================================================================*/

/*============================= Eisagwgh ================================================*/

// Ginetai eisagwgh kainouriou komvou sto dentro. H sunarthsh pairnei san orisma enan kainourio komvo pou
// dhmiourgeitai apo thn klhsh ths "newNode()"
void avlTree::avlInsertion(avlNode* node) {
	
	// ean h riza einai NULL tote o kainourios komvos tha einai h riza	
	if (root == NULL) {
		root = node;
		return;
	}
	
	// voithitikoi komvoi kai metavlhtes
	avlNode *temp, *back, *ancestor;
	bool z=true;
	ancestor = back = NULL;	
	temp = root;
	
	// anazhthsh sto dentro gia thn euresh ths theshs pou tha eisagoume
	// ton kainourio komvo
	while(temp != NULL) {

		back = temp;						
		if(node->key < temp->key) 
			temp = temp->left;		
		else if(node->key > temp->key)
			temp = temp->right;
		else if(node->key == temp->key) {
			z=false;
			temp=NULL;
		}
	}
	
	// Ean o komvos uparxei hdh exoume apotuxia kai den eisagetai tipota
	if(z){
	
		node->parent = back;
		if(node->key < back->key) 
			back->left = node;		
		else 
			back->right = node;
		
		// klhsh sunarthshs gia thn apokatastash tou dentrou meta thn enthesh
		restoreAvlTree(node);
	}
}
/*=======================================================================================*/

/*============================= Diagrafh ================================================*/

// Edw pragmatopoieitai diagrafh komvou vasei tou id.
void avlTree::avlDeletion(int id) {
	
	avlNode *temp, *sub;
	
	// anzhthsh sto dentro gia thn euresh tou pros diagrafh komvou
	temp = avlSearch(id);
	//se periptwsh epituxias ekselisetai h praksh aposveshs
	if(temp!=NULL) {
		
		// periptwsh pou o komvos einai fullo
		if((temp->right == NULL) && (temp->left == NULL)) {
			
			// an o komvos den einai h riza
			// thetoume ton progono me NULL kai ton diagrafoume
			if(temp != root){
				if(temp->parent->right == temp)
					temp->parent->right = NULL;
				else if(temp->parent->left == temp)
					temp->parent->left = NULL;
			
				// Sunarthsh apokatastashs tou dentrou meta thn aposvesh	
				restoreAvlTree(temp->parent);
				delete[] temp;
				return;
			}
			else {
				delete[] temp;
				return;
			}				
		}
		// periptwseis pou okomvos exei paidia
		// kalountai oi sunarthseis "findMin()" kai "findMax()" gia thn euresh
		// fullou antikatastath tou komvou
		else if((temp->right != NULL) && (temp->left == NULL))
			sub = findMin(temp);
		else
			sub = findMax(temp);
		// exoume epileksei na dialegoume ws komvo antikatastashs auton me to megalutero
		// id apo to aristero upodentro sthn periptwsh pou o komvos exei kai ta 2 paidia tou ugih kai swa!
	}
	else
		return;
	
	// afou vrethei o antikatastaths ton antikathistoume me ton komvo pou theloume na diagrapsoume
	temp->key = sub->key;
	temp->count = sub->count;
	if(sub->parent->right == temp)
		sub->parent->right = NULL;
	else if(sub->parent->left == temp)
		sub->parent->left = NULL;
	
	//kaloume thn parakatw sunarthsh gia thn epanazughsh tou dentrou
	restoreAvlTree(sub->parent);
	delete[] sub;	// kai diagrafoume to fullo
}
/*=======================================================================================*/

/*============================= Sunarthseis eureshs =====================================*/

//euresh tou amesws mikroterou komvou sthn diagrafh
avlNode* avlTree::findMax(avlNode* node) {
	avlNode *temp;
	temp = node;
	
	temp = temp->left;
	while(temp->right!=NULL){
		temp = temp->right;
	}
			
	return temp;
}

//euresh tou amesws megaluterou komvou sthn diagrafh
avlNode* avlTree::findMin(avlNode* node) {
	avlNode *temp;
	temp = node;
	
	temp = temp->right;
	while(temp->left!=NULL){
		temp = temp->left;
	}
			
	return temp;
}
/*===================================================================================================*/

/*============================= Apokatastash AVL ====================================================*/

// H sunarthsh auth kaleitai meta apo kathe enthesh 'h diagrafh kai elegxei to upsos kai thn isorropoia
// twn komvwn sto krisimo monopati kai apofasizei ana xreiazontai peristrofes 'h oxi
void avlTree::restoreAvlTree(avlNode* node) {
	
	// arxika kaloume thn "restoreHeights()" gia na kanoume apokatastash tou AVL
	// me ta teleutaia upsh kai isorropoies( h sunarthsh auth kalei me thn seira ths thn
	// "restoreBalances()" gia tis isorropoies)
	restoreHeights(node);
	avlNode* temp;
	
	temp = node;
	while(temp->parent!=NULL) {
		temp = temp->parent;
		// elegxoume an kapoios komvos exei mh-epitrpth isorropoia
		// opws einai fusiko oi epitreptes times einai monon oi {-1,0,+1}
		if((temp->balance==2) || (temp->balance==-2) ) {
			// ean kapoios komvos exei isorropoia -2
			if (temp->balance == -2) {
				//kai to deksi tou upodentro exei isorropoia -1 				
				if ((temp->right->balance == -1) || (temp->right->balance == 0)){
					// tote kanoume aplh aristerh peristrofh
					rotateLeft(temp);					
				}
				// an to deksi upodentro tou exei isorropoia 1 tote prepei
				else{
					// na kanoume diplh aristerh peristrofh (mia deksia ston yio akolouthoumenh apo mia aristerh)
					rotateRight(temp->right);
					rotateLeft(temp);
				}	
			}
			// ean kapoios komvos exei isorropoia 2
			else if(temp->balance==2) {
				//kai to aristero tou upodentro exei isorropoia 1 
				if((temp->left->balance == 1) || (temp->left->balance == 0)) {
					// tote kanoume aplh deksia peristrofh
					rotateRight(temp);
				}
				// an to deksi upodentro tou exei isorropoia -1 tote prepei
				else{
					// na kanoume diplh aristerh peristrofh 
					// (mia deksia ston yio akolouthoumenh apo mia aristerh)
					rotateLeft(temp->left);
					rotateRight(temp);
				}
			}
		}
		/* Edw shmeiwnoume oti se auto to shmeio tha eprepe na kalesoume ksana thn
		 * restoreHeights(), alla kaleitai mesa stis sunarthseis peristrofwn. Auto
		 * ginetai dioti den xreiazetai na epanupologiszoume ta upsh kai tis isorropoies
		 * se periptwsh pou den uparksei peristrofh*/
	}
	
}
/*==================================================================================================*/

/*============================= Apokatastash Ypsous ================================================*/

// Auth h sunarthshs kaleitai me orisma ton komvo ston opoio exei ginei kapoia allagh(enthesh, aposvesh, peristrofh, ktl)
// kai diatrexei to krisimo monopati apo ton komvo ws thn riza, epanaupologizontas ta upsh ton komvwn sto monopati auto.
void avlTree::restoreHeights(avlNode* node) {
	avlNode *temp = node;
	int i,j;
	j=1;
	while(temp!=NULL) {
		
		if((temp->left!=NULL) || (temp->right!=NULL)) {
			// an o komvos exei 2 paidia
			if((temp->left!=NULL) && (temp->right!=NULL)) {
				// to upsos tha isoutai me to megalutero apo ta upsh twn paidiwn tou
				if(temp->left->height >= temp->right->height)
					j=temp->left->height+1;
				// an ta ipsh twn paidiwn tou einai isa tote to upsos tha einai +1 megalutero
				// apo ena apo auta(dialegoume to deksi edw)
				else
					j=temp->right->height+1;
			}
			// periptwsh pou o komvos exei mono aristero paidi
			else if ((temp->left!=NULL) && (temp->right==NULL)) {
				// tote to upsos tha einai iso me to upsos tou paidiou +1
				j = temp->left->height+1;
			}
			// kai an o komvos exei mono deksi paidi
			else if((temp->left==NULL) && (temp->right!=NULL))
				j = temp->right->height+1;
		}
		// telos anathetoume ston komvo to upsos j pou exoume upologisei prohgoumenws,
		// shmeiwnoume oti an o komvos einai fullo tou anathetoume upsos 1 			
		temp->height = j;

		temp = temp->parent;
			
	}
	// meta twn upologismo twn upswn kaleitai h sunarthsh "restoreBalances()" gia ton
	// epanupologismo twn isorropiwn me orisma ton idio komvo
	restoreBalances(node);
}
/*==================================================================================================*/

/*============================= Apokatastash Isorropias =============================================*/

// Sthn parakatw sunarthsh, opws kai prin, diatrexoume to krisimo monopati apo ton komvo ths allaghs
// mexri thn riza kai epanupologizoume thn isorropia kathe komvou.
void avlTree::restoreBalances(avlNode* node) {
	avlNode* temp = node;
	// Arxika gia ton arxiko komvo sto krisimo monopati
	// elegxoume an o komvos exei kai ta 2 tou paidia
	if(temp->left!=NULL && temp->right!=NULL)
		// tote h isorropoia tou einai ish me to ypsos tou aristerou
		// mion to upsos tou deksiou upodentrou		
		temp->balance = temp->left->height - temp->right->height;
	// an o komvos exei mono deksi upodentro
	else if(temp->left==NULL && temp->right!=NULL)
	 	// h isorropoia tou einai ish me to upsos tou deksiou upodentrou
		temp->balance = 0 - temp->right->height;
	// enw an exei mono aristero paidi
	else if(temp->left!=NULL && temp->right==NULL)
		// h isorropoia einai ish me to upsos tou aristerou upodentrou
		temp->balance = temp->left->height - 0;
	else
	// ean o komvos den exei katholou paidia h isorropoia einai 0
		temp->balance = 0;
		
	
	// sth sunexeia kanoume to parapanw gia olous tous komvous sto
	// krisimo monopati apo ton komvo ws thn riza		
	while(temp->parent!=NULL) {
		temp = temp->parent;
		if(temp->left!=NULL && temp->right!=NULL)
			temp->balance = temp->left->height - temp->right->height;
		else if(temp->left==NULL && temp->right!=NULL)
			temp->balance = 0 - temp->right->height;
		else
			temp->balance = temp->left->height - 0;
	}
}

/*==================================================================================================*/

/*============================= Aristerh peristrofh ================================================*/

// H sunarthsh auth ektelei aristerh peristrofh ston komvo node pou eisxwreitai san orisma
void avlTree::rotateLeft(avlNode* node) {
	avlNode *temp, *pivot;
	temp = node;
	// h metavlhth pivot krata to deksi upodentro tou komvou pros peristrofh
	pivot = temp->right;
	
	// to deksi upodentro exei twra patera ton patera tou komvou
	pivot->parent = temp->parent;
	
	// elegxoume an o komvos einai den einai h riza 
	if(temp->parent!=NULL){
			// an nai elegxoume an o komvos einai to deksi h aristero paidi tou patera tou 
			if(temp->parent->left==temp)
				// kai ton kanoume patera kai tou aristerou upodentou
				temp->parent->left = pivot;
			else
				// h tou deksiou antistoixa
				temp->parent->right = pivot;
	}
	// an einai h riza tote apla h riza ginetai to deksi paidi
	else
		root = pivot;
	
					
	temp->parent = pivot;		// pateras tou komvou ginetai to deksi tou paidi
	temp->right = pivot->left;	// kai to aristero paidi tou deksiou paidiou ginetai twra deksi paidi tou komvou (isws kai na mhn uparxei!)		
	pivot->left = temp;			// o komvos ginetai aristero paidi tou paliou deksiou paidiou tou
	if(temp->right!=NULL)		// telos elegxoume an to palaio deksi paidi eixe aristero upodentro
		temp->right->parent = temp;  // kai an nai tou anathetoume ton kainourio patera tou
	
	// edw ksana kaloume thn sunarthsh apokatastashs twn upswn
	restoreHeights(temp);
		
	
}
/*==================================================================================================*/

/*============================= Aristerh peristrofh ================================================*/

// H sunarthsh auth ektelei deksia peristrofh ston komvo node pou eisxwreitai san orisma
void avlTree::rotateRight(avlNode* node) {
	avlNode *temp, *pivot;
	temp = node;
	// edw h metavlhth pivot krata to aristero upodentro tou komvou pros peristrofh
	pivot = temp->left;
	// to aristero upodentro exei twra patera ton patera tou komvou
	pivot->parent = temp->parent;
	
	// elegxoume an o komvos einai den einai h riza
	if(temp!=root){
			if(temp->parent->left==temp)
				temp->parent->left = pivot;
			else
				temp->parent->right = pivot;
	}
	else
		root = pivot;
						
	temp->parent = pivot;		// pateras tou komvou ginetai to aristero tou paidi
	temp->left = pivot->right;	// kai to deksi paidi tou aristerou paidiou ginetai twra aristero paidi tou komvou
	pivot->right = temp;		// o komvos ginetai deksi paidi tou paliou aristerou paidiou tou
	if(temp->left!=NULL)		// telos elegxoume an to palaio aristero paidi eixe deksi upodentro
		temp->left->parent = temp;	// kai an nai tou anathetoume ton kainourio patera tou
	
	restoreHeights(temp);
	
}
/*========================================================================================================*/


/*============================= Dhmiourgia Komvou ================================================*/

// Auth h sunarthsh pairnei san orisma to id mias etairias kai ton antistoixo aukswn arithmo ths
// kai dhmiourgei enan arxiko komvo o opoios tha stalei argotera gia enthesh sto dentro
avlNode* newNode(int id, int n)
{
   avlNode *temp = new avlNode();
   temp->key = id;
   temp->left = NULL;
   temp->right = NULL;
   temp->parent = NULL;
   temp->balance = 0;
   temp->height =1;
   temp->count = n;
   return temp;
}
/*========================================================================================================*/
