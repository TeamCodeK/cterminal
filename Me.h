#include <iostream>
#include <vector>
#include <fstream>


namespace Me {
    // Xoa cac phan tu trong chuoi
    bool remove(std::string &input, std::string str) {
  	for (int i=0; i != input.length(); i++) {
	    if (input[i] == str[0]) {
        	int n = i;
                int k = i;
                for (int j=1; j != str.length(); j++) {
                    n++;
                    if (input[n] != str[j]) {
                        break;
                    }
		    if (j == str.length()-1) {
        	        input.erase(k, str.length());
			return true;
                    }
                }
            }
        }
	return false;
    }; 
    // Tim kiem phan tu trong chuoi 
    bool search(std::string &input, std::string str) {
  	for (int i=0; i != input.length(); i++) {
	    if (input[i] == str[0]) {
        	int n = i;
                int k = i;
                for (int j=1; j != str.length(); j++) {
                    n++;
                    if (input[n] != str[j]) {
                        break;
                    }
		    if (j == str.length() -1) {
        	        return true;
                    }
                }
            }
        }
	return false;
    };         
    
    // Tach chuoi 
    std::vector<std::string> split(std::string input, std::string str) {
    	std::vector<std::string> o;
	std::string s;
	input.push_back(str[0]);
	for (int i=0; i != input.length(); i++) {
	    if (input[i] == str[0]) {
	    	o.push_back(s);
		s = "";
	    } else {
	        s.push_back(input[i]);
	    }
	}
	return o;
    };

    // Doc file 
    std::string readFile(std::string file_name) {
        std::ifstream read(file_name, std::ios::in);
        if (read) {
            read.seekg(0, std::ios::end);
            int length = read.tellg();
            read.seekg(0, std::ios::beg);
            char * buf = new char[length];
            read.read(buf, length);
            std::string rtValue = buf;
            delete buf;
            return rtValue;
        }
        return NULL;
    }

    // Ghi file
    bool writeFile(std::string file_name, std::string buf) {
        std::ofstream write(file_name, std::ios::out);
        if (write) {
            write << buf << std::endl;
            return true;
        }
        return false;
    }

    bool existFile(std::string file_name) {
        std::ifstream i(file_name);
        return i.good();
    }
}

