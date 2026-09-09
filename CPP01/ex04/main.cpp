#include <iostream>
#include <string>
#include <fstream>

static void	searchAndReplace(std::ifstream& inFile, std::ofstream& outFile, const std::string& s1, const std::string& s2)
{
	std::string		line;
	std::size_t		pos;

	while (std::getline(inFile, line)) {
		pos = line.find(s1);
		while (pos != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
		}
		outFile << line;
		// getline ate the delimiter: eof() here means the line ended at EOF instead.
		if (!inFile.eof())
			outFile << "\n";
	}
}

int	main(int ac, char **av)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		fileName;

	if (ac != 4) {
		std::cerr << "Error: bad number of arguments" << std::endl;
		return (1);
	}

	// Before opening anything: opening the output would truncate it.
	if (std::string(av[2]).empty()) {
		std::cerr << "Error: string empty" << std::endl;
		return (1);
	}

	fileName = av[1];
	inFile.open(fileName.c_str());
	if (!inFile.is_open()) {
		std::cerr << "Error: cannot open " << fileName << std::endl;
		return (1);
	}
	outFile.open((fileName + ".replace").c_str());
	if (!outFile.is_open()) {
		std::cerr << "Error: cannot open " << fileName << ".replace" << std::endl;
		return (1);
	}

	searchAndReplace(inFile, outFile, av[2], av[3]);

	inFile.close();
	outFile.close();
	return (0);
}
