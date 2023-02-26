#include <iostream>
#include <vector>
#include <string>
#include "datatxt.h"

int main() {
	std::cout<<"oooi"<<std::endl;
	DataTXT bd("dados.txt");
	
	std::vector<std::string> dados = {"nome", "ano", "nota"}, lista;
	
	bd.setParameter(dados);
	
	bd.add({"adalberto","1ano","9.5"});
	bd.add({"regi","2ano","7.5"});
	bd.add({"ana","4ano","5.5"});
	bd.add({"lene","7ano","2.5"});
	
	lista = bd.list();
	
	for(auto i: lista){
		std::cout<<i<<std::endl;
	}

	std::cout<<"\n\n"<<std::endl;
	
	
	bd.remove({"regi","2ano","7.5"});

	lista = bd.list();
	
	for(auto i: lista){
		std::cout<<i<<std::endl;
	}
	std::cout<<"\n\n"<<std::endl;
	
	
	bd.update({"ana","4ano","5.5"},{"aninha","1ano","9.0"});
		
	lista = bd.list();
	
	for(auto i: lista){
		std::cout<<i<<std::endl;
	}
	std::cout<<"\n\n"<<std::endl;
		
    
	return 0;
}
