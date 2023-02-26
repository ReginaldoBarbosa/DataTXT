#include "datatxt.h"
#include <iostream>

DataTXT::DataTXT(){}

DataTXT::DataTXT(std::string fileName){
    this->fileName = fileName;
}

int DataTXT::err_dadotxt(std::vector<std::string> parameters,int aux){
    if(aux == 0){
    //std::cout<<"DADOS NAO ENCONTRADOS"<<std::endl;
        return 1;
    }		

    if(this->nParameters != parameters.size()){
    //std::cout<<"QUANTIDADE DE ELEMENTOS NÃO EQUIVALE A QUANTIDADE DE PARAMETROS DEFINIDOS"<<std::endl;
        return 2;
    }

    if(this->nParameters == 0){
    //std::cout<<"PARAMETROS DE CLASSIFICAÇÃO DE DADOS NAO DEFINIDOS"<<std::endl;
        return 3;
    }

    return 0;

}

void DataTXT::setFile(std::string fileName ){
    this->fileName = fileName;
}

void DataTXT::setParameter(std::vector<std::string> parameters){

    if(this->flagParameters == 0){
        
        std::string param, space = " ";
        
        for(auto i : parameters){
            param = param + i + space;
        }
        param = param +"\n";
        std::ofstream file;
        file.open(this->fileName);
        
        file<<param;
        
        file.close();
        this->flagParameters = 1;
        this->nParameters = parameters.size();
    }
    else 
        std::cout<<"Parameters defined"<<std::endl;
}

int DataTXT::add(std::vector<std::string> data){
 			
    err_dadotxt(data);

    std::ofstream file;
    std::string dataStr = "";
    for(auto i : data){
        dataStr = dataStr + i + " ";
    }

    file.open(this->fileName,std::ios::app);
    file<<dataStr<<std::endl;
    file.close();
    return 0;   
    }

int DataTXT::remove(std::vector<std::string> data){

        
    err_dadotxt(data);

    int flag = 0;
    std::string dataStr = "", buff;
    std::fstream file, file_aux;

    file.open(this->fileName,std::ios::in);
    file_aux.open(this->Data_Aux,std::ios::app);

    for(auto i : data){
        dataStr = dataStr + i + " ";
    }			


    while(file){ 
        std::getline(file,buff);
        if(buff.compare(dataStr)!=0){
            file_aux<<buff<<"\n";
        }
        else flag++;

    } 	


    file.close();
    file_aux.close();

    file_aux.open(this->Data_Aux,std::ios::in);
    file.open(this->fileName,std::ios::out);	

    while(file_aux){ 
        std::getline(file_aux,buff);
        file<<buff<<"\n";
    } 	 

    file.close();
    file_aux.close();
    std::remove( Data_Aux.c_str());
    err_dadotxt(data,flag);
    return 0;
        

}

int DataTXT::update(std::vector<std::string> data, std::vector<std::string> newData){
            
    err_dadotxt(data);
    int flag;	
    std::string dataStr, newDataStr,buff;
    std::fstream file, file_aux;
    
    file.open(fileName,std::ios::in);
    file_aux.open(Data_Aux,std::ios::app);
    
    
    for(auto i : data){
        dataStr = dataStr + i + " ";
    }				
    
    for(auto i : newData){
        newDataStr = newDataStr + i + " ";
    }				
    
    
    while(file){ 
        std::getline(file,buff);
        if(buff.compare(dataStr)!=0){
            file_aux<<buff<<"\n";
            
        }
        else {
            file_aux<<newDataStr<<"\n";
            flag++;
        }
    } 	
    file.close();
    file_aux.close();
    
    file_aux.open(Data_Aux,std::ios::in);
    file.open(fileName,std::ios::out);	
    
    while(file_aux){ 
        std::getline(file_aux,buff);
        file<<buff<<"\n";
    } 	 
    
    file.close();
    file_aux.close();
    std::remove(Data_Aux.c_str());
    err_dadotxt(data, flag);
    return 0;

            
}

std::vector<std::string> DataTXT::list(){
    
    std::string buff; 
    std::ifstream file;  
    std::vector<std::string> listStr;
    
    file.open(this->fileName);
    
    while(file){ 
        std::getline(file,buff);
        listStr.push_back(buff);
    } 	
    
    file.close();			
    return listStr;
    
}