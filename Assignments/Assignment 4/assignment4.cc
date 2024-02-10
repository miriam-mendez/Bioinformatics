/*
 * To compile this C++ program type:
 *
 *      g++ -o 4 assignment4.cc
 *
 * To run the program, type:
 *
 *      ./4 file_name1.pdb file_name2.pdb > file_name2_file_name1.txt
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct Atom {
    string type;
    int serial_number;
    string name;
    string residue_type;
    char chain_id;
    int residue_sequence_number;
    double x;
    double y;
    double z;
};

vector<Atom> read_pdb(const string& file_name) {
    vector<Atom> atoms;
    string line;
    ifstream file(file_name);
    while (getline(file, line)) {
        if (line.compare(0, 4, "ATOM") == 0 || line.compare(0, 6, "HETATM") == 0) {
            Atom atom_data;
            atom_data.type = line.substr(0, 5);
            atom_data.serial_number = stoi(line.substr(6, 5));
            atom_data.name = line.substr(12, 4);
            atom_data.residue_type = line.substr(17, 3);
            atom_data.chain_id = line[21];
            atom_data.residue_sequence_number = stoi(line.substr(22, 4));
            atom_data.x = stod(line.substr(30, 8));
            atom_data.y = stod(line.substr(38, 8));
            atom_data.z = stod(line.substr(46, 8));

            atoms.push_back(atom_data);
        }
    }
    return atoms;
}


double atom_distance(const Atom& atom1, const Atom& atom2) {
    return sqrt(pow(atom1.x - atom2.x, 2) + 
                    pow(atom1.y - atom2.y, 2) +
                    pow(atom1.z - atom2.z, 2));
}


pair<int,int> clashing_atoms(const vector<Atom>& atoms1, const vector<Atom>& atoms2) {
    int comparisons = 0;
    int clashes = 0;

    for (const auto& atom1 : atoms1) {
        for (const auto& atom2 : atoms2) {
            ++comparisons;
            double distance = atom_distance(atom1, atom2);
            if (distance < 4.0) {
                ++clashes;
                cout << atom1.serial_number << " " << atom1.residue_type << " "  << atom1.residue_sequence_number << "  " << atom1.name << endl;
                break;
            }
        }
    }
    return {clashes, comparisons};
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " file1.pdb file2.pdb > file2_file1.txt" << endl;
        return 1;
    }

    string file_name1 = argv[1];
    string file_name2 = argv[2];

    vector<Atom> atoms1 = read_pdb(file_name1);
    vector<Atom> atoms2 = read_pdb(file_name2);

    pair<int,int> out = clashing_atoms(atoms1, atoms2);

    cout << "Number of clashing atoms: " << out.first << endl;
    cout << "Number of comparisons: " << out.second << endl;

}