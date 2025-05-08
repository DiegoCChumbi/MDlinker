#include <filesystem>
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>

namespace fs = std::filesystem;

void creaLinker(std::string);
void imprimirLista(std::vector<std::string>);
std::vector<std::string> capturaNombres(fs::path);
bool validaRuta(fs::path);
void creaIndex(fs::path,std::vector<std::string>);
fs::path defineRuta(std::string);
