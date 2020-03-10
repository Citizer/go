#include <iostream>
using namespace std;

int main()
{
   float c1, c2, c3, c4, c5, c_par, c_pos;
   cout << "Program for calculating the total capacity of five capacitors in parallel and serial connections\n";
   cout << "Enter the capacity value of the first capacitor ";
   cin >> c1;
   cout << "Enter the capacity value of the second capacitor ";
   cin >> c2;
   cout << "Enter the capacity value of the first capacitor ";
   cin >> c3;
   cout << "Enter the capacity value of the first capacitor ";
   cin >> c4;
   cout << "Enter the capacity value of the first capacitor ";
   cin >> c5;
   c_par = c1 + c2 + c3 + c4 + c5;
   c_pos = 1 / c1 + 1 / c2 + 1 / c3 + 1 / c4 + 1 / c5;
   cout << "Total capacity for parallel connection " << c_par << endl;
   cout << "Total capacity for serial connection " << c_pos;
}
