#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
using json = nlohmann::json;

void writej(json &data) {
	std::ofstream o("pretty.json");
	o << std::setw(4) << data << std::endl;
}

json readj(std::string file) {
    std::ifstream f(file);
    json data = json::parse(f);
	return data;
}
int main() {

	// write
	json data;
#define TEST_JWRITE
	data["cam1"]["current_frame"] = 10;
	data["cam1"]["row"] = 4;
	data["cam1"]["col"] = 4;
	for(int i = 0; i < 6; i++)
		data["cam1"]["angles"].push_back(i/12.8);

	writej(data);
#else
	data = readj("pretty.json");
#endif
	for (auto& [key, value] : data["cam1"].items()) {
	  std::cout << key << " : " << value << "\n";
	  break;
	}


	return 0;
}
