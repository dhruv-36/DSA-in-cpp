// PATTERNS
void pattern (int n){           //  1 2 3 4
    //int n=4;                  //  5 6 7 8                                                           //   1  2  3
    int count=1;                //  9 10 11 12                                                          //    4  5  6
    for(int i=1;i<=n;i++){      //  13 14 15 16                                                         //     7  8  9
        for(int j=1;j<=n;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }

}


// void pattern1 (int n){
//     int count =1;
//     for (int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){                      // A B C D
//             char ch='A'+j-1;        //  VERY IMP   //  A B C D
//             cout<<ch<<" ";                        //   A B C D
//                                                   //   A B C D   
//         }
//         cout<<"\n";
//            }
// }


// void pattern2(int n){
//    // char count ='A';
//    char ch='A';     //   pehle hi initialize krdo loop se pehle for ease in further in ch++
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             cout<<ch<<" ";
//              ch++;              // ABC
//                                //  DEF
//         }                     //   HIJ
//         cout<<endl;
//     }
//}

// void pattern2(int n){
//    // char count ='A';
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             char ch='A'+i+j-1-1;    // IMPORTANT STEP
//             cout<<ch<<" ";
//                                       // ABC
//                                      //  BCD
//         }                           //   CDE
//         cout<<endl;
//     }
// }


// void pattern3(int n){
//    // char count ='A';
    
//     for(int i=1;i<=n;i++){
//         char ch='A'+ n-i;     // This helps in printing in the reverse order of the characters
//         for(int j=1;j<=i;j++){              // D                        //  Now incrementing the staritng character
//                                             // C D
//             cout<<ch<<" ";                  // B C D
//             ch++;                           // A B C D
            
                         
                               
//         }                     
//         cout<<endl;
//     }
// }



// void pattern2(int n){
//    // char count ='A';
//     for(int i=1;i<=n;i++){    //            1           tough
//         int count=1;          //           121
//         int count2=i-1;     //            12321
//         for(int j=1;j<=n-i+1;j++){  //   1234321
//             cout<<" ";
//         }
//         for(int j=n-i+1;j<=n;j++){
//             cout<<count;
//             count++;
//         }
//         for(int k=i-1 ;k>=1;k--){      // IMP: agar iteration same row mein ho gyi then same row mein iteratiion aage hi hogi chahe tum condition lgao ya na lgao bas phir ye socho ki print kya krna hai as iteration to aage hi hogi anyways.
//             cout<<k;                   // >=1 krnese upper wala row mein right triangle nji ban payega
           
//         }
                         
//         cout<<endl;
//     }
// }

// void pattern1(int n){
//     int count =1;
//     for(int i=1;i<=n;i++){
        
//         for(int j=1;j<=n-i;j++){
//             cout<<" ";
//         }
//         for(int k=1;k<=i;k++){                //     *
//             cout<<"*";                       //     **
//         }                                    //    ***      Here agar tu space print krata hai then use koi ovewrite nhi karega vo whain rahnegi then try to make another for loop with another variable  
//                                             //    ****      and just focus on the other pattern irrespective of the space pritned
//                                             //   *****
       
//         cout<<endl;
//     }
// }

// void pattern1(int n){
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(i==1||j==1||i==n||j==n){            //     * * * *
//                 cout<<"*";                         //     *     *
//             }                                     //      *     *                 * in the boundary condition i.e for i=1,n and j=1,n
//             else{                                //       * * * *                 else " " in rest of the conditions
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }




// void pattern1(int n){
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(i==n||j==1||(i==j)){                //     * 
//                 cout<<"*";                         //     * *   
//             }                                     //      * * *                    * in the boundary condition i.e for i=1, j=1, and i=j
//             else{                                //       * * * *                    else " " in rest of the conditions
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }


