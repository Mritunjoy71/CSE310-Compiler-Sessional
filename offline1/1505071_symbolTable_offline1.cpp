#include<bits/stdc++.h>
using namespace std;
int bucket_size;
int Count =0;
class ScopeTable;
ScopeTable *present=NULL;
class SymbolInfo
{
private:
    string symbol_name;
    string symbol_type;
public:
    SymbolInfo *next;
    SymbolInfo *prev;

    SymbolInfo()
    {
        this->symbol_name="";
        this->symbol_type="";
        this->next=NULL;
        this->prev=NULL;
    }

    ~SymbolInfo()
    {
        delete prev;
        delete next;
    }

    void set_name_type(string symbol_name,string symbol_type)
    {
        this->symbol_name=symbol_name;
        this->symbol_type=symbol_type;
    }

    string get_symbol_name()
    {
        return this->symbol_name;
    }

    string get_symbol_type()
    {
        return this->symbol_type;
    }
};

class ScopeTable
{
public:
    ScopeTable *parentScope;
    int st_id;
    SymbolInfo **htable, **top;
    ScopeTable(int bucket_size)
    {
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

    bool Insert(string symbol_name, string symbol_type)
    {
        SymbolInfo *si=Lookup(symbol_name);
        if(!si)
        {
            int hash_val = HashFunc1(symbol_name);
            SymbolInfo *entry = htable[hash_val];
            int pos=0;
            if (entry == NULL)
            {
                entry = new SymbolInfo;
                entry->set_name_type(symbol_name,symbol_type);
                entry->next = NULL;
                entry->prev = NULL;
                htable[hash_val] = entry;
                top[hash_val] = entry;
                printf("    Inserted in ScopeTable #%d at position %d,%d\n",this->st_id,hash_val,pos);
            }
            else
            {
                while (entry != NULL)
                {
                    entry = entry->next;
                    pos++;
                }
                entry = new SymbolInfo;
                entry->set_name_type(symbol_name,symbol_type);
                entry->next = NULL;
                entry->prev = top[hash_val];
                top[hash_val]->next = entry;
                top[hash_val] = entry;
                printf("    Inserted in ScopeTable #%d at position %d,%d\n",this->st_id,hash_val,pos);
            }
            return true;
        }
        else
        {
            cout<<"    Already inserted\n";
            return false;
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
            if(entry->get_symbol_name()==symbol_name)
            {
                if(entry->prev==NULL &&entry->next!=NULL)
                {
                    entry->next->prev=NULL;
                    htable[hash_val]=entry->next;
                    delete entry;
                    cout<<"     The token is deleted\n";
                    break;
                }
                if(entry->prev!=NULL && entry->next!=NULL)
                {
                    entry->prev->next=entry->next;
                    entry->next->prev=entry->prev;
                    delete entry;
                    cout<<"     The token is deleted\n";
                    break;
                }
                if (entry->next == NULL)
                {
                    if (entry->prev == NULL)
                    {
                        htable[hash_val] = NULL;
                        top[hash_val] = NULL;
                        delete entry;
                        cout<<"     The token is deleted\n";
                        break;
                    }
                    else
                    {
                        top[hash_val] = entry->prev;
                        top[hash_val]->next = NULL;
                        delete entry;
                        cout<<"     The token is deleted\n";
                        entry = top[hash_val];
                    }
                }
            }
            entry = entry->next;
        }
    }

    SymbolInfo* Lookup(string symbol_name)
    {
        int hash_val = HashFunc1(symbol_name);
        SymbolInfo* sinfo=new SymbolInfo();
        sinfo= htable[hash_val];
        if (sinfo != NULL)
        {
            int l=0;
            while (sinfo != NULL)
            {
                if (sinfo->get_symbol_name() == symbol_name)
                {
                    cout<<"     Found  in ScopeTable #"<<this->st_id<<" at position "<<hash_val<<" , "<<l<<"\n";
                    return sinfo;
                }
                l++;
                sinfo=sinfo->next;
            }
        }
        return  0;
    }

    void Print()
    {
        int i;
        cout<<"     ScopeTable #"<<this->st_id<<endl;
        for(i=0; i<bucket_size; i++)
        {
            cout<<"\t";
            if(top[i]!=NULL)
            {
                SymbolInfo *temp=htable[i];
                cout<<i<<" -->";
                while(temp)
                {
                    cout<<"<"<<temp->get_symbol_name()<<" : "<<temp->get_symbol_type()<<">"<<"\t";
                    temp=temp->next;
                }
                cout<<"\n";
            }
            else
            {
                cout<<i<<" -->"<<endl;
            }
        }
    }
};

class SymbolTable
{
public:
    ScopeTable *curScope;
    SymbolTable()
    {
        curScope=NULL;
    }
    ~SymbolTable()
    {
        delete curScope;
    }
    void Enter_scope()
    {
        ScopeTable *st  =new ScopeTable(bucket_size);
        st->parentScope=present;
        this->curScope=st;
        present=curScope;
        cout<<"     New ScopeTable with id "<<Count<<" is created\n";
    }
    void Exit_scope()
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

    bool Insert(string symbol_name,string symbol_type)
    {
        bool insrt;
        insrt=curScope->Insert(symbol_name,symbol_type);
        return insrt;
    }
    void Remove(string symbol_name)
    {
        this->curScope->Delete(symbol_name);
    }

    SymbolInfo* Look_up(string symbol_name)
    {
        SymbolInfo *si;
        si=this->curScope->Lookup(symbol_name);
        return si;

    }

    void Print_cur_ScopeTable()
    {
        if(curScope!=NULL)
            this->curScope->Print();

    }

    void Print_all_ScopeTable()
    {
        ScopeTable *temp=this->curScope;
        while(temp!=NULL)
        {
            temp->Print();
            if(temp->parentScope==NULL)
            {
                break;
            }
            else
                temp=temp->parentScope;
        }
    }
};

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





