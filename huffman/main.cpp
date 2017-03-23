#include <iostream>
#include <string>
#include "huffman.h"
using namespace std;

bool iCompare(string const &a, string const &b){
	if (a.length() == b.length()) {
		unsigned int i = 0;
		for (; (i < a.length()) && (tolower(a[i]) == tolower(b[i])); i++){}
		if (i == a.length()){
			return true;
		}
	}
	return false;
}

string getExtension(string input, char delim){
	if (input.find(delim) != string::npos) {
		return input.erase(0, input.find_last_of(delim) + 1);
	}
	else {
		return "";
	}
}

//void huffman::printTree(Node* node, unsigned int indent = 0){
//	if (node){
//		if (node->right){
//			printTree(node->right, indent + 3);
//		}
//
//		for (unsigned int i = 0; i < indent; i++){
//			std::cout << " ";
//		}
//
//		std::cout << node->number;
//		if (isPeak(node)){
//			std::cout << "(" << node->data << ")";
//		}
//		std::cout << std::endl;
//
//		if (node->left){
//			printTree(node->left, indent + 3);
//		}
//	}
//}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	huffman archiver;

	if (argc > 1){
		for (int i = 1; i < argc; i++){
			archiver.setFilename(argv[i]);

			cout << ">> ";
			if (argc > 2){
				cout << "(" << i << "/" << argc - 1 << ") ";
			}
			if (iCompare(getExtension(argv[i], '.'), COMPRESSED_EXTENSION)){
				cout << "Extracting ";
			} else {
				cout << "Archiving ";
			}
			cout << "\"" << getExtension(argv[i], '\\') << "\" ........ ";

			try {
				if (archiver.toggle()){
					cout << "done." << endl;
				}
			} catch (huffman::exception e){
				e.showMessage();
			}
		}
	}

	system("pause");
	return 0;
}