#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

double calculate_value(double*a, int n, double x){
    double value=0;
    for(int i=n;i>=0;i--){
        value=value + a[i]*pow(x,i);
    }
    return value;
}


double calculate_horner(double* a, double* b, int n, double x){
    double value=0;
    a[n]=b[n];
    
    for(int i=n-1;i>=0;i--){
        b[i]=a[i]+b[i+1]*x;
    }
    value=b[0];
    return value;
}
int main(){
    int n = 0;
    double *a;      //polynomial coefficient
    double *b;      //horner coefficient
    double x;       //argument in whcich will be calculated
    double limit=10000000;
    time_t beggining, end;
    
    cout<<"Give order of polynomial: ";
    cin>>n;
    n = n+1;
    
    a = new double[n];
    b = new double[n];
    
    
    for(int i=n-1;i>=0;i--){
        cout<<"Give coefficient a"<<i<<": ";
        cin>>a[i];
    }
    
    cout<<"Give the value of the argument: ";
    cin>>x;
    cout <<endl<< "Function value using Horner: " << calculate_horner(a,b,n,x)<<endl;
    
    time(&beggining);
    for (int i = 0; i < limit; i++)
    {
        calculate_horner(a,b,n,x);
    }
    time(&end);
    cout << "Horner time: " << difftime(end, beggining) << endl;
    
    time(&beggining);
    for (int i = 0; i < limit; i++)
    {
        calculate_value(a,n,x);
    }
    time(&end);
    cout<<"Function value using substitution: "<<calculate_value(a,n,x)<<endl;;
    cout << "Substitution time: " << difftime(end, beggining) << endl;
}
