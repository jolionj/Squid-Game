//Toma Alexandru-Ionel // 322AC
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;

class Person{ //class
private:
    string city; // Encapsulation
public:
    string given_name;
    string family_name;
    string type="competitor";
    int debt;
    int weight;
    int prize=0;

    void setCity(string city){ // setters
        this->city=city;
    }

    string getCity(){ // getters
        return this->city;
    }

    void show(string x){ // Polymorphism
        cout<<"Team "<<x<<" won the most money ";
    }

    void show(int x){ // Overloading
        cout<<"Team "<<x<<" won the most money ";
    }

};

class Competitor : public Person{ // Inheritance
public:
    int contest_number;
    string status="alive";
    string team;
    string teamTOW;
    int numberG;
    Competitor(){ // Constructor
    }
    ~Competitor(){ // Deconstructor
    };
};

class Supervisor : public Person{
public:
    string mask;
};

class Winner{ //Abstract class
public:
    virtual void function() = 0; // Abstraction

    virtual void print(){
        cout<<"Winner ";
    }

};

template<typename X> // Template, concatenation of any 2 data types with a space between them
void concat(X p1, X p2){
    cout<<p1<<" "<<p2;
}

Person p1[200]; // Object
int length_p=108;

Competitor c1[200];
int length_c=99;

Supervisor s1[200];
int length_s=9;

int pick_random(int a, int b){ // picks a random number between a and b

    int x;
    x = (rand() % (b-a+1)) + a;
    return x;

}

void read_file(){ // read the file

    fstream file;
    string word, filename;
    int k=1;

    filename = "Data.txt";

    file.open(filename.c_str());
    file >> word;

    while (k!=length_p+1)
    {
        p1[k].given_name=word; file >> word;
        p1[k].family_name=word; file >> word;
        p1[k].setCity(word); file >> word;
        k++;
    }

    file.close();
}

void set_weight(){ // set random weight
    int k=1;
    while (k!=length_p+1){
        p1[k].weight=pick_random(50, 100);
        k++;
    }
}

void set_debt(){ // set random debt
    int k=1;
    while (k!=length_p+1){
        p1[k].debt=pick_random(1000, 10000)*10;
        k++;
    }
}

void write_file(){ // write a file
    ofstream MyFile("Results1.txt");
    MyFile << "Results1.";
    MyFile.close();
}

void pick_type_gen(){ // set random supervisor or competitor and then team rectangle,triangle or circle

    int x,k=1,i;;

     i=1;
     while(i!=length_s+1){
         x=pick_random(1, 108);
         if(p1[x].type!="supervisor"){
                    p1[x].type="supervisor";
                    i++;
                }
     }

    for(i=1; i<=length_p; i++){
        if(p1[i].type=="competitor"){
            c1[i].contest_number=k;
            k++;
        }
      }

    i=1;

    int rec_c=0;
    int tr_c=0;
    int cir_c=0;

    for(i=1; i<=length_p; i++) {

         if(p1[i].type=="supervisor"){

                x=pick_random(1, 3);

                if(x==1) {
                    if(rec_c!=3) {
                        rec_c++;
                        s1[i].mask="rectangle";
                    }
                    else if(tr_c!=3) {
                        tr_c++;
                        s1[i].mask="triangle";
                    }
                    else if(cir_c!=3) {
                        cir_c++;
                        s1[i].mask="circle";
                    }
                }

                else if(x==2) {
                    if(tr_c!=3) {
                        tr_c++;
                        s1[i].mask="triangle";
                    }
                    else if(cir_c!=3) {
                        cir_c++;
                        s1[i].mask="circle";
                    }
                    else if(rec_c!=3) {
                        rec_c++;
                        s1[i].mask="rectangle";
                    }
                }

                else if(x==3) {
                    if(cir_c!=3) {
                        cir_c++;
                        s1[i].mask="circle";
                    }
                    else if(tr_c!=3) {
                        tr_c++;
                        s1[i].mask="triangle";
                    }
                    else if(rec_c!=3) {
                        rec_c++;
                        s1[i].mask="rectangle";
                    }
                }
                }
     }



    }

void pick_type_triangle(){ // between supervisors, team triangle, divides random in 3 triangle1,triangle2 or triangle3

    int i,x;
    int rec_c=0;
    int tr_c=0;
    int cir_c=0;

    for(i=1; i<=length_p; i++) {

         if(p1[i].type=="supervisor")
            if(s1[i].mask=="triangle"){

                x=pick_random(1, 3);

                if(x==1) {
                    if(rec_c!=1) {
                        rec_c++;
                        s1[i].mask="triangle1";
                    }
                    else if(tr_c!=1) {
                        tr_c++;
                        s1[i].mask="triangle2";
                    }
                    else if(cir_c!=1) {
                        cir_c++;
                        s1[i].mask="triangle3";
                    }
                }

                else if(x==2) {
                    if(tr_c!=1) {
                        tr_c++;
                        s1[i].mask="triangle2";
                    }
                    else if(cir_c!=1) {
                        cir_c++;
                        s1[i].mask="triangle3";
                    }
                    else if(rec_c!=1) {
                        rec_c++;
                        s1[i].mask="triangle1";
                    }
                }

                else if(x==3) {
                    if(cir_c!=1) {
                        cir_c++;
                        s1[i].mask="triangle3";
                    }
                    else if(tr_c!=1) {
                        tr_c++;
                        s1[i].mask="triangle2";
                    }
                    else if(rec_c!=1) {
                        rec_c++;
                        s1[i].mask="triangle1";
                    }
                }
                }
     }



    }

void pick_type_circle(){ // same as above but for team circle

    int i,x;
    int rec_c=0;
    int tr_c=0;
    int cir_c=0;

    for(i=1; i<=length_p; i++) {

         if(p1[i].type=="supervisor")
            if(s1[i].mask=="circle"){

                x=pick_random(1, 3);

                if(x==1) {
                    if(rec_c!=1) {
                        rec_c++;
                        s1[i].mask="circle1";
                    }
                    else if(tr_c!=1) {
                        tr_c++;
                        s1[i].mask="circle2";
                    }
                    else if(cir_c!=1) {
                        cir_c++;
                        s1[i].mask="circle3";
                    }
                }

                else if(x==2) {
                    if(tr_c!=1) {
                        tr_c++;
                        s1[i].mask="circle2";
                    }
                    else if(cir_c!=1) {
                        cir_c++;
                        s1[i].mask="circle3";
                    }
                    else if(rec_c!=1) {
                        rec_c++;
                        s1[i].mask="circle1";
                    }
                }

                else if(x==3) {
                    if(cir_c!=1) {
                        cir_c++;
                        s1[i].mask="circle3";
                    }
                    else if(tr_c!=1) {
                        tr_c++;
                        s1[i].mask="circle2";
                    }
                    else if(rec_c!=1) {
                        rec_c++;
                        s1[i].mask="circle1";
                    }
                }
                }
     }



    }

void pick_type_rectangle(){ // same but for team rectangle

    int i,x;
    int rec_c=0;
    int tr_c=0;
    int cir_c=0;

    for(i=1; i<=length_p; i++) {

         if(p1[i].type=="supervisor")
            if(s1[i].mask=="rectangle"){

                x=pick_random(1, 3);

                if(x==1) {
                    if(rec_c!=1) {
                        rec_c++;
                        s1[i].mask="rectangle1";
                    }
                    else if(tr_c!=1) {
                        tr_c++;
                        s1[i].mask="rectangle2";
                    }
                    else if(cir_c!=1) {
                        cir_c++;
                        s1[i].mask="rectangle3";
                    }
                }

                else if(x==2) {
                    if(tr_c!=1) {
                        tr_c++;
                        s1[i].mask="rectangle2";
                    }
                    else if(cir_c!=1) {
                        cir_c++;
                        s1[i].mask="rectangle3";
                    }
                    else if(rec_c!=1) {
                        rec_c++;
                        s1[i].mask="rectangle1";
                    }
                }

                else if(x==3) {
                    if(cir_c!=1) {
                        cir_c++;
                        s1[i].mask="rectangle3";
                    }
                    else if(tr_c!=1) {
                        tr_c++;
                        s1[i].mask="rectangle2";
                    }
                    else if(rec_c!=1) {
                        rec_c++;
                        s1[i].mask="rectangle1";
                    }
                }
                }
     }



    }

void pick_team(){ // divides competitors in 3 teams rectangle,triangle or circle

    int x,i;

    int rec_c=0;
    int tr_c=0;
    int cir_c=0;

    for(i=1; i<=length_p; i++){
        if(p1[i].type=="competitor"){

                x=pick_random(1, 3);

                if(x==1) {
                    if(rec_c!=33) {
                        rec_c++;
                        c1[i].team="rectangle";
                    }
                    else if(tr_c!=33) {
                        tr_c++;
                        c1[i].team="triangle";
                    }
                    else if(cir_c!=33) {
                        cir_c++;
                        c1[i].team="circle";
                    }
                }

                else if(x==2) {
                    if(tr_c!=33) {
                        tr_c++;
                        c1[i].team="triangle";
                    }
                    else if(cir_c!=33) {
                        cir_c++;
                        c1[i].team="circle";
                    }
                    else if(rec_c!=33) {
                        rec_c++;
                        c1[i].team="rectangle";
                    }
                }

                else if(x==3) {
                    if(cir_c!=33) {
                        cir_c++;
                        c1[i].team="circle";
                    }
                    else if(tr_c!=33) {
                        tr_c++;
                        c1[i].team="triangle";
                    }
                    else if(rec_c!=33) {
                        rec_c++;
                        c1[i].team="rectangle";
                    }
                }
                }
    }




}

void pick_team_rectangle(){ // divides competitors from team rectangle in 3 teams rectangle1,rectangle2 or rectangle3

    int x,i;

    int rec_c=0;
    int tr_c=0;
    int cir_c=0;

    for(i=1; i<=length_p; i++){
        if(p1[i].type=="competitor")
            if(c1[i].team=="rectangle"){

                x=pick_random(1, 3);

                if(x==1) {
                    if(rec_c!=11) {
                        rec_c++;
                        c1[i].team="rectangle1";
                    }
                    else if(tr_c!=11) {
                        tr_c++;
                        c1[i].team="rectangle2";
                    }
                    else if(cir_c!=11) {
                        cir_c++;
                        c1[i].team="rectangle3";
                    }
                }

                else if(x==2) {
                    if(tr_c!=11) {
                        tr_c++;
                        c1[i].team="rectangle2";
                    }
                    else if(cir_c!=11) {
                        cir_c++;
                        c1[i].team="rectangle3";
                    }
                    else if(rec_c!=11) {
                        rec_c++;
                        c1[i].team="rectangle1";
                    }
                }

                else if(x==3) {
                    if(cir_c!=11) {
                        cir_c++;
                        c1[i].team="rectangle3";
                    }
                    else if(tr_c!=11) {
                        tr_c++;
                        c1[i].team="rectangle2";
                    }
                    else if(rec_c!=11) {
                        rec_c++;
                        c1[i].team="rectangle1";
                    }
                }
                }
    }




}

void pick_team_circle(){ // same but for team circle

    int x,i;

    int rec_c=0;
    int tr_c=0;
    int cir_c=0;

    for(i=1; i<=length_p; i++){
        if(p1[i].type=="competitor")
            if(c1[i].team=="circle"){

                x=pick_random(1, 3);

                if(x==1) {
                    if(rec_c!=11) {
                        rec_c++;
                        c1[i].team="circle1";
                    }
                    else if(tr_c!=11) {
                        tr_c++;
                        c1[i].team="circle2";
                    }
                    else if(cir_c!=11) {
                        cir_c++;
                        c1[i].team="circle3";
                    }
                }

                else if(x==2) {
                    if(tr_c!=11) {
                        tr_c++;
                        c1[i].team="circle2";
                    }
                    else if(cir_c!=11) {
                        cir_c++;
                        c1[i].team="circle3";
                    }
                    else if(rec_c!=11) {
                        rec_c++;
                        c1[i].team="circle1";
                    }
                }

                else if(x==3) {
                    if(cir_c!=11) {
                        cir_c++;
                        c1[i].team="circle3";
                    }
                    else if(tr_c!=11) {
                        tr_c++;
                        c1[i].team="circle2";
                    }
                    else if(rec_c!=11) {
                        rec_c++;
                        c1[i].team="circle1";
                    }
                }
                }
    }




}

void pick_team_triangle(){ // same but for team triangle

    int x,i;

    int rec_c=0;
    int tr_c=0;
    int cir_c=0;

    for(i=1; i<=length_p; i++){
        if(p1[i].type=="competitor")
            if(c1[i].team=="triangle"){

                x=pick_random(1, 3);

                if(x==1) {
                    if(rec_c!=11) {
                        rec_c++;
                        c1[i].team="triangle1";
                    }
                    else if(tr_c!=11) {
                        tr_c++;
                        c1[i].team="triangle2";
                    }
                    else if(cir_c!=11) {
                        cir_c++;
                        c1[i].team="triangle3";
                    }
                }

                else if(x==2) {
                    if(tr_c!=11) {
                        tr_c++;
                        c1[i].team="triangle2";
                    }
                    else if(cir_c!=11) {
                        cir_c++;
                        c1[i].team="triangle3";
                    }
                    else if(rec_c!=11) {
                        rec_c++;
                        c1[i].team="triangle1";
                    }
                }

                else if(x==3) {
                    if(cir_c!=11) {
                        cir_c++;
                        c1[i].team="triangle3";
                    }
                    else if(tr_c!=11) {
                        tr_c++;
                        c1[i].team="triangle2";
                    }
                    else if(rec_c!=11) {
                        rec_c++;
                        c1[i].team="triangle1";
                    }
                }
                }
    }




}

void RedLightGreenLight(){ // first game RedLightGreenLight

    for(int i=1; i<=length_p; i++){
            if(p1[i].type=="competitor"){
                if(c1[i].contest_number%2==0)
                    c1[i].status="dead RedLightGreenLight";
            }
    }

}

void show_RedLightGreenLight(){ // prints the survivors after the first game

cout<<"Alive competitors after Red Light Green Light:"<<endl;

for(int i=1; i<=length_p; i++){
            if(p1[i].type=="competitor"){
                if(c1[i].status=="alive"){
                    cout<<p1[i].given_name<<" "
                    <<p1[i].family_name<<endl;
                }
            }
    }
}

void TugofWar_1(){ // divides the players in 4 team for Tug of War

    int alv=0,b,i,k=0;
    int v[4];
    for(int i=1; i<=length_p; i++){
            if(p1[i].type=="competitor"){
                if(c1[i].status=="alive"){
                    alv++;
                    v[k]=i;
                    k++;
                }
            }
    }

    b=alv%4;

    for(i=0; i<=b; i++)
        c1[v[i]].teamTOW="skip TOW";

    int x;
    int team_1=0;
    int team_2=0;
    int team_3=0;
    int team_4=0;

    for(i=v[b]; i<=length_p; i++){
        if(p1[i].type=="competitor")
            if(c1[i].status=="alive")
            {
                x=pick_random(1, 4);

                if(x==1) {
                    if(team_1!=alv/4) {
                        team_1++;
                        c1[i].teamTOW="TOW team 1";
                    }
                    else if(team_2!=alv/4) {
                        team_2++;
                        c1[i].teamTOW="TOW team 2";
                    }
                    else if(team_3!=alv/4) {
                        team_3++;
                        c1[i].teamTOW="TOW team 3";
                    }
                    else if(team_4!=alv/4) {
                        team_4++;
                        c1[i].teamTOW="TOW team 4";
                    }
                }

                else if(x==2) {
                    if(team_2!=alv/4) {
                        team_2++;
                        c1[i].teamTOW="TOW team 2";
                    }
                    else if(team_1!=alv/4) {
                        team_1++;
                        c1[i].teamTOW="TOW team 1";
                    }
                    else if(team_3!=alv/4) {
                        team_3++;
                        c1[i].teamTOW="TOW team 3";
                    }
                    else if(team_4!=alv/4) {
                        team_4++;
                        c1[i].teamTOW="TOW team 4";
                    }
                }
                else if(x==3) {
                    if(team_3!=alv/4) {
                        team_3++;
                        c1[i].teamTOW="TOW team 3";
                    }
                    else if(team_2!=alv/4) {
                        team_2++;
                        c1[i].teamTOW="TOW team 2";
                    }
                    else if(team_1!=alv/4) {
                        team_1++;
                        c1[i].teamTOW="TOW team 1";
                    }
                    else if(team_4!=alv/4) {
                        team_4++;
                        c1[i].teamTOW="TOW team 4";
                    }
                }

                 else if(x==4) {
                    if(team_4!=alv/4) {
                        team_4++;
                        c1[i].teamTOW="TOW team 4";
                    }
                    else if(team_2!=alv/4) {
                        team_2++;
                        c1[i].teamTOW="TOW team 2";
                    }
                    else if(team_3!=alv/4) {
                        team_3++;
                        c1[i].teamTOW="TOW team 3";
                    }
                    else if(team_1!=alv/4) {
                        team_1++;
                        c1[i].teamTOW="TOW team 1";
                    }
                }

                }
    }


}

void TugofWar_2(){ // eliminates the players

    int i;
    int weight_team_1=0;
    int weight_team_2=0;
    int weight_team_3=0;
    int weight_team_4=0;

    string r1,r2,r3;

    int ri1=0,ri2=0,ri3=0;

    for(i=1; i<=length_p; i++)
        if(c1[i].teamTOW=="TOW team 1")
            weight_team_1=weight_team_1+p1[i].weight;

    for(i=1; i<=length_p; i++)
        if(c1[i].teamTOW=="TOW team 2")
            weight_team_2=weight_team_2+p1[i].weight;

    for(i=1; i<=length_p; i++)
        if(c1[i].teamTOW=="TOW team 3")
            weight_team_3=weight_team_3+p1[i].weight;

    for(i=1; i<=length_p; i++)
        if(c1[i].teamTOW=="TOW team 4")
            weight_team_4=weight_team_4+p1[i].weight;

    if(weight_team_1<weight_team_2){
        r1="round 1 winner TOW team 2";
        ri1=2;
            for(i=1; i<=length_p; i++)
                if(c1[i].teamTOW=="TOW team 1")
                    c1[i].status="dead TOW round 1";
    }
    else{
        r1="round 1 winner TOW team 1";
        ri1=1;
            for(i=1; i<=length_p; i++)
                if(c1[i].teamTOW=="TOW team 2")
                    c1[i].status="dead TOW round 1";

    }

    if(weight_team_3<weight_team_4){
        r2="round 2 winner TOW team 4";
        ri2=4;
            for(i=1; i<=length_p; i++)
                if(c1[i].teamTOW=="TOW team 3")
                    c1[i].status="dead TOW round 2";


    }
    else{
        r2="round 2 winner TOW team 3";
        ri2=3;
            for(i=1; i<=length_p; i++)
                if(c1[i].teamTOW=="TOW team 4")
                    c1[i].status="dead TOW round 2";

    }

    if(ri1==1){
        if(ri2==4){
            if(weight_team_1<weight_team_4){
                ri3=4;

                for(i=1; i<=length_p; i++)
                    if(c1[i].teamTOW=="TOW team 1")
                        c1[i].status="dead TOW round 3";

            }
            else{
                ri3=1;

                for(i=1; i<=length_p; i++)
                    if(c1[i].teamTOW=="TOW team 4")
                        c1[i].status="dead TOW round 3";
            }

        }
        else{
            if(weight_team_1<weight_team_3){
                ri3=3;

                for(i=1; i<=length_p; i++)
                    if(c1[i].teamTOW=="TOW team 1")
                        c1[i].status="dead TOW round 3";
            }
            else{
                ri3=1;

                for(i=1; i<=length_p; i++)
                    if(c1[i].teamTOW=="TOW team 3")
                        c1[i].status="dead TOW round 3";
            }

        }
    }

    else{
        if(ri2==4){
            if(weight_team_2<weight_team_4){
                ri3=4;

                for(i=1; i<=length_p; i++)
                    if(c1[i].teamTOW=="TOW team 2")
                        c1[i].status="dead TOW round 3";


            }
            else{
                ri3=2;

                for(i=1; i<=length_p; i++)
                    if(c1[i].teamTOW=="TOW team 4")
                        c1[i].status="dead TOW round 3";
            }

        }
        else{
            if(weight_team_2<weight_team_3){
                ri3=3;

                for(i=1; i<=length_p; i++)
                    if(c1[i].teamTOW=="TOW team 2")
                        c1[i].status=="dead TOW round 3";
            }
            else{
                ri3=2;

                for(i=1; i<=length_p; i++)
                    if(c1[i].teamTOW=="TOW team 3")
                        c1[i].status="dead TOW round 3";
            }

        }
    }

}

void show_TugofWar(){ // prints the survivors after the second game

cout<<endl<<"Alive competitors after Tug of War:"<<endl;

for(int i=1; i<=length_p; i++){
            if(p1[i].type=="competitor"){
                if(c1[i].status=="alive"){
                    cout<<p1[i].given_name<<" "
                    <<p1[i].family_name<<endl;
                }
            }
    }

}

void Marbles(){ // the third game Marbles

    int k=1;
    int v[100],f[100];
    for(int i=1; i<=length_p; i++)
        if(p1[i].type=="competitor")
            if(c1[i].status=="alive"){
                v[k]=pick_random(1,100);
                f[k]=i;
                k++;
            }

    for(int i=1; i<k; i=i+2){
        if(v[i]>v[i+1]){
            c1[f[i]].status="dead Marbles" ;
        }
        else{
            c1[f[i+1]].status="dead Marbles" ;
        }

    }
}

void show_Marbles(){ // prints the survivors after Marbles

cout<<endl<<"Alive competitors after Marbles:"<<endl;

for(int i=1; i<=length_p; i++){
            if(p1[i].type=="competitor"){
                if(c1[i].status=="alive"){
                    cout<<p1[i].given_name<<" "
                    <<p1[i].family_name<<endl;
                }
            }
    }
}

int Genken_resolve(){ // takes 2 random number and resolves the game

    int a=pick_random(1,3);
    int b=pick_random(1,3);

    if(a==1){
        if(b==1) Genken_resolve();
        else if(b==2) return 2;
        else if(b==3) return 1;
    }

    else if(a==2){
        if(b==1) return 2;
        else if(b==2) Genken_resolve();
        else if(b==3) return 2;
    }

    else if(a==3){
        if(b==1) return 2;
        else if(b==2) return 1;
        else if(b==3) Genken_resolve();
    }

}

void Genken_compare(int comp_list[100],int k){ // returns the winner

    if(Genken_resolve()==1){

        comp_list[k+1]=comp_list[k];
        k++;
    }

    else if(Genken_resolve()==2){
        k++;

    }
}

void Genken(){ // calls the function above and print the winner

    int fin_list[100];
    int fin_list_d[100];

    int k=1,i,x,y;
    for(i=1; i<=length_p; i++)
        if(p1[i].type=="competitor")
            if(c1[i].status=="alive"){
                fin_list[k]=c1[i].contest_number;
                k++;
            }

    for(i=1; i<k; i++) fin_list_d[k-i]=fin_list[i];

    for(i=1; i<k; i++) Genken_compare(fin_list_d,i);

    cout<<endl<<"Alive competitors after Genken:"<<endl;

    for(i=1; i<=length_p; i++)
         if(p1[i].type=="competitor")
            if(c1[i].status=="alive")
                if(c1[i].contest_number==fin_list_d[k-1]){
                        cout<<p1[i].given_name<<" "
                        <<p1[i].family_name<<endl;

                        c1[i].status="winner";
                }

    for(i=1; i<=length_p; i++)
        if(p1[i].type=="competitor")
            if(c1[i].status=="alive")
                c1[i].status="dead Genken";

}

int prize_calc(string team_w){ // calculates prize for each team

     int i;
     int z;

    for(i=1; i<=length_p; i++)
        if(p1[i].type=="supervisor")
            if(s1[i].mask==team_w)
                z=i;

    for(i=1; i<=length_p; i++)
        if(p1[i].type=="competitor")
            if(c1[i].status!="winner")
                if(c1[i].team==team_w)
                    p1[z].prize=p1[z].prize+p1[i].debt;

    for(i=1; i<=length_p; i++)
        if(p1[i].type=="competitor")
            if(c1[i].status=="winner")
                if(c1[i].team==team_w)
                    p1[z].prize=p1[z].prize+(p1[i].debt*10);

     p1[z].prize=p1[z].prize-p1[z].debt;

     return p1[z].prize;
}

void swap(int *xp, int *yp) { // swap for selection sort
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[],int arr2[], int n){ // selection sort
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
        swap(&arr2[min_idx], &arr2[i]);
    }
}

void show_final(){ // calculates and prints the final requirements

     int i,z;

     for(i=1; i<=length_p; i++)
         if(p1[i].type=="competitor")
            if(c1[i].status=="winner")
                z=i;

     for(i=1; i<=length_p; i++)
         if(p1[i].type=="competitor")
            if(c1[i].status!="winner")
                p1[z].prize=p1[z].prize+p1[i].debt;

    concat<string>("Winner","prize "); // Use of template concat
    cout<<p1[z].prize<<endl;

    int prize_c=prize_calc("circle1")+prize_calc("circle2")+prize_calc("circle3");

    int prize_r=prize_calc("rectangle1")+prize_calc("rectangle2")+prize_calc("rectangle3");

    int prize_t=prize_calc("triangle1")+prize_calc("triangle2")+prize_calc("triangle3");

    int v[10],f[10];
    int k=0;

    for(i=1; i<=length_p; i++)
        if(p1[i].type=="supervisor"){
            v[k]=p1[i].prize;
            f[k]=i;
            k++;
        }

    selectionSort(v,f,k);

    cout<<endl;

    for(i=0; i<k; i++)
        cout<<p1[f[k-i-1]].given_name<<" "<<p1[f[k-i-1]].family_name<<" "<<p1[f[k-i-1]].prize<<endl;

    cout<<endl;


    try{  //Exceptions
        if(prize_c>prize_t) if(prize_c>prize_r){
            p1[1].show("circle");
            cout<<prize_t<<endl;
        }
        if(prize_t>prize_c) if(prize_t>prize_r){
            p1[1].show("triangle");
            cout<<prize_t<<endl;
        }
        if(prize_r>prize_t) if(prize_r>prize_c){
            p1[1].show("rectangle");
            cout<<prize_t<<endl;
        }
    }
     catch (...) {
         cout << "No clear winner for supervisor team."<< endl;
    }

}

int main(){ // calls above functions

    srand(time(0));
    read_file();
    set_weight();
    set_debt();

    pick_type_gen();
    pick_type_circle();
    pick_type_triangle();
    pick_type_rectangle();

    pick_team();
    pick_team_rectangle();
    pick_team_triangle();
    pick_team_circle();

    RedLightGreenLight();
    show_RedLightGreenLight();

    TugofWar_1();
    TugofWar_2();
    show_TugofWar();

    Marbles();
    show_Marbles();

    Genken();

    show_final();

    system("pause");

}
