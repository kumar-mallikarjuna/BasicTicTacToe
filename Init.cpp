/*
 * Author: Kumar Mallikarjuna
 * Completion Date: 27/03/2014
 * */

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

#include "time.h"

using namespace std;

string cells[] = {" "," "," "," "," "," "," "," "," "};
string sets[8];

int main(){

	/*
	 	 +-----------+
	 	 | 1 | 2 | 3 |
	 	 +-----------+
	 	 | 4 | 5 | 6 |
	 	 +-----------+
	 	 | 7 | 8 | 9 |
	 	 +-----------+
	 */

	//User = x,Computer = o

	cout << "User - x\nComputer - o" << endl << endl;

	srand(time(NULL));
	while(1){
		int user = -1;

		while(1){
			cout << "User: ";
			cin >> user;

			if(user > 0 && user < 10){
				if(cells[user-1] == " "){
					break;
				}
			}else
				continue;
		}

		cells[user-1] = "x";

		sets[0] = cells[0]+cells[1]+cells[2]; //1,2,3
		sets[1] = cells[3]+cells[4]+cells[5]; //4,5,6
		sets[2] = cells[6]+cells[7]+cells[8]; //7,8,9
		sets[3] = cells[0]+cells[3]+cells[6]; //1,4,7
		sets[4] = cells[1]+cells[4]+cells[7]; //2,5,8
		sets[5] = cells[2]+cells[5]+cells[8]; //3,6,9
		sets[6] = cells[0]+cells[4]+cells[8]; //1,5,9
		sets[7] = cells[2]+cells[4]+cells[6]; //3,5,7

		vector<int> _sets[8];

		_sets[0].push_back(0);
		_sets[0].push_back(1);
		_sets[0].push_back(2);

		_sets[1].push_back(3);
		_sets[1].push_back(4);
		_sets[1].push_back(5);

		_sets[2].push_back(6);
		_sets[2].push_back(7);
		_sets[2].push_back(8);

		_sets[3].push_back(0);
		_sets[3].push_back(3);
		_sets[3].push_back(6);

		_sets[4].push_back(1);
		_sets[4].push_back(4);
		_sets[4].push_back(7);

		_sets[5].push_back(2);
		_sets[5].push_back(5);
		_sets[5].push_back(8);

		_sets[6].push_back(0);
		_sets[6].push_back(4);
		_sets[6].push_back(8);

		_sets[7].push_back(2);
		_sets[7].push_back(4);
		_sets[7].push_back(6);

		int sets_o[] = {0,0,0,0,0,0,0,0};
		int sets_x[] = {0,0,0,0,0,0,0,0};

		int max_o = -1;
		int max_x = -1;

		for(unsigned int i=0;i<8;i++){
			if(sets[i].find('x') == string::npos && sets[i].find('o') != string::npos){
				sets_o[i] = count(sets[i].begin(),sets[i].end(),'o');
			}
			if(sets[i].find('x') != string::npos && sets[i].find('o') == string::npos){
				sets_x[i] = count(sets[i].begin(),sets[i].end(),'x');
			}
		}

		for(unsigned int i=0;i<sizeof(sets_o)/sizeof(sets_o[0]);i++){
			if(sets_o[i] > max_o)
				max_o = sets_o[i];
		}

		for(unsigned int i=0;i<sizeof(sets_x)/sizeof(sets_x[0]);i++){
			if(sets_x[i] > max_x)
				max_x = sets_x[i];
		}

		if(max_o == 3){
			cout << "Winner - Computer" << endl;
			cout << "+-----------+\n| " << cells[0] << " | " << cells[1] << " | " << cells[2] << " |\n+-----------+\n| " << cells[3] << " | " << cells[4] << " | " << cells[5] << " |\n+-----------+\n| " << cells[6] << " | " << cells[7] << " | " << cells[8] << " |\n+-----------+\n";
			exit(0);
		}
		if(max_x == 3){
			cout << "Winner - User" << endl;
			cout << "+-----------+\n| " << cells[0] << " | " << cells[1] << " | " << cells[2] << " |\n+-----------+\n| " << cells[3] << " | " << cells[4] << " | " << cells[5] << " |\n+-----------+\n| " << cells[6] << " | " << cells[7] << " | " << cells[8] << " |\n+-----------+\n";
			exit(0);
		}

		int count_filled = 0,count_tie = 0;
		for(unsigned int i=0;i<sizeof(cells)/sizeof(cells[0]);i++)
			if(cells[i] != " ")
				count_filled++;
		for(unsigned int i=0;i<8;i++)
			if(sets[i].find('x') != string::npos && sets[i].find('o') != string::npos)
				count_tie++;
		if(count_filled == 9 || count_tie == 8){
			cout << "Tie" << endl;
			cout << "+-----------+\n| " << cells[0] << " | " << cells[1] << " | " << cells[2] << " |\n+-----------+\n| " << cells[3] << " | " << cells[4] << " | " << cells[5] << " |\n+-----------+\n| " << cells[6] << " | " << cells[7] << " | " << cells[8] << " |\n+-----------+\n";
			exit(0);
		}

		if(cells[4] == " "){
			cells[4] = "o";
		}else{
			if(max_o < max_x){
				for(unsigned int i=0;i<sizeof(sets_x)/sizeof(sets_x[0]);i++){
					if(sets_x[i] == max_x){
						if(cells[_sets[i].at(0)] == " "){
							cells[_sets[i].at(0)] = "o";
							break;
						}
						if(cells[_sets[i].at(1)] == " "){
							cells[_sets[i].at(1)] = "o";
							break;
						}
						if(cells[_sets[i].at(2)] == " "){
							cells[_sets[i].at(2)] = "o";
							break;
						}
					}
				}
			}else{
				cout << max_x << " " << max_o << endl;

				if(max_o != 2){
					if(max_x != 2){
						vector<int> cells_vector[2];
						for(unsigned int i=0;i<sizeof(sets_o)/sizeof(sets_o[0]);i++){
							if(sets_o[i] != 0){
								for(unsigned int j=0;j<_sets[i].size();j++){
									cells_vector[0].push_back(_sets[i].at(j));
								}
							}
						}
						for(unsigned int i=0;i<sizeof(sets_x)/sizeof(sets_x[0]);i++){
							if(sets_x[i] != 0){
								for(unsigned int j=0;j<_sets[i].size();j++){
									cells_vector[1].push_back(_sets[i].at(j));
								}
							}
						}

						bool done = false;

						for(unsigned int i=0;i<cells_vector[0].size();i++){
							if(find(cells_vector[1].begin(),cells_vector[1].end(),cells_vector[0].at(i)) != cells_vector[1].end()){
								if(cells[cells_vector[0].at(i)] == " "){
									cells[cells_vector[0].at(i)] = "o";
									done = true;
									break;
								}
							}
						}

						if(done == false){
							for(unsigned int i=0;i<sizeof(sets_o)/sizeof(sets_o[0]);i++){
								if(sets_o[i]  == max_o){
									bool brk = false;
									for(unsigned int j=0;j<_sets[i].size();j++){
										if(cells[_sets[i].at(0)] == " "){
											cout << "lel" << endl;
											cells[_sets[i].at(0)] = "o";
											brk = true;
											break;
										}
										if(cells[_sets[i].at(1)] == " "){
											cout << "lel" << endl;
											cells[_sets[i].at(1)] = "o";
											brk = true;
											break;
										}
										if(cells[_sets[i].at(2)] == " "){
											cout << "lel" << endl;
											cells[_sets[i].at(2)] = "o";
											brk = true;
											break;
										}
									}

									if(brk)
										break;
								}
							}
						}
					}else{
						for(unsigned int i=0;i<sizeof(sets_x)/sizeof(sets_x[0]);i++){
							if(sets_x[i] == max_x){
								if(cells[_sets[i].at(0)] == " "){
									cells[_sets[i].at(0)] = "o";
									break;
								}
								if(cells[_sets[i].at(1)] == " "){
									cells[_sets[i].at(1)] = "o";
									break;
								}
								if(cells[_sets[i].at(2)] == " "){
									cells[_sets[i].at(2)] = "o";
									break;
								}
							}
						}
					}
				}else{
					for(unsigned int i=0;i<sizeof(sets_o)/sizeof(sets_o[0]);i++){
						if(sets_o[i] == max_o){
							if(cells[_sets[i].at(0)] == " "){
								cells[_sets[i].at(0)] = "o";
								break;
							}
							if(cells[_sets[i].at(1)] == " "){
								cells[_sets[i].at(1)] = "o";
								break;
							}
							if(cells[_sets[i].at(2)] == " "){
								cells[_sets[i].at(2)] = "o";
								break;
							}
						}
					}
				}
			}
		}

		sets[0] = cells[0]+cells[1]+cells[2]; //1,2,3
		sets[1] = cells[3]+cells[4]+cells[5]; //4,5,6
		sets[2] = cells[6]+cells[7]+cells[8]; //7,8,9
		sets[3] = cells[0]+cells[3]+cells[6]; //1,4,7
		sets[4] = cells[1]+cells[4]+cells[7]; //2,5,8
		sets[5] = cells[2]+cells[5]+cells[8]; //3,6,9
		sets[6] = cells[0]+cells[4]+cells[8]; //1,5,9
		sets[7] = cells[2]+cells[4]+cells[6]; //3,5,7

		for(unsigned int i=0;i<8;i++){
			if(sets[i].find('x') == string::npos && sets[i].find('o') != string::npos){
				sets_o[i] = count(sets[i].begin(),sets[i].end(),'o');
			}
			if(sets[i].find('x') != string::npos && sets[i].find('o') == string::npos){
				sets_x[i] = count(sets[i].begin(),sets[i].end(),'x');
			}
		}

		for(unsigned int i=0;i<sizeof(sets_o)/sizeof(sets_o[0]);i++){
			if(sets_o[i] > max_o)
				max_o = sets_o[i];
		}

		for(unsigned int i=0;i<sizeof(sets_x)/sizeof(sets_x[0]);i++){
			if(sets_x[i] > max_x)
				max_x = sets_x[i];
		}

		count_filled = 0;
		count_tie = 0;
		for(unsigned int i=0;i<sizeof(cells)/sizeof(cells[0]);i++)
			if(cells[i] != " ")
				count_filled++;
		for(unsigned int i=0;i<8;i++)
			if(sets[i].find('x') != string::npos && sets[i].find('o') != string::npos)
				count_tie++;
		if(count_filled == 9 || count_tie == 8){
			cout << "Tie" << endl;
			cout << "+-----------+\n| " << cells[0] << " | " << cells[1] << " | " << cells[2] << " |\n+-----------+\n| " << cells[3] << " | " << cells[4] << " | " << cells[5] << " |\n+-----------+\n| " << cells[6] << " | " << cells[7] << " | " << cells[8] << " |\n+-----------+\n";
			exit(0);
		}

		if(max_o == 3){
			cout << "Winner - Computer" << endl;
			cout << "+-----------+\n| " << cells[0] << " | " << cells[1] << " | " << cells[2] << " |\n+-----------+\n| " << cells[3] << " | " << cells[4] << " | " << cells[5] << " |\n+-----------+\n| " << cells[6] << " | " << cells[7] << " | " << cells[8] << " |\n+-----------+\n";
			exit(0);
		}
		if(max_x == 3){
			cout << "Winner - User" << endl;
			cout << "+-----------+\n| " << cells[0] << " | " << cells[1] << " | " << cells[2] << " |\n+-----------+\n| " << cells[3] << " | " << cells[4] << " | " << cells[5] << " |\n+-----------+\n| " << cells[6] << " | " << cells[7] << " | " << cells[8] << " |\n+-----------+\n";
			exit(0);
		}

		cout << "+-----------+\n| " << cells[0] << " | " << cells[1] << " | " << cells[2] << " |\n+-----------+\n| " << cells[3] << " | " << cells[4] << " | " << cells[5] << " |\n+-----------+\n| " << cells[6] << " | " << cells[7] << " | " << cells[8] << " |\n+-----------+\n";
	}

	return 0;
}
