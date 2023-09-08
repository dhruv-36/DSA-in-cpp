//  void fibbonacci(int n){
//     cout<<0<<" "<<1;
//      int a=0;                                              // FIBBINACCI  0 1 1 2 3 5 8
//     int b=1;
//     for(int i=0;i<n-2;i++){

       
//         int nextsum=a+b;
//         cout<<" "<<nextsum<<" ";
//         a=b;    
//         b=nextsum;
//     }
// }



// void decimal_to_binary(int n){
//     cout<<n<<endl;
//     int bit;
//     int binary=0;
//     int i=0;
//     while(n!=0){
//         bit=n&1;
//         binary=bit*pow(10,i) + binary;     // IMPORTANT STEP
//         n=n>>1;
//         i++;

//     }
//     cout<<binary<<endl;
   
    
// }

void binary_to_decimal(int n){
    int decimal=0;
    int i=0;
    while(n!=0){
        int rem=n%10;
        if(rem==1){
            decimal=decimal+(rem*pow(2,i));
        }
        i++;
        n=n/10;
    }
    cout<<decimal;
}
