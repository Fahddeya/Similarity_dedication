// Author: Fahd Deya El-din Salah El-din Ahmed
// Date: 15 Nov 2024
// Detailed explanation of the file and how program works: 
// this is similarty detecting program which simulate the sets in c++ languange (string set).
// this program takes an input in two forms first takes a text file name and read all the content .
// second it takes the string from the user directly .
// and provides some useful methods to edit in the sets.
// and it display the whole data (set1, set2, union, intersection, similarty) when choosing the display option.



#include<bits/stdc++.h>

using namespace std;



class Stringset{
    vector<string> tokens;

    void cleaning(string& word){
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        
        for(int i = 0 ; i < word.size() ; i++){
            word[i] = tolower(word[i]);
        }
    }

public:
    Stringset(){}

    Stringset(string filename){
        ifstream input(filename);
        while(!input.is_open()){
            cout<<"Error in opining file, please enter the name again: ";
            cin >> filename;
            input.open(filename);
        }
        string word;
        while(input>>word){
            cleaning(word);
            if (find(tokens.begin(), tokens.end(), word) == tokens.end()){
                tokens.push_back(word);
            }
        }
    }
   
    Stringset(string docement,bool test){
        string word;
        istringstream seperate(docement);
        while(seperate >> word){
            cleaning(word);
            if(find(tokens.begin(), tokens.end(), word) == tokens.end()){
                tokens.push_back(word);
            }
        }
    }
    
    void adding(string word){
        if(find(tokens.begin(), tokens.end(), word) != tokens.end()) {
            cout << word << " is already exists in this string vector.\n";
        } 
        else{
            tokens.push_back(word);
            cout << word << " is added.\n";
        }
    }
    
    void removig(string word){
        for(auto it = tokens.begin(); it != tokens.end();){
            if(*it == word){
                it = tokens.erase(it);
            }
            else{
                ++it;
            }
        }
    }
    
    void clearing(){tokens.clear();}
    
    int size(){return tokens.size();}
    
    void display(){
        for(int i = 0; i < tokens.size(); i++){
            cout <<"Word "<< i+1 <<": "<< tokens[i] << "\n";
        }   
    }
    
    double similarity(Stringset sec){
        Stringset intersection = *this * sec;
        double intersectionsize = intersection.size();
        double firstsize = this->size();
        double secsize = sec.size();
        return intersectionsize/sqrt(firstsize*secsize);
    }
    
     Stringset operator+(Stringset sec) {
        Stringset final;
        for (int i = 0; i < tokens.size(); i++) {
            if (find(sec.tokens.begin(), sec.tokens.end(), tokens[i]) == sec.tokens.end()) {
                final.tokens.push_back(tokens[i]);
            }
        }
        for (int i = 0; i < sec.tokens.size(); i++) {
            if (find(tokens.begin(), tokens.end(), sec.tokens[i]) == tokens.end()) {
                final.tokens.push_back(sec.tokens[i]);
            }
        }
        return final;
    }
    
    Stringset operator*(Stringset sec){
        Stringset final;
        for(int i = 0; i < tokens.size(); i++){
            if (find(sec.tokens.begin(), sec.tokens.end(), tokens[i]) != sec.tokens.end()){
                final.tokens.push_back(tokens[i]);                
            }
        }
        return final;
    }
};

int main(){
cout<<"Welcome to the similaity detecting machine.\n";
string choice; 
Stringset firstset;
Stringset secset;  
do{
    cout<<"Please choose an option.\n";
    cout<<"A) Load two files.\n";
    cout<<"B) Adding two strings.\n";
    cout<<"C) Add file and a string.\n";
    cout<<"D) Exit\n";
    cin >> choice;
    choice[0] = toupper(choice[0]);
    while(choice!="A" && choice!="B" && choice!="C" && choice!="D"){
        cout << "Error wrong choice, please try again: \n";
        cin >> choice;
        choice[0] = toupper(choice[0]);
    }
    
    if(choice == "A"){
        string filename1 , filename2;
        cout << "Enter the first file name: ";
        cin >> filename1;
        cout << "Enter the sec file name: ";
        cin >> filename2;
        firstset = Stringset(filename1);
        secset = Stringset(filename2);
        string choice2;
        do{
            cout <<"Want do you want next?\n";
            cout <<"A)Edit first set.\n";
            cout <<"B)Edit secund set.\n";
            cout <<"C)display all data.\n";
            cout <<"D)Return.\n";
            cin >> choice2; 
            choice2[0] = toupper(choice2[0]);
            while(choice2!="A" && choice2!="B" && choice2!="C" && choice2 !="D"){
                cout << "Error wrong choice, please try again: \n";
                cin >> choice2;
                choice2[0] = toupper(choice2[0]);
            }
            
            if(choice2 == "A"){
                string choice3;
                do{
                cout <<"A)Add to first set.\n";
                cout <<"B)Remove from first set.\n";
                cout <<"C)clear.\n";
                cout <<"D)return.\n";
                cin >> choice3; 
                choice3[0] = toupper(choice3[0]);
                while(choice3!="A" && choice3!="B" && choice3!="C" && choice3 != "D"){
                    cout << "Error wrong choice, please try again: \n";
                    cin >> choice3;
                    choice3[0] = toupper(choice3[0]);
                }
                if(choice3 =="A"){
                    string word;
                    cout << "Enter the word you want to add: ";
                    cin >> word;
                    firstset.adding(word);
                }
                else if(choice3 == "B"){
                    string word;
                    cout << "Enter the word you want to remove: ";
                    cin >> word;
                    firstset.removig(word);
                }
                else if(choice3 =="C"){
                    firstset.clearing();
                }
                }while(choice3!="D");
            }
            else if(choice2 == "B"){
                string choice3;
                do{
                cout <<"A)Add to second set.\n";
                cout <<"B)Remove from second set.\n";
                cout <<"C)clear.\n";
                cout <<"D)return.\n";
                cin >> choice3; 
                choice3[0] = toupper(choice3[0]);
                while(choice3!="A" && choice3!="B" && choice3!="C" && choice3 != "D"){
                    cout << "Error wrong choice, please try again: \n";
                    cin >> choice3;
                    choice3[0] = toupper(choice3[0]);
                }
                if(choice3 =="A"){
                    string word;
                    cout << "Enter the word you want to add: ";
                    cin >> word;
                    secset.adding(word);
                }
                else if(choice3 == "B"){
                    string word;
                    cout << "Enter the word you want to remove: ";
                    cin >> word;
                    secset.removig(word);
                }
                else if(choice3 =="C"){
                    secset.clearing();
                }
                }while(choice3!="D");
            }
            else if(choice2 =="C"){
                Stringset intersection, inion;
                cout<< "The words in the first set: \n";
                firstset.display();
                cout<< "The words in the secound set: \n";
                secset.display();
                intersection = firstset * secset;
                inion = firstset + secset;
                cout<< "The intersection words is: \n";
                intersection.display();
                cout<< "The union words is: \n";
                inion.display();
                cout<< "The similarity \n";
                cout << firstset.similarity(secset)<<"\n\n";
            }


        }while(choice2!="D");

    }
    else if(choice == "B"){
        string firstdoc , secdoc;
        cout << "Enter the first string: ";
        cin.ignore();
        getline(cin,firstdoc);
        cout << "Enter the sec string: ";
        getline(cin,secdoc);
        firstset = Stringset(firstdoc,true);
        secset = Stringset(secdoc,true);
        string choice2;
        do{
            cout <<"Want do you want next?\n";
            cout <<"A)Edit first set.\n";
            cout <<"B)Edit secund set.\n";
            cout <<"C)display all data.\n";
            cout <<"D)Return.\n";
            cin >> choice2; 
            choice2[0] = toupper(choice2[0]);
            while(choice2!="A" && choice2!="B" && choice2!="C" && choice2 !="D"){
                cout << "Error wrong choice, please try again: \n";
                cin >> choice2;
                choice2[0] = toupper(choice2[0]);
            }
            
            if(choice2 == "A"){
                string choice3;
                do{
                cout <<"A)Add to first set.\n";
                cout <<"B)Remove from first set.\n";
                cout <<"C)clear.\n";
                cout <<"D)return.\n";
                cin >> choice3; 
                choice3[0] = toupper(choice3[0]);
                while(choice3!="A" && choice3!="B" && choice3!="C" && choice3 != "D"){
                    cout << "Error wrong choice, please try again: \n";
                    cin >> choice3;
                    choice3[0] = toupper(choice3[0]);
                }
                if(choice3 =="A"){
                    string word;
                    cout << "Enter the word you want to add: ";
                    cin >> word;
                    firstset.adding(word);
                }
                else if(choice3 == "B"){
                    string word;
                    cout << "Enter the word you want to remove: ";
                    cin >> word;
                    firstset.removig(word);
                }
                else if(choice3 =="C"){
                    firstset.clearing();
                }
                }while(choice3!="D");
            }
            else if(choice2 == "B"){
                string choice3;
                do{
                cout <<"A)Add to second set.\n";
                cout <<"B)Remove from second set.\n";
                cout <<"C)clear.\n";
                cout <<"D)return.\n";
                cin >> choice3; 
                choice3[0] = toupper(choice3[0]);
                while(choice3!="A" && choice3!="B" && choice3!="C" && choice3 != "D"){
                    cout << "Error wrong choice, please try again: \n";
                    cin >> choice3;
                    choice3[0] = toupper(choice3[0]);
                }
                if(choice3 =="A"){
                    string word;
                    cout << "Enter the word you want to add: ";
                    cin >> word;
                    secset.adding(word);
                }
                else if(choice3 == "B"){
                    string word;
                    cout << "Enter the word you want to remove: ";
                    cin >> word;
                    secset.removig(word);
                }
                else if(choice3 =="C"){
                    secset.clearing();
                }
                }while(choice3!="D");
            }
            else if(choice2 =="C"){
                Stringset intersection, inion;
                cout<< "The words in the first set: \n";
                firstset.display();
                cout<< "The words in the secound set: \n";
                secset.display();
                intersection = firstset * secset;
                inion = firstset + secset;
                cout<< "The intersection words is: \n";
                intersection.display();
                cout<< "The union words is: \n";
                inion.display();
                cout<< "The similarity \n";
                cout << firstset.similarity(secset)<<"\n\n";
            }


        }while(choice2!="D");

    }

    else if(choice == "C"){
        string firstdoc , secdoc;
        cout << "Enter the file name: ";
        cin.ignore();
        getline(cin,firstdoc);
        cout << "Enter the string: ";
        getline(cin,secdoc);
        firstset = Stringset(firstdoc);
        secset = Stringset(secdoc,true);
        string choice2;
        do{
            cout <<"Want do you want next?\n";
            cout <<"A)Edit first set.\n";
            cout <<"B)Edit secund set.\n";
            cout <<"C)display all data.\n";
            cout <<"D)Return.\n";
            cin >> choice2; 
            choice2[0] = toupper(choice2[0]);
            while(choice2!="A" && choice2!="B" && choice2!="C" && choice2 !="D"){
                cout << "Error wrong choice, please try again: \n";
                cin >> choice2;
                choice2[0] = toupper(choice2[0]);
            }
            
            if(choice2 == "A"){
                string choice3;
                do{
                cout <<"A)Add to first set.\n";
                cout <<"B)Remove from first set.\n";
                cout <<"C)clear.\n";
                cout <<"D)return.\n";
                cin >> choice3; 
                choice3[0] = toupper(choice3[0]);
                while(choice3!="A" && choice3!="B" && choice3!="C" && choice3 != "D"){
                    cout << "Error wrong choice, please try again: \n";
                    cin >> choice3;
                    choice3[0] = toupper(choice3[0]);
                }
                if(choice3 =="A"){
                    string word;
                    cout << "Enter the word you want to add: ";
                    cin >> word;
                    firstset.adding(word);
                }
                else if(choice3 == "B"){
                    string word;
                    cout << "Enter the word you want to remove: ";
                    cin >> word;
                    firstset.removig(word);
                }
                else if(choice3 =="C"){
                    firstset.clearing();
                }
                }while(choice3!="D");
            }
            else if(choice2 == "B"){
                string choice3;
                do{
                cout <<"A)Add to second set.\n";
                cout <<"B)Remove from second set.\n";
                cout <<"C)clear.\n";
                cout <<"D)return.\n";
                cin >> choice3; 
                choice3[0] = toupper(choice3[0]);
                while(choice3!="A" && choice3!="B" && choice3!="C" && choice3 != "D"){
                    cout << "Error wrong choice, please try again: \n";
                    cin >> choice3;
                    choice3[0] = toupper(choice3[0]);
                }
                if(choice3 =="A"){
                    string word;
                    cout << "Enter the word you want to add: ";
                    cin >> word;
                    secset.adding(word);
                }
                else if(choice3 == "B"){
                    string word;
                    cout << "Enter the word you want to remove: ";
                    cin >> word;
                    secset.removig(word);
                }
                else if(choice3 =="C"){
                    secset.clearing();
                }
                }while(choice3!="D");
            }
            else if(choice2 =="C"){
                Stringset intersection, inion;
                cout<< "The words in the first set: \n";
                firstset.display();
                cout<< "The words in the secound set: \n";
                secset.display();
                intersection = firstset * secset;
                inion = firstset + secset;
                cout<< "The intersection words is: \n";
                intersection.display();
                cout<< "The union words is: \n";
                inion.display();
                cout<< "The similarity \n";
                cout << firstset.similarity(secset)<<"\n\n";
            }


        }while(choice2!="D");

    }
}while (choice != "D");

cout <<"good bye :)";
}
