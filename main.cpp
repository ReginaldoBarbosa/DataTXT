#include <iostream>
#include <vector>
#include <string>
#include "datatxt.h"

int main() {

	DataTXT bd("data.txt");
	
	std::vector<std::string> dados = {"name", "age", "job"}, lista;
	
	bd.setParameter(dados);
	
	bd.add({"Robert","40","Teacher"});
	bd.add({"Rock","35","Musician"});
	bd.add({"Steave","20","Driver"});
	bd.add({"Pocketnaro","60","Prisoner"});
	
	lista = bd.list();
	
	for(auto i: lista){
		std::cout<<i<<std::endl;
	}

	std::cout<<"\n"<<std::endl;
	
	
	bd.remove({"Steave","20","Driver"});

	lista = bd.list();
	
	for(auto i: lista){
		std::cout<<i<<std::endl;
	}
	std::cout<<"\n"<<std::endl;
	
	
	bd.update({"Pocketnaro","60","Prisoner"},{"Squead","75","President"});
		
	lista = bd.list();
	
	for(auto i: lista){
		std::cout<<i<<std::endl;
	}
	std::cout<<"\n"<<std::endl;
		
    
	return 0;
}
