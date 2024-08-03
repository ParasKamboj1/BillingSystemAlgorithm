#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<endl<<"Total number of persons = ";
    cin>>n;
    cout<<endl;
    string persons[n];
    for(int i=0;i<n;i++){
        cout<<"Person "<<i<<" name = ";
        cin>>persons[i];
    }
    cout<<endl<<"Please remember these person's number."<<endl;
    double rupees[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rupees[i][j] = 0;
        }
    }
    while(true){
        cout<<endl;
        int personnumber,number;
        double amount;
        cout<<"Write the person number who gave money = ";
        cin>>personnumber;
        cout<<"Amount of money = ";
        cin>>amount;
        cout<<"For number of persons = ";
        cin>>number;
        int borrowedby[number];
        double distributed_amount = (double)amount/number;
        cout<<"Write number's of those persons in always new line :\n";
        for(int k=0;k<number;k++){
            cin>>borrowedby[k];
        }
        for(int k=0;k<number;k++){
            rupees[personnumber][borrowedby[k]] = rupees[personnumber][borrowedby[k]] + distributed_amount;
            if(rupees[personnumber][borrowedby[k]] > rupees[borrowedby[k]][personnumber]){
                rupees[personnumber][borrowedby[k]] = rupees[personnumber][borrowedby[k]]-rupees[borrowedby[k]][personnumber];
                rupees[borrowedby[k]][personnumber] = 0;
            }
            else if(rupees[personnumber][borrowedby[k]] < rupees[borrowedby[k]][personnumber]){
                rupees[borrowedby[k]][personnumber] = rupees[borrowedby[k]][personnumber]-rupees[personnumber][borrowedby[k]];
                rupees[personnumber][borrowedby[k]] = 0;
            }
            else{
                rupees[personnumber][borrowedby[k]] = 0;
                rupees[borrowedby[k]][personnumber] = 0;
            }
        }
        int c;
        cout<<endl<<"For continue Press 1."<<endl<<"For exit Press 0."<<endl;
        cin>>c;
        if(c==0){
            break;
        }
    }
    cout<<endl<<"The bill for each person is :\n";
    cout<<endl;
    for(int i=0;i<n;i++){
        double total = 0;
        for(int j=0;j<n;j++){
            if(i!=j){
                cout<<persons[i]<<" will pay to "<<persons[j]<<" = "<<rupees[j][i]<<" Rupees."<<endl;
                total = rupees[j][i] + total;
            }
        }
        cout<<"Total amount "<<persons[i]<<" will pay is "<<total<<" Rupees."<<endl<<endl;
    }
    return 0;
}