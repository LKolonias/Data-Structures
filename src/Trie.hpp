/*===========================================================================*
 *  To arxeio periexei tis sunarthseis pou xrhsimopoiountai gia:
 *   - Eisagwgh
 *   - Anazhthsh vash eponumou
 *  mesw tou Trie kai aforoun to Meros D ths askhshs.
 *===========================================================================*/

/*============================= Komvos =================================================*/

// Parakatw orizoume thn domh tou komvou sto trie kai thn domh ths listas gia thn apothikeush
// pollwn diafwretikvn kleidiwn se periptwsh idou epwnumou.
struct trieList{
	int count;
	trieList* next=NULL;
};

struct trieNode {
	bool leaf;
	trieList* result=NULL;	
	
	// Oi deiktes exoun ulopoihthei me unordered map gia pio grhgorh anazhthsh
	unordered_map<char, trieNode*> children;
    trieNode():leaf(false), children(){}	
};
/*=======================================================================================*/

/*============================= Trie Class ===============================================*/

// H klash tou dentrou pou periexei tis sunarthseis gia thn diaxeirhsh tou.
class trie
{
	public:
		void trieDestruction(trieNode* node);
		void trieInsertion(char lastName[56], int count);
		void trieSearch(string str);
		trieNode* root;
		trie():root(new trieNode()){}
};
/*=======================================================================================*/

/*============================= Katastrofh tou trie =====================================*/

// H parakatw sunarthsh katastrefei to trie komvo pros komvo, anadromika, kalwntas ton
// eauto ths gia ta paidia kathe komvou.
void trie::trieDestruction(trieNode* node){
	if(node==NULL)
		return;
	for(size_t i=0; i<node->children.size(); i++)
	    trieDestruction(node->children[i]);
	delete node;
	node = NULL;
	
}
/*=======================================================================================*/

/*============================= Eisagwgh sto trie =======================================*/

// Edw ulopoioume thn sunarthsh eisagwghs enos epithetou sto trie. To orisma einai char[56]
// idio me auto pou dinetai sthn ekfwnhsh.
void trie::trieInsertion(char lastName[56],int count) {
	
	// metatrepoume to onoma se string
	string str(lastName);

	trieNode* temp = root;
	
	// Edw ksekina h eisagwgh apo thn riza
	for(size_t i=0; i<str.size(); ++i){
	   
	   // elegxoume an uparxei hdh komvos me ton antistoixo xarakthra
	    if(temp->children.count(str[i])==0)
	    	// kai ton dhmiourgoume se periptwsh pou 
			// den uparxei deikths pou na deixnei se auton
	    	temp->children[str[i]] = new trieNode();
	   
	    temp = temp->children[str[i]];
	}
	// Telos eisagoume to fullo pou shmatodotei to telos tou epithetou
	temp->leaf= true;
	
	// Sth sunexeia eisagoume komvous sth lista gia thn apothikeush twn
	// kleidiwn twn etairiwn pou douleuei upallhlos me to antistoixo epitheto      
	trieList* p;
	trieList* res = new trieList;
	
	if(temp->result == NULL){
		temp->result = res;
	    res->count = count;
	}
	else{
		p=temp->result;
	    while(p->next!=NULL){
	       	p = p->next;
		}
		p->next = res;
		res->count = count;
	}
}
/*=======================================================================================*/

/*============================= Anazhthsh sto trie ======================================*/

// H parakatw sunarthsh ulopoiei thn anazhthsh sto trie

void trie::trieSearch(string str) {
	
	if(root==NULL)
		return;
	 
	trieNode* temp = root;
	
	// H anazhthsh ginetai diatrexontas tous komvous tou dentrou
	for(size_t i=0; i<str.size(); ++i){
		if(temp->children.count(str[i])==0)
			return;
	    temp = temp->children[str[i]];
	}
	// kai an sto telos vriskomaste se fullo
	// ektupwnoume olh thn lista.
	if(temp->leaf) {
		trieList* p;
		p = temp->result;
		if(pr)
			printCompany(p->count);
			
		while(p->next!=NULL) {
			p=p->next;
			if(pr)
				printCompany(p->count);			
		}
	}
	else {
		if(pr)
			cout << "\n No employee with this surname works in a company\n\n\n";
	}  	
}
/*=======================================================================================*/
