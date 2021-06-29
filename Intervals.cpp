#include <iostream>
#include <math.h>


using namespace std;

void interval (double* a, int n){
    
    double x=0;
    double* b = new double[n+1];
    double alfa,beta;
    double epsilon=0.000001;
    bool condition = true;
    bool found;
    
    double* p= new double[n+1];
    
    //------------------------- BETA
    b[n]=a[n];
    while(condition){
        x += epsilon;
        found = false;
        for(int i=n-1; i>=0; i--){
            b[i]=a[i]+b[i+1]*x;
            if(b[i]<=0){
                found=true;
                break;
            }
        }
        if(!found)
            condition=false;
    }
    beta = x;
   
  //-------------------------- ALFA
    
    
    for(int i=n; i>=0; i--){
        p[i] = pow(-1,n) * pow(-1,i)*a[i];
        
        cout<<p[i]<<endl;
    }
    
    x=0;
    condition=true;
    
    while(condition){
        x += epsilon;
        found = false;
        for(int i=n-1; i>=0; i--){
            b[i]=p[i]+b[i+1]*x;
            if(b[i]<=0){
                found=true;
                break;
            }
        }
        if(!found)
            condition=false;
    }
    alfa = -x;
    cout<<"All real roots are contained in the interval <"<<alfa<<", "<<beta<<">"<<endl;
}

int main(){
    int n;
    cout<<"Give order of polynomial: ";
    cin>>n;
    cout<<endl;
    
    double*a =new double[n+1];
    
    for(int i=n;i>=0;i--){
        cout<<"Give the coefficient a"<<i<<": ";
        cin>>a[i];
    }
    
 interval(a,n);
}

