#include "MDLlib.h"

void creaLinker(std::string sruta){

	fs::path ruta = defineRuta(sruta);

	if(!validaRuta(ruta)) return;

	std::vector<std::string> nombres = capturaNombres(ruta);

	if(nombres.empty()){
		std::cout << "No se encontro archivos .md" << std::endl;
		return;
	}

	//imprimirLista(nombres);
	creaIndex(ruta,nombres);
}

fs::path defineRuta(std::string ruta){
	if(ruta == ".") return fs::current_path();
	else return ruta;
}

void creaIndex(fs::path ruta,std::vector<std::string> nombres){
	std::string nombreIndex = ruta.filename();
	std::string indexArch = (std::string)ruta + "/" + nombreIndex + ".md";
	std::cout << "Ruta: " << ruta << std::endl;
	std::cout << "Nombre carpeta: " << nombreIndex << std::endl;
	std::cout << "Path index" << indexArch << std::endl;
	std::ofstream index;
	index.open(indexArch);

	index << "# Bienvenido al Hub de " << nombreIndex << std::endl;
	index << "#Hub" << std::endl;
	for (std::string nombre : nombres){
		index << "# [[" << nombre << "]]" << std::endl << std::endl;
	}
	std::cout << "Index creado" << std::endl;
	index.close();
}

void imprimirLista(std::vector<std::string> nombres){
	if(nombres.empty()){
		std::cout << "No se encontraron archivos" << std::endl;
		return; 
	}

	std::cout << "Archivos encontrados: " << std::endl;
	for(std::string nom : nombres){
		std::cout << nom << std::endl;
	}
}

std::vector<std::string> capturaNombres(fs::path ruta){
	std::vector<std::string> nombres;

	for(const auto & arch : fs::directory_iterator(ruta)){
		if( arch.path().extension() == ".md" )
			nombres.push_back(arch.path().filename());
	}

	return nombres;
}

bool validaRuta(fs::path ruta){
	if(exists(ruta)){
		std::cout << "Ruta recibida: " << ruta << std::endl;
		return true;
	}else{
		std::cout << "Ruta no valida" << std::endl;
		return false;
	}
}
