#include <iostream>
using namespace std;

int main ()
{

int i = 0;
double vk_array[5] = 
{
2.0,
3.0, 
5.0,
2.0,
3.0,} ; //array containing a range of voltage values simulated by the solar emulator
double ik_array[5]= 
{
1.0,
2.0,
4.0,
6.0,
1.0,}; //array containing a range of current values simulated by the solar emulator

double pk_value; // a pseudo variable to store powers values in between
double mppt_value; // double variable to store the MPPT value 

// if the difference of power between previous index point compared to the current index point has no difference
// or if the index exceeds the capacity of the arrays, exit the loop
    for ( pk_value = (vk_array[i]*ik_array[i]) ;
        (vk_array[i+1]*ik_array[i+1]) - (vk_array[i]*ik_array[i])!= 0 
         &&  //and index not more than 4 
        (i<=4); 
        i++) 
    {         
        cout << "Value " << pk_value << endl << endl;  // check highest value
         
         if ( (vk_array[i+1]*ik_array[i+1]) > (vk_array[i]*ik_array[i]) 
             && ((i+1) < 5) ) //if next array value is more than previous and index does not exceed 4 to prevent garbage value 
         {                    //then you...
             pk_value =  vk_array[i+1]*ik_array[i+1] ; // update max_ptt value for now
         }     
    }
        mppt_value = pk_value; // not necessary
        cout << "The max MPPT value outputted by the solar panel is : " << pk_value << endl << endl; 
        return 0;
}

