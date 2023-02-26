/**
 * @file datatxt.h
 * @brief This file contains the definition of the DataTXT class.
 */

#ifndef CRUDTXT_H
#define CRUDTXT_H


#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>


/**
 * @class DataTXT
 * @brief This class define the object DataTXT. 
 * 
 * It receives a constant number of parameters and need to be filled with a list which has the 
 * same number of parameters.
*/

class DataTXT {
	
	private:
		std::vector<std::string> parameters;		
		std::string fileName;
		std::string Data_Aux = "DataAux.txt";
		int flagParameters = 0;
		int nParameters = 0;
				
	public:
		/**
		 * @brief Constructs a new DataTXT object without parameter.
		 * 
		 */		
		DataTXT();

		/**
		 * @brief Constructs a new DataTXT object with the file's name defined.
		 * @param fileName Name of the file defined to create the list, type string.
		 */
		
		DataTXT(std::string fileName = "file.txt");

		/**
		 * @brief Define the erro codes of the functions.
		 * @param parameters Vector of parameters defined to the list.
		 * @param aux Auxiliary variavel which receive a diferent flag in the functions.
		 * @return A diferent integer valuo for each error, diferent of 0; 
		 */

		int err_dadotxt(std::vector<std::string> parameters,int aux = 1);
		
		/**
		 * @brief Set the file's name, in case use of the constructor DataTXT().
		 * @param fileName Name of the file defined to create the list, type string.
		 */
		
		
		void setFile(std::string fileName = "file.txt");

		/**
		 * @brief Set the name and the number of parameters of the list, it can be used once.
		 * @param parameters It's a vector of strings that define the parameters.
		 */
		
		void setParameter(std::vector<std::string> parameters);

		/**
		 * @brief Add the data string vector in the file.
		 * @param parameters It's a string vector which size is equal to nParameters
		 * @return If correct return 0, if wrong return a interger different of 0.
		 */
						
		int add(std::vector<std::string> data);

		/**
		 * @brief Remove the data string vector in the file.
		 * @param parameters It's a string vector which size is equal to nParameters and must be in the list.
		 * @return If correct return 0, if wrong return a interger different of 0.
		 */
		
		int remove(std::vector<std::string> data);

		/**
		 * @brief Update the data string vector in the file to the new data parameter.
		 * @param data It's a string vector which size is equal to nParameters, and must be in the list.
		 * @param newData It's a string vector which size is equal to nParameters.
		 * @return If correct return 0, if wrong return a interger different of 0.
		 */
		
		int update(std::vector<std::string> data, std::vector<std::string> newData);

		/**
		 * @brief List the data contained in the list.
		 * @return return a string vector which each line of the file.
		 */
		
		std::vector<std::string> list();
		
		
};

#endif