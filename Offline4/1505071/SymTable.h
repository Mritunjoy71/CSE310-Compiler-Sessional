
#include<bits/stdc++.h>
using namespace std;
extern ofstream log_file;
class SymbolInfo
{
public:
    string code;
    string Name;
    string Type;
	string IDType;				
	string VarType;				
	int AraSize; 			
	string FuncRet;				
	int araIndex;
	bool FuncDefined = false;	
	string match;          //rule by rule match portion
	int val;

    SymbolInfo *next;
    SymbolInfo *prev;

    vector<string> ParameterList;	

	SymbolInfo(){
	    this->Name="";
        this->Type="";
        this->next=NULL;
        this->prev=NULL;
        IDType="";
        VarType="";
        FuncRet="";
        match="";
        code="";
    }
    SymbolInfo(const SymbolInfo *sym){
		Name = sym->Name;
		Type = sym->Type;
		code = sym->code;
	}

    SymbolInfo(string type){
		VarType = type;
		this->Name="";
        this->Type="";
        this->next=NULL;
        this->prev=NULL;
        IDType="VAR";
        FuncRet="";
    }

    SymbolInfo(string name, string type){
        Name = name;
        Type = type;
        this->next=NULL;
        this->prev=NULL;
         IDType="";
        VarType="";
        FuncRet="";
    }



    ~SymbolInfo()
    {
        delete prev;
        delete next;
    }


	void setVarType(string type){
		VarType = type;

	}	

};

class ScopeTable
{
public:
    ScopeTable *parentScope;
    int st_id;
    int bucket_size;
    SymbolInfo **htable, **top;
    ScopeTable(int m ,int scop_n)
    {
        bucket_size=m;
        this->st_id=scop_n;
        htable = new SymbolInfo*[bucket_size];
        top = new SymbolInfo*[bucket_size];
        for (int i = 0; i < bucket_size; i++)
        {
            htable[i] = NULL;
            top[i] = NULL;
        }
    }
    ScopeTable()
    {
        
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
        SymbolInfo *si=lookUp(symbol_name);
        if(!si)
        {
            int hash_val = HashFunc1(symbol_name);
            SymbolInfo *entry = htable[hash_val];
            int pos=0;
            if (entry == NULL)
            {
                entry = new SymbolInfo;
                entry->Name=symbol_name;
                entry->Type=symbol_type;
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
                entry->Name=symbol_name;
                entry->Type=symbol_type;
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
        int hash_val = HashFunc1(sym->Name);
        SymbolInfo *entry = htable[hash_val];
        int pos=0;
        if (entry == NULL)
        {
            entry = new SymbolInfo;
            entry->Name=sym->Name;
            entry->Type=sym->Type;
            entry->setVarType(sym->VarType);
            entry->IDType=sym->IDType;
            entry->FuncRet=sym->FuncRet;
            
            
            entry->next = NULL;
            entry->prev = NULL;
            entry=sym;
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
            entry->Name=sym->Name;
            entry->Type=sym->Type;
            entry->setVarType(sym->VarType);
            entry->IDType=sym->IDType;
            entry->FuncRet=sym->FuncRet;
            entry->next = NULL;
            entry->prev = top[hash_val];
            entry=sym;
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
            if(entry->Name==symbol_name)
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

    SymbolInfo* lookUp(string symbol_name)
    {
        int hash_val = HashFunc1(symbol_name);
        SymbolInfo* sinfo=new SymbolInfo();
        sinfo= htable[hash_val];
        if (sinfo != NULL)
        {
            int l=0;
            while (sinfo != NULL)
            {   
                if (sinfo->Name == symbol_name)
                {
                    //cout<<"     Found  in ScopeTable #"<<this->st_id<<" at position "<<hash_val<<" , "<<l<<"\n";
                    return sinfo;
                }
                l++;
                sinfo=sinfo->next;
            }
        }
        return  NULL;
    }
    
    
    SymbolInfo* lookUpVar(string symbol_name,string idtype)
    {
        int hash_val = HashFunc1(symbol_name);
        SymbolInfo* sinfo=new SymbolInfo();
        sinfo= htable[hash_val];
        if (sinfo != NULL)
        {
            int l=0;
            while (sinfo != NULL)
            {   
                if (sinfo->Name == symbol_name && sinfo->IDType==idtype)
                {
                    //cout<<"     Found  in ScopeTable #"<<this->st_id<<" at position "<<hash_val<<" , "<<l<<"\n";
                    return sinfo;
                }
                l++;
                sinfo=sinfo->next;
            }
        }
        return  NULL;
    }


    SymbolInfo* lookUp(SymbolInfo* si)
    {
        string symbol_name=si->Name;
        int hash_val = HashFunc1(symbol_name);
        SymbolInfo* sinfo=new SymbolInfo();
        sinfo= htable[hash_val];
        if (sinfo != NULL)
        {
            int l=0;
            while (sinfo != NULL)
            {
                if (sinfo->Name == symbol_name)
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
        file<<"ScopeTable #"<<this->st_id<<endl;
        for(i=0; i<bucket_size; i++)
        {
            if(top[i]!=NULL)
            {
                SymbolInfo *temp=htable[i];
                file<<i<<" -->";
                while(temp)
                {
                    file<<"<"<<temp->Name<<" : "<<temp->Type<<">"<<"\t";
                    temp=temp->next;
                }
                file<<"\n";
            }
            
        }
    }
};

class SymbolTable
{
public:
    int count =0;
    ScopeTable *curScope=NULL;
    SymbolTable()
    {
        curScope=NULL;
    }

    SymbolTable(int m){
        count=1;
        curScope=NULL;
        ScopeTable *st  =new ScopeTable(m,1);
        st->parentScope=NULL;
        this->curScope=st;
       // present=curScope;

    }

    ~SymbolTable()
    {
        delete curScope;
    }

    void Insert(SymbolInfo *sym){
        SymbolInfo *si=new SymbolInfo();
		si= curScope->Insert(sym);
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

    SymbolInfo* lookUp(string name)
    {

        ScopeTable *st=this->curScope;
        SymbolInfo *sil=NULL;
        while(st !=NULL)
        {
            sil=st->lookUp(name);
            if(sil !=NULL)
                break;
            st=st->parentScope;
        }
        return sil;

    }
    
    SymbolInfo* lookUpVar(string name,string idtype)
    {

        ScopeTable *st=new ScopeTable();
        st=this->curScope;
        SymbolInfo *sil=new SymbolInfo();
        sil=NULL;
        while(st !=NULL )
        {
            sil=st->lookUpVar(name,idtype);
            if(sil !=NULL)
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
        //count++;
        ScopeTable *st  =new ScopeTable(curScope->bucket_size,++count);
        st->parentScope=this->curScope;
        this->curScope=st;
       // present=curScope;
        cout<<"     New ScopeTable with id "<<count<<" is created\n";
        log_file<<"New ScopeTable with id "<<count<<" is created\n";
       
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
            cout<<"     ScopeTable with id "<<count<<" is removed\n";
            delete curScope;
            curScope=NULL;
        }
        else
        {
            cout<<"     ScopeTable with id "<<count<<" is removed\n";
            ScopeTable *st ;
            st=curScope->parentScope;
            delete curScope;
            curScope=st;
        }

    }


};
/*
int main ()
{
    //cout<<"enter bucket_size\n";
    //cin>>bucket_size;
    SymbolTable *syt=new SymbolTable(10);
    ofstream file;
    file.open("file.txt");
    while(1)
    {
        char ch;
        cin>>ch;
        if(ch=='I')
        {
            string name,type;
            cin>>name>>type;
            SymbolInfo *si=new SymbolInfo();
            si->Name=name;
            si->Type=type;
            SymbolInfo *insrt;
            insrt= syt->Insert(si);
        }
        if(ch=='L')
        {
            string name;
            cin>>name;
            SymbolInfo *si;
            si =syt->lookUp(name);
            if(!si)
                cout<<"     Not found\n";
        }
        if(ch=='D')
        {
            string sname;
            cin>>sname;
            SymbolInfo *si;
            si =syt->curScope->lookUp(sname);
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
                syt->printCurrent(file);
            }
            if (c=='A')
            {
                syt->printAll(file);
            }
        }
        if(ch=='S')
        {
            syt->enterScope();
        }
        if(ch=='E')
        {
            syt->exitScope();
        }
    }
    file.close();

    return 0;
}
*/







