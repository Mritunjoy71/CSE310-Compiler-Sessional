
#include<bits/stdc++.h>
using namespace std;
int bucket_size;
int Count =0;
class ScopeTable;
ScopeTable *present=NULL;
class SymbolInfo
{
private:


    string Name;
    string Type;
	string IDType;				//VAR, ARA, FUNC
	string VarType;				//INT, FLOAT, CHAR
	int AraSize; 				//CONST_INT
	string FuncRet;				//INT, FLOAT, VOID
	int araIndex;
	bool FuncDefined = false;	//true, false	//true,false


public:
    SymbolInfo *next;
    SymbolInfo *prev;

    vector<string> ParamList;	//INT, FLOAT, STRING, CHAR
    vector<int> ints;
	vector<float> floats;
	vector<char> chars;

	SymbolInfo(){
	    this->Name="";
        this->Type="";
        this->next=NULL;
        this->prev=NULL;
    }

    SymbolInfo(string type){
		VarType = type;
		if(type == "INT") ints.push_back(0);
		else if(type == "FLOAT") floats.push_back(0);
    }

    SymbolInfo(string name, string type){
        Name = name;
        Type = type;
        this->next=NULL;
        this->prev=NULL;
    }



    ~SymbolInfo()
    {
        delete prev;
        delete next;
    }


    void setName(string name){	Name = name;	}
    void setType(string type){ 	Type = type;	}
	void setIDType(string type){IDType = type;	}
	void setVarType(string type){
		VarType = type;
		if(type == "INT") ints.push_back(0);
		else if(type == "FLOAT") floats.push_back(0);
	}
	void setAraSize(int size){	AraSize = size;	}
	void setFuncRet(string type){FuncRet = type;}
	void setFuncDefined(){ FuncDefined = true;	}
	void setAraIndex(int index){araIndex = index;}

    string getName(){ return Name;}
    string getType(){ return Type;}
	string getIDType(){return IDType;}
	string getVarType(){return VarType;}
	int getAraSize(){return AraSize;}
	string getFuncRet(){return FuncRet;}
	bool isFuncDefined(){return FuncDefined;}
	int getAraIndex(){return araIndex;}

    SymbolInfo operator = (const SymbolInfo &sym){
        this->Name = sym.Name;
        this->Type = sym.Type;
        return *this;
    }

	void printValues(ofstream& file){
		if(IDType == "VAR"){
			file << " , ";
			if(VarType == "INT") file << ints[0] ;
			else file << floats[0];
		}
		else if(IDType == "ARA"){
			file << " , { " ;
			if(VarType == "INT"){
				for(int i = 0; i< AraSize; i++) file << ints[i] << " ";
			}
			else if(VarType == "FLOAT"){
				for(int i = 0; i< AraSize; i++) file << floats[i] << " ";
			}
			file << "}" ;
		}
		else if(IDType == "FUNC"){

		}
	}



};

class ScopeTable
{
public:
    ScopeTable *parentScope;
    int st_id;
    SymbolInfo **htable, **top;
    ScopeTable(int m)
    {
        bucket_size=m;
        Count++;
        this->st_id=Count;
        this->parentScope=present;
        htable = new SymbolInfo*[bucket_size];
        top = new SymbolInfo*[bucket_size];
        for (int i = 0; i < bucket_size; i++)
        {
            htable[i] = NULL;
            top[i] = NULL;
        }
    }
    ~ScopeTable()
    {
        delete [] htable;
    }

    int HashFunc1(string  key)
    {
        int seed = 123;
        unsigned long index = 0;
        for(int i = 0; i < key.length(); i++)
        {
            index = (index * seed) + key[i];
        }
        return index % bucket_size;
    }

    int getID(){return st_id;}

    bool Insert(string symbol_name, string symbol_type)
    {
        SymbolInfo *si=lookUp(symbol_name,symbol_type);
        if(!si)
        {
            int hash_val = HashFunc1(symbol_name);
            SymbolInfo *entry = htable[hash_val];
            int pos=0;
            if (entry == NULL)
            {
                entry = new SymbolInfo;
                entry->setName(symbol_name);
                entry->setType(symbol_type);
                entry->next = NULL;
                entry->prev = NULL;
                htable[hash_val] = entry;
                top[hash_val] = entry;
              //  printf("    Inserted in ScopeTable #%d at position %d,%d\n",this->st_id,hash_val,pos);
            }
            else
            {
                while (entry != NULL)
                {
                    entry = entry->next;
                    pos++;
                }
                entry = new SymbolInfo;
                entry->setName(symbol_name);
                entry->setType(symbol_type);
                entry->next = NULL;
                entry->prev = top[hash_val];
                top[hash_val]->next = entry;
                top[hash_val] = entry;
              //  printf("    Inserted in ScopeTable #%d at position %d,%d\n",this->st_id,hash_val,pos);
            }
            return true;
        }
        else
        {
           // cout<<"    Already inserted\n";
            return false;
        }
    }

    SymbolInfo* Insert(SymbolInfo* sym){
        int hash_val = HashFunc1(sym->getName());
        SymbolInfo *entry = htable[hash_val];
        int pos=0;
        if (entry == NULL)
        {
            entry = new SymbolInfo;
            entry->setName(sym->getName());
            entry->setType(sym->getType());
            entry->next = NULL;
            entry->prev = NULL;
            htable[hash_val] = entry;
            top[hash_val] = entry;
          //  printf("    Inserted in ScopeTable #%d at position %d,%d\n",this->st_id,hash_val,pos);
            return htable[hash_val];
        }
        else
        {
            while (entry != NULL)
            {
                entry = entry->next;
                pos++;
            }
            entry = new SymbolInfo;
            entry->setName(sym->getName());
            entry->setType(sym->getType());
            entry->next = NULL;
            entry->prev = top[hash_val];
            top[hash_val]->next = entry;
            top[hash_val] = entry;
          //  printf("    Inserted in ScopeTable #%d at position %d,%d\n",this->st_id,hash_val,pos);
            return entry;
        }


    }

    void  Delete(string name)
    {

        SymbolInfo* entry;
        string symbol_name=name;
        int hash_val = HashFunc1(symbol_name);
        entry= htable[hash_val];

        while (entry != NULL)
        {
            if(entry->getName()==symbol_name)
            {
                if(entry->prev==NULL &&entry->next!=NULL)
                {
                    entry->next->prev=NULL;
                    htable[hash_val]=entry->next;
                    delete entry;
                   // cout<<"     The token is deleted\n";
                    break;
                }
                if(entry->prev!=NULL && entry->next!=NULL)
                {
                    entry->prev->next=entry->next;
                    entry->next->prev=entry->prev;
                    delete entry;
                   // cout<<"     The token is deleted\n";
                    break;
                }
                if (entry->next == NULL)
                {
                    if (entry->prev == NULL)
                    {
                        htable[hash_val] = NULL;
                        top[hash_val] = NULL;
                        delete entry;
                        //cout<<"     The token is deleted\n";
                        break;
                    }
                    else
                    {
                        top[hash_val] = entry->prev;
                        top[hash_val]->next = NULL;
                        delete entry;
                       // cout<<"     The token is deleted\n";
                        entry = top[hash_val];
                    }
                }
            }
            entry = entry->next;
        }
    }

    SymbolInfo* lookUp(string symbol_name,string type)
    {
        int hash_val = HashFunc1(symbol_name);
        SymbolInfo* sinfo=new SymbolInfo();
        sinfo= htable[hash_val];
        if (sinfo != NULL)
        {
            int l=0;
            while (sinfo != NULL)
            {
                if (sinfo->getName() == symbol_name &&sinfo->getType()==type)
                {
                    //cout<<"     Found  in ScopeTable #"<<this->st_id<<" at position "<<hash_val<<" , "<<l<<"\n";
                    return sinfo;
                }
                l++;
                sinfo=sinfo->next;
            }
        }
        return  0;
    }


    SymbolInfo* lookUp(SymbolInfo* si)
    {
        string symbol_name=si->getName();
        int hash_val = HashFunc1(symbol_name);
        SymbolInfo* sinfo=new SymbolInfo();
        sinfo= htable[hash_val];
        if (sinfo != NULL)
        {
            int l=0;
            while (sinfo != NULL)
            {
                if (sinfo->getName() == symbol_name && sinfo->getType()==si->getType())
                {
                    //cout<<"     Found  in ScopeTable #"<<this->st_id<<" at position "<<hash_val<<" , "<<l<<"\n";
                    return sinfo;
                }
                l++;
                sinfo=sinfo->next;
            }
        }
        return  0;
    }

    void PrintScope(ofstream& file)
    {
        int i;
        file<<"     ScopeTable #"<<this->st_id<<endl;
        for(i=0; i<bucket_size; i++)
        {
            file<<"\t";
            if(top[i]!=NULL)
            {
                SymbolInfo *temp=htable[i];
                file<<i<<" -->";
                while(temp)
                {
                    file<<"<"<<temp->getName()<<" : "<<temp->getType()<<">"<<"\t";
                    temp=temp->next;
                }
                file<<"\n";
            }
            else
            {
                file<<i<<" -->"<<endl;
            }
        }
    }
};

class SymbolTable
{
public:
    ScopeTable *curScope=NULL;
    SymbolTable()
    {
        curScope=NULL;
    }

    SymbolTable(int m){
        ScopeTable *st  =new ScopeTable(m);
        st->parentScope=present;
        this->curScope=st;
        present=curScope;

    }

    ~SymbolTable()
    {
        delete curScope;
    }

    SymbolInfo* Insert(SymbolInfo *sym){
        SymbolInfo *si=new SymbolInfo();
		si= curScope->Insert(sym);
		return si;
	}

    bool Insert(string symbol_name,string symbol_type)
    {
        return curScope->Insert(symbol_name,symbol_type);
    }

    SymbolInfo* InsertandGet(string name, string type){
		SymbolInfo* temp = new SymbolInfo(name, type);
		SymbolInfo* temp2 = curScope->Insert(temp);
		return temp2;
	}

    void Remove(string symbol_name)
    {
        this->curScope->Delete(symbol_name);
    }

    SymbolInfo* lookUp(string name,string type)
    {

        ScopeTable *st=curScope;
        SymbolInfo *sil=NULL;
        while(st!=NULL)
        {
            sil=st->lookUp(name,type);
            if(sil!=NULL)
                break;
            st=st->parentScope;
        }
        return sil;

    }

    void printCurrent(ofstream& file){
        if(curScope!=NULL)
            this->curScope->PrintScope(file);
    }

    void printAll(ofstream& file){
    {
        ScopeTable *temp=this->curScope;
        while(temp!=NULL)
        {
            temp->PrintScope(file);
            if(temp->parentScope==NULL)
            {
                break;
            }
            else
                temp=temp->parentScope;
        }
    }
    }

     void enterScope()
    {
        ScopeTable *st  =new ScopeTable(bucket_size);
        st->parentScope=present;
        this->curScope=st;
        present=curScope;
        cout<<"     New ScopeTable with id "<<Count<<" is created\n";
    }
    void exitScope()
    {
        if(curScope==NULL)
        {
             cout<<"    There is no ScopeTable to remove\n";
             return ;
        }
        else if(curScope->parentScope==NULL)
        {
            cout<<"     ScopeTable with id "<<Count<<" is removed\n";
            delete curScope;
            curScope=NULL;
            present=NULL;
            Count--;
        }
        else
        {
            cout<<"     ScopeTable with id "<<Count<<" is removed\n";
            present=curScope->parentScope;
            delete curScope;
            curScope=present;
            Count--;
        }
    }

};
/*
int main ()
{
    cout<<"enter bucket_size\n";
    cin>>bucket_size;
    SymbolTable *syt=new SymbolTable();
    syt->Enter_scope();
    while(1)
    {
        char ch;
        cin>>ch;
        if(ch=='I')
        {
            string name,type;
            cin>>name>>type;
            bool insrt;
            insrt= syt->Insert(name,type);
        }
        if(ch=='L')
        {
            string name;
            cin>>name;
            SymbolInfo *si;
            si =syt->Look_up(name);
            if(!si &&syt->curScope->parentScope!=NULL)
            {
                si=syt->curScope->parentScope->Lookup(name);
            }
            if(!si)
                cout<<"     Not found\n";
        }
        if(ch=='D')
        {
            string sname;
            cin>>sname;
            SymbolInfo *si;
            si =syt->curScope->Lookup(sname);
            if(si)
                syt->Remove(sname);
            else
                cout<<"     Not found\n";
        }
        if(ch=='P')
        {
            char c;
            cin>>c;
            if(c=='C')
            {
                syt->Print_cur_ScopeTable();
            }
            if (c=='A')
            {
                syt->Print_all_ScopeTable();
            }
        }
        if(ch=='S')
        {
            syt->Enter_scope();
        }
        if(ch=='E')
        {
            syt->Exit_scope();
        }
    }

    return 0;
}

*/






