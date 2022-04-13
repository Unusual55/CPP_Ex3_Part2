// #include "Matrix.hpp"
// #include <iostream>
// #include <string>
// using namespace zich;

// int main(int argv, char *argc[]){
    ////Declaring on needed constants
//     bool flag=true;
//     Matrix a;
//     Matrix b;
//     string MatrixString;
//     char MChar;
//     string Estring;
////Creating the two matrix we need for the main
//     while(a.getRows()==0||b.getRows()==0){
//         cout<<"Enter M for matrix input or R for random 3x3 matrix or I for I_3"<<endl;
//         cin>>MChar;
//         if(MChar=='M'){
//             cout<<"Enter the first matrix"<<endl;
//             try{
//                 cin>>a;
//             }
//             catch(exception &e){
//                 cin>>a;
//             }
//         }
//         else if(MChar=='R'){
//             for(int i=0;i<9;i++){
//                 a= Matrix({(double)rand(), (double)rand(), (double)rand(),
//                 (double)rand(), (double)rand(), (double)rand(),
//                 (double)rand(), (double)rand(), (double)rand()},3 , 3);
//             }
//         }
//         else if(MChar=='I'){
//             a=Matrix({1,0,0,0,1,0,0,0,1}, 3, 3);
//         }
//         cout<<"Enter M for matrix input or R for random 3x3 matrix or I for I_3"<<endl;
//         cin>>MChar;
//         if(MChar=='M'){
//             cout<<"Enter the second matrix"<<endl;
//             try{
//                 cin>>b;
//             }
//             catch(exception &e){
//                 cin>>b;
//             }
//         }
//         else if(MChar=='R'){
//             for(int i=0;i<9;i++){
//                 b= Matrix({(double)rand(), (double)rand(), (double)rand(),
//                 (double)rand(), (double)rand(), (double)rand(),
//                 (double)rand(), (double)rand(), (double)rand()},3 , 3);
//             }
//         }
//         else if(MChar=='I'){
//             b=Matrix({1,0,0,0,1,0,0,0,1}, 3, 3);
//         }
//     }
////Few matrix operators for the interactive presentation
//     cout<<"Matrix A:\n"<<a<<endl;
//     cout<<"Matrix B:\n"<<b<<endl;
//     double scale;
//     cout<<"Enter a scale to multiply A by"<<endl;
//     cin>>scale;
//     cout<<scale<<"*a:\n"<<a*scale<<endl;
//     cout<<"a*b:\n"<<a*b<<endl;
//     cout<<"a+b:\n"<<a+b<<endl;
//     cout<<"a-b:\n"<<a-b<<endl;
//     cout<<"Enter a scale to add to A"<<endl;
//     cin>>scale;
//     cout<<"a+"<<scale<<":\n"<<(a+scale)<<endl;
//     cout<<"Enter a scale to substruct from B"<<endl;
//     cin>>scale;
//     cout<<"b-"<<scale<<":\n"<<b-scale<<endl;
//     cout<<"a==b\n"<<(a==b)<<endl;
//     cout<<"a!=b\n"<<(a!=b)<<endl;
//     cout<<"a<=b\n"<<(a<=b)<<endl;
//     cout<<"a>=b\n"<<(a>=b)<<endl;
//     cout<<"a<b\n"<<(a<b)<<endl;
//     cout<<"a>b\n"<<(a>b)<<endl;
// }