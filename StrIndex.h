#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

typedef struct StrIndex{
	std::string sruta;
	fs::path ruta;
	std::string nombreIndex;
	fs::path archIndex;
} StrIndex; 

