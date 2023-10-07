ofstream file("result.txt");
    if(file.is_open()){
    	file<<"Name: "<<s1.getname()<<endl;
    	file<<"Roll no: "<<s1.outID()<<endl;
    	file<<"Age: "<<age.getyear()<<endl;
    	for(int i=1;i<4;i++){
		Mavi[i].out(i);
	    }
	    Mavi[0]=Mavi[1]+Mavi[2]+Mavi[3];
	    Mavi[0]/3;
	}
	file.close();
	system("taskkill /IM notepad.exe");
	cout<<"File closed. "<<endl;
	