void sum_anti_diagonal(int arr1[3][3],int column, int row ){
	int sum=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			
				cout<<arr1[i][j];
		}
		cout<<endl;
	
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			if(j+i==(column-1)){
				sum+=arr1[i][j];
			}	
		}
	
	}
	cout<<sum;
}



