
#include "MDlib.h"

void MDlinker(std::string sruta){

	StrIndex data;

	if(!fs::exists(sruta)) return;

	inicializar(data,sruta);

	if(fs::exists(data.archIndex)){
		//actualizaLinker();
	}else{
		creaIndex(data);
	}
	
}

void inicializar(StrIndex& data, std::string sruta){
	data.ruta = defineRuta(sruta);
	data.nombreIndex = data.ruta.filename();
	data.archIndex = (std::string)data.ruta + "/" + data.nombreIndex + ".md";	
}

fs::path defineRuta(std::string ruta){
	if(ruta == ".") return fs::current_path();
	else{
		ruta.erase(ruta.length()-1);
		return ruta;
	}
}

void creaIndex(StrIndex data){
	
	std::vector<std::string> nombres = capturaNombres(data.ruta);

	if(nombres.empty()){
		std::cout << "No se encontro archivos .md" << std::endl;
		return;
	}
	
	std::cout << "Ruta: " << data.ruta << std::endl;
	std::cout << "Nombre carpeta: " << data.nombreIndex << std::endl;
	std::cout << "Path index: " << data.archIndex << std::endl;
	
	std::ofstream index;
	index.open(data.archIndex);

	if (!index.is_open()){
		std::cout << "Error en la creacion del archivo" << std::endl;
		return;
	}

	index << "# Bienvenido al Hub de " << data.nombreIndex << std::endl;
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
			nombres.push_back(arch.path().stem());
	}

	std::sort(nombres.begin(),nombres.end());

	return nombres;
}
