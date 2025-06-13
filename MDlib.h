#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include "StrIndex.h"

namespace fs = std::filesystem;

void MDlinker(std::string sruta);
void imprimirLista(std::vector<std::string>);
std::vector<std::string> capturaNombres(fs::path);
void creaIndex(StrIndex data);
fs::path defineRuta(std::string);
void inicializar(StrIndex& data, std::string sruta);
