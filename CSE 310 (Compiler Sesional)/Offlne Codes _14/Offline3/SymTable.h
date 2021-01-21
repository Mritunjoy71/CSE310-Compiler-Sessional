#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

//int loc=0;
/*
union vartype{
	int n;
	float f;
	char c;
};
*/
class SymbolInfo{
private:
    string Name;
    string Type;
	string IDType;				//VAR, ARA, FUNC
	string VarType;				//INT, FLOAT, STRING, CHAR
	int AraSize; 				//CONST_INT
	string FuncRet;				//INT, FLOAT, VOID
	int araIndex;	
	bool FuncDefined = false;	//true, false	//true,false

public:

	vector<string> ParamList;	//INT, FLOAT, STRING, CHAR
	vector AraElem;	//INT, FLOAT, STRING, CHAR
	
    SymbolInfo(){
    }
	
	SymbolInfo(string type){
		VarType = type;
    }

    SymbolInfo(string name, string type){
        Name = name;
        Type = type;
    }

    void setName(string name){	Name = name;	}
    void setType(string type){ 	Type = type;	}
	void setIDType(string type){IDType = type;	}
	void setVarType(string type){VarType = type;}
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

};

class ScopeTable{
private:

    vector<SymbolInfo>* symbols;
    ScopeTable* parentScope;
    int mod;
    int ID;

public:

    ScopeTable(){
        parentScope = NULL;
    }

    ScopeTable(int M,int id){
        mod = M;
        symbols = new vector<SymbolInfo>[mod];
        parentScope = new ScopeTable;
        parentScope = NULL;
        ID = id;
    }

    SymbolInfo* Insert(SymbolInfo sym){
        symbols[Hash(sym)].push_back(sym);
        return &symbols[Hash(sym)][symbols[Hash(sym)].size()-1];
    }

    int Hash(SymbolInfo sym){
        int key = 0;
        string name = sym.getName();
        for(int i = 0; i< name.size(); i++)
            key += (int)name[i];
        return(key % mod);
    }

    int Hash(string name){
        int key = 0;
        for(int i = 0 ; i< name.size(); i++)
            key += (int)name[i];
        return (key % mod);
    }

    int getID(){return ID;}

    void PrintScope(ofstream& file){
        file << " ScopeTable# " << ID << endl;        
		for(int i = 0; i< mod; i++){
			if(symbols[i].size() != 0){           	
				file << " " << i << " -->";
           		for(int j = 0; j<symbols[i].size(); j++){
               		file << " < " << symbols[i][j].getName() << " : "
               		    << symbols[i][j].getType() << " > ";
           		}
         		file << endl;
			}
       	}
		file<< endl;
    }

    SymbolInfo* lookUp(string name, string type){
        int key = Hash(name);
        for(int i = 0; i< symbols[key].size(); i++){
            if(symbols[key][i].getName() == name && symbols[key][i].getIDType() == type){
                //loc = i;
                return &symbols[key][i];
            }
        }
        return NULL;
    }

    SymbolInfo* lookUp(SymbolInfo sym){
        int key = Hash(sym.getName());
        for(int i = 0; i< symbols[key].size(); i++){
            if(symbols[key][i].getName() == sym.getName() && symbols[key][i].getIDType() == sym.getIDType()){
                //loc = i;
                return &symbols[key][i];
            }
        }
        return NULL;
    }

    void Delete(string name){
        int key = Hash(name);
        int s = symbols[key].size();
        for(int i = 0; i< s; i++){
            if(symbols[key][i].getName() == name){
                if( s == 1) {
                    symbols[key].clear();

                }
                else{
                    for(int j = i; j<s-1; j++){
                        symbols[key][j] = symbols[key][j+1];
                    }
                    symbols[key].erase(symbols[key].begin() +s-1);
                    symbols[key].resize(s-1);

                }

                cout << "Deleted entry at " << key << ", "
                << i << " from ScopeTable" << endl;

                return;
            }
        }
    }
};

class SymbolTable{

private:
    vector<ScopeTable> tableStack;
    int current;
    int scopeNum;
    int mod;

public:

    SymbolTable(int m){
        scopeNum = 1;
        mod = m;
        ScopeTable newScope(mod, scopeNum);
        tableStack.push_back(newScope);
        current = 0;

    }

    bool Insert(SymbolInfo sym){
        SymbolInfo* temp = new SymbolInfo;
        temp = tableStack[current].lookUp(sym);
        if(temp == NULL){
            tableStack[current].Insert(sym);
            //cout <<"Inserted in ScopeTable# " << tableStack[current].getID()
              //  << " at position " << tableStack[current].Hash(sym) << ", "
                //<< loc << endl;
            //loc = 0;
            return true;
        }
        else{
            //cout << "< " << temp->getName()
              //  << " : " << temp->getType()
                //<< " > already exists in current ScopeTable" << endl ;
            return false;
        }
    }

	bool Insert(string name, string type){
		
        SymbolInfo* temp = new SymbolInfo;
		SymbolInfo sym(name,type);
        temp = tableStack[current].lookUp(sym);
        if(temp == NULL){
            tableStack[current].Insert(sym);
            //cout <<"Inserted in ScopeTable# " << tableStack[current].getID()
              //  << " at position " << tableStack[current].Hash(sym) << ", "
                //<< loc << endl;
            //loc = 0;
            return true;
        }
        else{
            //cout << "< " << temp->getName()
              //  << " : " << temp->getType()
                //<< " > already exists in current ScopeTable" << endl ;
            return false;
        }
    }

	SymbolInfo* InsertandGet(string name, string type){
		SymbolInfo* temp = new SymbolInfo(name, type);
		SymbolInfo* temp2 = tableStack[current].Insert(*temp);
		return temp2;
	}

    SymbolInfo* lookUp(string name, string type){
        for(int i = current; i>=0; i--){
            SymbolInfo* temp = new SymbolInfo;
            temp = tableStack[i].lookUp(name, type);
            if(temp != NULL){
                //cout << "Found in ScopeTable# " << tableStack[i].getID()
                 //   << " at position " << tableStack[i].Hash(name) << ", "
                  //  << loc << endl;
                //loc = 0;
                return temp;
            }
        }
        return NULL;

    }

    void printCurrent(ofstream& file){
        tableStack[current].PrintScope(file);
    }

    void printAll(ofstream& file){
        for(int i = current; i>= 0 ;i--){
            tableStack[i].PrintScope(file);
        }
        cout << endl;
    }

    bool Remove(string name){
        SymbolInfo* temp = new SymbolInfo;
        temp = tableStack[current].lookUp(name);
        if(temp == NULL){
            cout << "Not found" << endl;
            return false;
        }
        else{
            //cout << "Found in ScopeTable# " << tableStack[current].getID()
              //  << " at position " << tableStack[current].Hash(name) << ", "
               // << loc << endl;
            //loc = 0;

            tableStack[current].Delete(name);
        }
    }

    void enterScope(){
        ScopeTable newScope(mod,++scopeNum);
        current++;
        tableStack.push_back(newScope);
        cout << "New ScopeTable with ID " << scopeNum << " created" << endl;
    }

    void exitScope(){
        tableStack.erase(tableStack.begin()+ current--);
        cout << "ScopeTable with ID " << scopeNum-- << " removed";
        tableStack.resize(scopeNum);
    }

};

//SymbolTable table(8);
