#include <cstdlib>
#include <iostream>

using namespace std;

float weight1=0;
float weight2=0;
const float bias=-0.8;
const float eta=0.1;
float counter =0;
float weight_temp_1=0;
float weight_temp_2=0;
int iteration = 0;
      
/* Weight Updating Equation */      
      
void weight_updating(void)
{
     weight1+=weight_temp_1/counter;
     weight2+=weight_temp_2/counter;
     weight_temp_1=0;
     weight_temp_2=0;
     iteration++;
}

/* Error calc Equation */

int error_calc (int q, int w, int x)
{
    return (q && w)-x;
}

/* Weight calc Equation */
void weight_calc (int x1, int y1, int error)
{
     if (error == 1)
     {
               counter++;
               weight_temp_1+=eta*x1*error;
               weight_temp_2+=eta*y1*error;
     }
     
}

int hard_activation(float result_input)
{
    if (result_input>=0)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

/* Net input */
float function (float a,float b)
{ 
     float result = (a*weight1)+(b*weight2)+bias;
     return result;   
}

/* Loop for multiple calculation */

void main_calc (void)
{ 
float a;
    int cost = 0, function_output;
    for (int x=0; x<2; x++)
    {
        for (int y=0; y<2; y++)
        {
            cout<<"For values"<<" x = "<<x<<" y = "<<y<<endl;
            a = function(x,y);
            function_output = hard_activation(a);
            int t = error_calc (x,y,function_output);
            weight_calc (x,y,t); 
               
        }
    } 
weight_updating(); 

/* Weights values Equation */

cout<<"Weight 1 "<<weight1<<endl;
cout<<"Weight 2 "<<weight2<<endl;
cout<<"Iteration # "<<iteration<<endl;
cout<<endl<<endl<<"-----"<<endl<<endl;
}
    

int main(void)
{
    cout<<"Error Correction Learning Application on \"OR GATE\""<<endl<<endl;
    cout<<"Activation function is \"Hard Limiter\""<<endl<<endl;
    
    main_calc();
    
    while((counter/4)>0.1)
    {
        counter=0;
        main_calc();     
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

 
